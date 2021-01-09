
#include "eventqueue.hpp"

namespace cw
{
    eventqueue::eventqueue()
    {
        // Empty mutex starts out locked since the event queue is by
        // definiton empty upon construction.
        empty_mutex.lock();
    }

    void eventqueue::push(event e)
    {
        events_mutex.lock();
        events.push_back(e);
        
        // The event queue is now definitely not empty so the empty_mutex lock 
        // can be released, double unlock is undefined behaviour so try to lock
        // the mutex first.
        empty_mutex.try_lock();
        empty_mutex.unlock();

        events_mutex.unlock();
    }

    bool eventqueue::try_push(event e)
    {
        if (events_mutex.try_lock())
        {
            events.push_back(e);
            
            // The event queue is now definitely not empty so the empty_mutex
            // lock can be released, double unlock is undefined behaviour so 
            // try to lock the mutex first.
            empty_mutex.try_lock();
            empty_mutex.unlock();

            events_mutex.unlock();
            return true;
        }
        else return false;
    }
    
    event eventqueue::pop()
    {
        events_mutex.lock();
        
        // Ensure queue is not empty before getting the last.
        if (events.empty())
        {
            // Unlock so another thread can add data to queue.
            events_mutex.lock();

            // Block until empty mutex is released.
            empty_mutex.lock();

            // Recurively try again.
            return 
        }

        

        // We

        // Check if empty mutex can be unlocked or not.
        if (!events.empty()) {
            empty_mutex.try_lock();
            empty_mutex.unlock();
        }
    
        // Unlock and return popped event.
        events_mutex.unlock();
        return e;
    }
}