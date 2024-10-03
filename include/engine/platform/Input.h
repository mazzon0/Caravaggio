#ifndef CRVG_INPUT
#define CRVG_INPUT

#include "engine/ui/Window.h"

namespace engine {

    /* TODO: substitute glfw key names with custom names */
    namespace Input {
        bool isKeyDown(const Window& window, int key);
        void getCursorPos(const Window& window, double* x, double* y);
        /* TODO: mouse buttons, joystick */
    }

}

#endif
