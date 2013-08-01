#include "statusandcontrol.h"
#include <QtGui>
#include "globalpointers.h"

StatusAndControl::StatusAndControl(QWidget *parent) :
    QWidget(parent)
{
    //create
    QLabel *aliveCellsLabel = new QLabel("Alive Cells:");

    numOfAliveCells=0;

    aliveCells = new QLabel(labelCaption(numOfAliveCells));
    aliveCells->setAlignment(Qt::AlignHCenter);


    playButton = new QPushButton();
    playButton->setText(QApplication::tr("&Next"));

    play5Button = new QPushButton();
    play5Button->setText(QApplication::tr("&Next 5"));

    QVBoxLayout *rightLayout = new QVBoxLayout(this);
    rightLayout->addSpacing(10);
    rightLayout->addWidget(aliveCellsLabel);
    rightLayout->addWidget(aliveCells);

    rightLayout->addStretch();
    rightLayout->addWidget(playButton);
    rightLayout->addWidget(play5Button);
    rightLayout->addSpacing(10);
}

void StatusAndControl::changeAliveLabel(int alive)
{
    numOfAliveCells = alive;
    aliveCells->setText(labelCaption(numOfAliveCells));
}

QString StatusAndControl::labelCaption(int i)
{
    return QString("<H2><font color=red> %1 </font></H2>").arg(i);
}

void StatusAndControl::createConnections(){
    GlobalPointers * global = GlobalPointers::getInstance();
    connect(playButton, SIGNAL(clicked()), global->game ,SLOT(makeStep()) );
    connect(play5Button, SIGNAL(clicked()), this ,SLOT(do5Steps()) );
}

void StatusAndControl::do5Steps(){
    GlobalPointers * global = GlobalPointers::getInstance();
    global->game->makeStep();
    global->game->makeStep();
    global->game->makeStep();
    global->game->makeStep();
    global->game->makeStep();
}
