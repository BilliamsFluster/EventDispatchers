#pragma once
#include <iostream>
#include "EventDispatcher.h"
class Character
{
EventDispatcher<void>* EventHandler;

void SayHello(){std::cout<<"Hello"<<std::endl;}
};