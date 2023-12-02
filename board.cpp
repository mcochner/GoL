#include <QtGui>
#include <QGridLayout>

#include "board.h"
#include "square.h"
#include "defaultsettings.h"

Board::Board(QWidget *parent) :
    QWidget(parent), nHSqueres(DEFAULT_NUMBER_OF_HSQUARES), nVSqueres(DEFAULT_NUMBER_OF_WSQUARES),
    nAliveCells(0)
{

    readSettings();

    int width = nHSqueres;
    int height = nVSqueres;

    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
        {
            squaresVec.append(new Square(this,i,j));
        }

    QGridLayout *gridLayout = new QGridLayout(this);

    int k=0;
    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
        {
            gridLayout->addWidget(squaresVec[k++],i,j);
        }

    gridLayout->setSpacing(0); // aby som vynuloval miesto medzi stvorcekmi
    this->setFixedSize(this->sizeHint().width() , this->sizeHint().height());

    createConnections();
}
void Board::readSettings(){

    QSettings settings("config.ini", QSettings::IniFormat);

    nHSqueres = settings.value("HSquares", DEFAULT_NUMBER_OF_HSQUARES).toInt();
    nVSqueres = settings.value("WSquares", DEFAULT_NUMBER_OF_WSQUARES).toInt();

    //settings.value("HCells", DEFAULT_NUMBER_OF_HSQUARES);
    //settings.value("WCells", DEFAULT_NUMBER_OF_WSQUARES);
}

Board::~Board(){
    int width = nHSqueres;
    int height = nVSqueres;

    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
        {
            squaresVec.pop_back();
        }
}

// kazdy stvorec prepojim so spracovatelskym slotom na boarde
void Board::createConnections(){

    connect(this, SIGNAL(squaresChangedfromGame()), this , SLOT(setAllSquares()) );


    for (int i=0; i<squaresVec.size(); ++i)
    {   Square *s = squaresVec[i];
        connect(s, SIGNAL(squareChanged(int,int, bool)), this ,SLOT(setLabelAboutSquares()) );
        connect(s, SIGNAL(squareChanged(int,int, bool)), this ,SIGNAL(cellChanged(int,int, bool)) );
    }
}

void Board::setNumOfAliveSquares(){
    nAliveCells=0;
    for (int i=0; i<squaresVec.size(); ++i)
    {
        Square *s = squaresVec[i];
        if (s->isAlive())
            nAliveCells++;

    }
}

void Board::setLabelAboutSquares()
{
    setNumOfAliveSquares();
    // qDebug("setLabelAboutSquares");
    // qDebug() << nAliveCells;
    emit labelChanged(nAliveCells);
}

void Board::setAllSquares()
{
    //qDebug()<< "SLOT:setAllSquares";
    for (int i=0; i<squaresVec.size(); ++i)
    {
        squaresVec[i]->checkStateFromGame();
    }
}




