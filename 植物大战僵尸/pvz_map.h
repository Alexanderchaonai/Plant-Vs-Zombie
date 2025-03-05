#pragma once
#include"pvz_character.h"

class pvz_map
{
protected:
    unsigned short w,h;
public:
    //声明 纯虚  主循环（阳光）空
    virtual void main_cycle(unsigned short& sun)=0;

};