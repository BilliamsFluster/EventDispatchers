#ifndef EVENTDISPATCHER
#define EVENTDISPATCHER

#include <list>
#include <map>
using std::multimap;
using std::list;
using std::pair;


#include "Event.h"
#include "Listener.h"
class EventDispatcher// singleton
{
private:
multimap<EVENTID,Listener*> Database;

/* Event Helpers */
bool AlreadyRegistered(EVENTID EventID,Listener* Client);

void DispatchEvent(Event* Event);




list<Event> CurrentEvents;
	EventDispatcher();
~EventDispatcher(){Shutdown();};
EventDispatcher(const EventDispatcher& rhs);
EventDispatcher& operator=(const EventDispatcher& rhs);
public:
static EventDispatcher* Instance;
static EventDispatcher* Get()
	{
		if (Instance == NULL)
		{
			Instance = new EventDispatcher();
		}
		return Instance;
	}
void RegisterClient(EVENTID Event, Listener* Client);

void UnregisterClient(EVENTID Event, Listener* Client);
void UnregisterAll(Listener* Client);
void SendEvent(EVENTID EventID,void* Data = 0);
void ProcessEvents();
void ClearEvents();
void Shutdown();

};

#endif