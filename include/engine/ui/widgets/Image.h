#ifndef CRVG_IMAGE
#define CRVG_IMAGE

#include "Widget.h"

namespace engine {

    class Image final : public Widget {
    public:
        Image();
        Image(float w, float h, float r);

    private:
        float m_width, m_height;
        float m_borderRadius;

    };

}

#endif
