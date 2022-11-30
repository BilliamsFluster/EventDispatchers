#ifndef LISTENER
#define LISTENER
#include "Event.h"

class Listener
{
public:
Listener(){};
virtual ~Listener() = default;
virtual void HandleEvent(Event* event) = 0;
};
#endif