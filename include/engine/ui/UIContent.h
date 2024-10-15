#ifndef CRVG_UICONTENT
#define CRVG_UICONTENT

#include "engine/ui/widgets/Widget.h"

namespace engine {

    class UIContent {
    public:
        UIContent() {}
        ~UIContent() = default;

        void addContent(WidgetID id);
    private:
        std::vector<WidgetID> m_widgets;    /* TODO: store also the type of widgets? */
    };

}

#endif
