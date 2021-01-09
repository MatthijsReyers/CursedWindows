
#include <vector>
#include <mutex>

#include "event.hpp"

namespace cw
{
    class eventqueue
    {
    public:
        eventqueue();

        void push(event e) noexcept;
        bool try_push(event e) noexcept;

        event pop() noexcept;
        
    private:
        std::mutex events_mutex;
        std::mutex empty_mutex;
        std::vector<event> events;
    };
}
