#include "engine/ui/UIContent.h"

namespace engine {

    void UIContent::addContent(WidgetID id) {
        m_widgets.push_back(id);
    }
    
}