#ifndef CRVG_WIDGETMANAGER
#define CRVG_WIDGETMANAGER

#include <unordered_map>
#include "widgets/Widget.h"

namespace engine {

    template<typename T>
    class WidgetManager {
        static_assert(std::is_base_of<Widget, T>::value, "ERROR: T must derive from Widget (WidgetManager)");

    public:
        void add(WidgetID id, T widget) {
            /* TODO: replace with emplace_back and forwarding */
            widgets[id]=widget;
        }
        
        void remove(WidgetID id) {
            widgets.erase(id);
        }

        T& get(WidgetID id) const {
            return widgets[id];
        }

    private:
        /* TODO: replace map with a contunuous tree for performance ? */
        std::unordered_map<WidgetID, T> widgets;

    };

}

#endif
