#ifndef EVENT
#define EVENT
#include <string>
using std::string;
#define EVENTID string

class Event
{
private:
EVENTID EventID;
void* Parameter;
public:
Event(EVENTID EventID,void* Parameter = 0)
{
	this->EventID = EventID;
	this->Parameter = Parameter;
}
~Event();

inline EVENTID GetEventID() const {return EventID;}

inline void* GetParameter() {return Parameter;}
};

#endif