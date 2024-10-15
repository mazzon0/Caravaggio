#ifndef CRVG_WIDGET
#define CRVG_WIDGET

#include <vector>

namespace engine {

    enum class ScreenPos {
        TOP = 0,
        BOTTOM,
        LEFT,
        RIGHT,
        CENTER
    };

    using WidgetID = uint32_t;

    class Widget {
    protected:
        float m_padding[4];
        std::vector<WidgetID> children;
    };

    /*
    widgets are:
     - texts
     - images
     - icons
     - buttons
     - sliders
     - text fields
     - tables
     - color pickers
     ...
    */

   /*
   to add a new widget A you have to:
    1. extend the class Widget
    2. in UIData add WidgetManager<A> to the managers tuple
   */

}

#endif
