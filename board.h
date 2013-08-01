#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include "square.h"

class Board : public QWidget
{
    Q_OBJECT

private:
    int nHSqueres;
    int nVSqueres;
    int nAliveCells;
    QVector<Square*> squaresVec;
    void createConnections();
    void setNumOfAliveSquares();
    void readSettings();
public:
    explicit Board(QWidget *parent = 0);
    ~Board();
signals:
    void labelChanged(int);
    void cellChanged(int, int, bool);
    void squaresChangedfromGame();

public slots:
    void setLabelAboutSquares();
    void setAllSquares();
    
};

#endif // BOARD_H
