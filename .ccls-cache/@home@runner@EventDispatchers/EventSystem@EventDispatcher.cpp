#include "EventDispatcher.h"

bool EventDispatcher::AlreadyRegistered(EVENTID EventID,Listener* Client)
{
bool AlreadyRegistered = false;
	pair<multimap<EVENTID,Listener*>::iterator, multimap<EVENTID,Listener*>::iterator> Range;
	// Find all of the clients to recieve this event
	Range = Database.equal_range(EventID);
	//Go through the list of clients
	for(multimap<EVENTID,Listener*>::iterator it = Range.first; it != Range.second; it++)
		{
			if((*it).second == Client)
			{
				AlreadyRegistered = true;
				break;
			}
			
		}
	return AlreadyRegistered;
}

void EventDispatcher::DispatchEvent(Event* Event)
{
 pair<multimap<EVENTID,Listener*>::iterator, multimap<EVENTID,Listener*>::iterator> Range;
	// Find all of the clients to recieve this event
	Range = Database.equal_range(Event->  EventID); 
	for(multimap<EVENTID,Listener*>::iterator it = Range.first; it != Range.second; it++)
		{
			(*it).second->HandleEvent(Event);
		}
	
}


void EventDispatcher::RegisterClient(EVENTID Event, Listener* Client)
{
	if(!Client || AlreadyRegistered(Event,Client))
	{
		return;
	}
	Database.insert(make_pair(Event,Client));
}

void EventDispatcher::UnregisterClient(EVENTID Event, Listener* Client)
{
	pair<multimap<EVENTID,Listener*>::iterator, multimap<EVENTID,Listener*>::iterator> Range;
	Range = Database.equal_range(Event);
	for(multimap<EVENTID,Listener*>::iterator it = Range.first; it != Range.second; it++)
		{
			if((*it).second == Client)
			{
				it = Database.erase(it);
				break;
			}
		}
}
void EventDispatcher::UnregisterAll(Listener* Client)
{
	multimap<EVENTID,Listener*>::iterator  it = Database.begin();
	while(it != Database.end())
		{
			if((*it).second == Client)
			{
				it = Database.erase(it);
			}
			else{
				it++;
			}

		}
		
}
void EventDispatcher::SendEvent(EVENTID EventID,void* Data)
{
	Event NewEvent{EventID,Data};
	CurrentEvents.push_back(NewEvent);
}
void EventDispatcher::ProcessEvents()
{
	while(CurrentEvents.size())
		{
			DispatchEvent((&CurrentEvents.front()));
			CurrentEvents.pop_front();
		}
}
void EventDispatcher::ClearEvents()
{
	CurrentEvents.clear();
}
void EventDispatcher::Shutdown()
{
	Database.clear();
	CurrentEvents.clear();
}

EventDispatcher* EventDispatcher::Instance = NULL;