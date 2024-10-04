#ifndef CRVG_EVENTSYSTEM
#define CRVG_EVENTSYSTEM

#include "Events.h"
#include <memory>

namespace engine {

    class EventSystem {
    private:
        std::vector<std::unique_ptr<Event>> events;
        static const size_t STD_CAPACITY = 50;
    public:
        EventSystem();
        ~EventSystem() = default;

        void addEvent(std::unique_ptr<Event> e);
        void reset();
    };

}

#endif
