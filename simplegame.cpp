#include "simplegame.h"
#include <QtGui>

using namespace std;


int SimpleGame::ijTolinear(int i, int j){
    return i*height + j;
}

SimpleGame::SimpleGame(QObject *parent) :
    QObject(parent), height(NUMBER_OF_HCELLS), width(NUMBER_OF_WCELLS), spravnePole('s')
{
    readSettings();
    initVectors();
    //Vypis();

}

void SimpleGame::readSettings(){

    QSettings settings("config.ini", QSettings::IniFormat);

    height = settings.value("HSquares", DEFAULT_NUMBER_OF_HSQUARES).toInt();
    width = settings.value("WSquares", DEFAULT_NUMBER_OF_WSQUARES).toInt();
}


void SimpleGame::initVectors(){
    sCellsVector.clear();
    nCellsVector.clear();

    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
        {
            sCellsVector.push_back(0);
            nCellsVector.push_back(0);
        }
    setCurrentAndNextStepArrays();

}


void SimpleGame::Prehod(){

    if (spravnePole=='s') spravnePole='n'; else spravnePole='s';

    setCurrentAndNextStepArrays();
}


// return how many alive cells are in the neighborhood of the i,j cell

int SimpleGame::returnNumberOfCellsAroundCell(int i, int j){
    int p=0;

    if (isCellAlive(i+1, j  )) p++;
    if (isCellAlive(i+1, j+1)) p++;
    if (isCellAlive(i+1, j-1)) p++;


    if (isCellAlive(i  , j+1)) p++;
    if (isCellAlive(i  , j-1)) p++;

    if (isCellAlive(i-1, j  )) p++;
    if (isCellAlive(i-1, j+1)) p++;
    if (isCellAlive(i-1, j-1)) p++;

    return p;
}

bool SimpleGame::isCellAlive(int i, int j){

    if (!(validCellPosition(i,j))) return false;

    int linear = ijTolinear(i,j);
    if (linear>=(int)currentValidArray->size()){


        //qDebug(QString("currentValidArray is %1.").arg(currentValidArray->size()).toAscii());
        qDebug("problem with isCellAlive() funcion");
    }


    if (currentValidArray->at(linear)==1) return true;
    if (currentValidArray->at(linear)==0) return false;

    qDebug("something is wrong with returnIfCellAlive();");
    return 0;
}

bool SimpleGame::validCellPosition(int i, int j){
    if (( i<0) || (j<0)) return false;
    if ((i>= height) || (j >= width)) return false;
    return true;
}

void SimpleGame::Vypis(){
    for(int i=0; i<height; i++)
    {
        QDebug debug = qDebug();
        for(int j=0; j<width; j++)
        {
            if (  isCellAlive(i,j)) debug << "X " ;
            if (!(isCellAlive(i,j))) debug << "O " ;
        }
        debug << "\n" ;
    }
}

void SimpleGame::Krok(){               //pravidla
    //vynuluj(n);                //neni nutne robim za chodu

    int temp;
    for(int i=0;i<height;i++)
        for(int j=0;j<width;j++)
        {
            temp = returnNumberOfCellsAroundCell(i,j);
            //4 pravidla:

            if (isCellAlive(i, j)){
                // 1. Any live cell with fewer than two live neighbours dies, as if caused by under-population.
                if (temp < 2) { nextStepArray->at(ijTolinear(i,j)) = 0; }

                // 2. Any live cell with two or three live neighbours lives on to the next generation.
                if ((temp == 2) || (temp == 3)) { nextStepArray->at(ijTolinear(i,j)) = 1;}

                // 3. Any live cell with more than three live neighbours dies, as if by overcrowding.
                if ((temp > 3)) { nextStepArray->at(ijTolinear(i,j)) = 0;}
            }
            else {
                // 4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
                if (temp == 3) {nextStepArray->at(ijTolinear(i,j)) = 1; }
                else
                {nextStepArray->at(ijTolinear(i,j)) = 0;}
            }
        }

    Prehod();
    //Vypis();
}

void SimpleGame::makeStep(){
    //qDebug("In da makeStep");
    Krok();
    emit squaresChanged();
}

bool SimpleGame::setTheCellAndReturnIfSuccessful(int i, int j, bool alive){
    if (!(validCellPosition(i,j))) return false;

    int linear = ijTolinear(i,j);
    if (!alive) currentValidArray->at(linear) = 0;
    if (alive) currentValidArray->at(linear) = 1;
    return true;
}

void SimpleGame::setCell(int i, int j, bool alive){
    setTheCellAndReturnIfSuccessful(i,j,alive);
}

void SimpleGame::setCurrentAndNextStepArrays(){
    if (spravnePole=='s'){
        currentValidArray = &sCellsVector;
        nextStepArray = &nCellsVector;
    }
    else{
        currentValidArray = &nCellsVector;
        nextStepArray = &sCellsVector;
    }
}

void SimpleGame::clearGame(){
    initVectors();
    emit squaresChanged();
}
