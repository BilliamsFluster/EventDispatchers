#pragma once
#include <iostream>
#include "EventSystem/Listener.h"
#include "EventSystem/Event.h"
class Character: public Listener
{
public:
std::string Name;
Character(std::string Name)
{
	this->Name = Name;
}

void HandleEvent(Event* Event);

void SayHello(){std::cout<<"Hello"<<std::endl;}
};