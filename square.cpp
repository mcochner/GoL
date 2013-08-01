#include "square.h"
#include "defaultsettings.h"
#include "board.h"
#include <QtGui>


Square::Square(QWidget *parent, int i, int j) :
    QWidget(parent)
{
    this->_i = i;
    this->_j = j;

    alive = false;

    QPalette palette(Square::palette());
    palette.setColor(backgroundRole(), Qt::white);
    setPalette(palette);

    readSettings();

    this->setFixedSize(sizeOfSquare,sizeOfSquare);

}

void Square::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    if (alive==true)
    {
        painter.setBrush(QBrush(getAliveColor())); //zivi
    }
    else{
        painter.setBrush(QBrush(getDeadColor())); //mrtvy
    }

    painter.drawRect(0, 0, sizeOfSquare, sizeOfSquare);
}

void Square::swichAliveness()
{
    if (alive==true){
        alive=false;
    }
    else{
        alive = true;
    }
}


void Square::checkStateFromGame(){
    //qDebug()<<"checkStateFromGame";
    GlobalPointers *global=GlobalPointers::getInstance();
    alive = global->game->isCellAlive(_i,_j);
    emit squareChanged(_i,  _j, alive);
    update();
}

void Square::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton){
        swichAliveness();
        emit squareChanged(_i,  _j, alive);
        update();
    }
}

void Square::readSettings(){
    QSettings settings("config.ini", QSettings::IniFormat);
    sizeOfSquare = settings.value("SizeOfSquare", DEFAULT_SIZE_OF_SQUARE).toInt();
}
