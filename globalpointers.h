#ifndef GLOBALPOINTERS_H
#define GLOBALPOINTERS_H

#include <sys/types.h>


#include "statusandcontrol.h"
#include "simplegame.h"
//#include "board.h"

class Board;

class GlobalPointers
{

    GlobalPointers(){}

    static bool instanceFlag;
    static GlobalPointers *single;

public:
    static GlobalPointers* getInstance();
    ~GlobalPointers(){instanceFlag=false;}

    SimpleGame *game;
    Board *board;
    StatusAndControl *sac;
};



#endif // GLOBALPOINTERS_H
