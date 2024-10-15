#include "engine/ui/DrawArea.h"

namespace engine {

    DrawArea::DrawArea() : m_x(0), m_y(0), m_width(0), m_height(0) {}

    DrawArea::DrawArea(int x, int y, int width, int height) : m_x(x), m_y(y), m_width(width), m_height(height) {}

    DrawArea::DrawArea(const DrawArea& drawArea) : m_x(drawArea.m_x), m_y(drawArea.m_y), m_width(drawArea.m_width), m_height(drawArea.m_height) {}

    DrawArea& DrawArea::addChildren(ScreenPos pos) {
        size_t index = static_cast<size_t>(pos);
        /* TODO: m_childrens.emplace_back, visible[index]=m_childrens.find(drawArea) */
        return DrawArea(); /* TODO: remove, made just to make it compile */
    }

}