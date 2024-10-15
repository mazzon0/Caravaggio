#include "engine/ui/widgets/Image.h"

namespace engine {

    Image::Image():m_width(0), m_height(0), m_borderRadius(0) {}

    Image::Image(float w, float h, float r):m_width(w), m_height(h), m_borderRadius(r) {}
    
}