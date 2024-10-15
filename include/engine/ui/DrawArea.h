#ifndef CRVG_DRAWAREA
#define CRVG_DRAWAREA
#include "UIContent.h"
#include "UIData.h"
#include <vector>
#include <string>

namespace engine {

    class DrawArea {
    public:
        DrawArea();
        DrawArea(int x, int y, int width, int height);
        DrawArea(const DrawArea& drawArea);

        DrawArea& addChildren(ScreenPos pos);

        template<typename T>
        void add(T& widget);    /* TODO: accept a list of widgets */

    private:
        UIContent m_content;
        std::vector<DrawArea> m_childrens;  /* TODO: add ScreenPos somehow */
        std::string m_name;
        int m_x, m_y, m_width, m_height;
        uint8_t m_visible[5];
    };

    template<typename T>
    void DrawArea::add(T& widget) {
        static_assert(std::is_base_of<Widget, T>::value, "ERROR: T must derive from Widget (DrawArea::add)");
        
        WidgetID id = UIData::add(widget);
        m_content.addContent(id);
    }

}

#endif
