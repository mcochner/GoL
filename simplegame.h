#ifndef SIMPLEGAME_H
#define SIMPLEGAME_H

#include <QObject>
#include <vector>
#include "defaultsettings.h"


const int NUMBER_OF_HCELLS=DEFAULT_NUMBER_OF_HSQUARES; //horizontalny rozmery sietky
const int NUMBER_OF_WCELLS=DEFAULT_NUMBER_OF_WSQUARES; //horizontalny rozmery sietky

double doubleRand( );    //moja random funkcia


class SimpleGame : public QObject
{
    Q_OBJECT

public:
     int height, width;  //  aktualne rozmery sietky, resp N oznacuje kvoli bezpecnosti/jednoduchosti rozmer sietky-1.

     char spravnePole;   //  s ...sVyskyt, n ...nVyskyt
     void Prehod();      //  meni s za n

     void Vypis(); //s - vykresli s pole, n vykresli n pole
     void Krok();
     bool isCellAlive(int i, int j);
     explicit SimpleGame(QObject *parent = 0); //konstrukor

signals:
    void squaresChanged();
public slots:
    void makeStep();
    void setCell(int,int, bool);
    void clearGame();

private:
    void readSettings();
    void initVectors();  // clear it and initialize the vectors;
    bool validCellPosition(int i, int j);
    int ijTolinear(int i, int j);
    void setCurrentAndNextStepArrays();
    int returnNumberOfCellsAroundCell(int x, int y);    // pocet entit okolo v najblizsom okoli bunky

    bool setTheCellAndReturnIfSuccessful(int i, int j, bool alive);

    std::vector<int> sCellsVector;
    std::vector<int> nCellsVector;

    std::vector<int> *currentValidArray;
    std::vector<int> *nextStepArray;

};

#endif // SIMPLEGAME_H








