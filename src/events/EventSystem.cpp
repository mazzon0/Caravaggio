#include "engine/events/EventSystem.h"

namespace engine {

    EventSystem::EventSystem() {
        events.reserve(STD_CAPACITY);
    }

    void EventSystem::addEvent(std::unique_ptr<Event> e) {
        events.push_back(e);
    }

    void EventSystem::reset() {
        events.clear();
    }

}
