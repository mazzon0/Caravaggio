#ifndef CRVG_EVENTSYSTEM
#define CRVG_EVENTSYSTEM

#include "Events.h"
#include <memory>
#include <functional>

namespace engine {

    class EventSystem {
    private:
        std::vector<std::unique_ptr<Event>> events;
        static const size_t STD_CAPACITY = 50;
    public:
        EventSystem();
        ~EventSystem() = default;

        template<typename T, typename... Args>
        void addEvent(Args&&... args);

        void reset();
        void forEach(const std::function<void(Event&)>& action);
    };

    template<typename T, typename... Args>
    void EventSystem::addEvent(Args&&... args) {
        static_assert(std::is_base_of<Event, T>::value, "ERROR: T must derive from Event (EventSystem::addEvent)");
        events.push_back(std::make_unique<T>(std::forward<Args>(args)...));
    }

}

#endif
