#ifndef SQUARE_H
#define SQUARE_H

#include <QWidget>
#include "globalpointers.h"

class Board;

class Square : public QWidget
{
Q_OBJECT

    int sizeOfSquare;
    int _i;
    int _j;
    bool alive;
    Board *b;

public:
    explicit Square(QWidget *parent,  int i, int j);
    void checkStateFromGame();
    bool isAlive(){
        return alive;
    }

signals:
    void squareChanged(int i, int j, bool alive);

public slots:
    void swichAliveness();

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    QColor getAliveColor(){return QColor(255,0,0);}
    QColor getDeadColor(){return QColor(255,255,255);}
private:
    void readSettings();
};

#endif // SQUARE_H
