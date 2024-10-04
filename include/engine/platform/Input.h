#ifndef CRVG_INPUT
#define CRVG_INPUT

#include "engine/ui/Window.h"

namespace engine {

    /* TODO: substitute glfw names with custom names */
    namespace Input {
        bool isKeyDown(const Window& window, int key);
        void getCursorPos(const Window& window, double* x, double* y);
        bool isButtonPressed(const Window& window, int button);
        /* TODO: joystick */
    }

}

#endif
