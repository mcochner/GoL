#include "globalpointers.h"



bool GlobalPointers::instanceFlag = false;
GlobalPointers* GlobalPointers::single = NULL;

GlobalPointers* GlobalPointers::getInstance()
{
    if(! instanceFlag)
    {
        single = new GlobalPointers();
        instanceFlag = true;
        return single;
    }
    else
    {
        return single;
    }
}
