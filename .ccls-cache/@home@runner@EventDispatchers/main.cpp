#pragma once
#include "EventSystem/EventDispatcher.h"
#include <iostream>
#include "Character.h"




int main() {
Character Jeff("Jeff");
Character Billy("Billy");
EventDispatcher::Get()->RegisterClient("G", &Billy);
	EventDispatcher::Get()->RegisterClient("G", &Jeff);
	
	int num;
	std::cin >>num;

	if (num ==1)
	{

		EventDispatcher::Get()->SendEvent("G",0);
		EventDispatcher::Get()->ProcessEvents();
	}
	
}