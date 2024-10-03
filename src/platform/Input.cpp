#include "engine/platform/Input.h"
#include <glfw/glfw3.h>

namespace engine {

    namespace Input {
        bool isKeyDown(const Window& window, int key) {
            return glfwGetKey(window.m_pWindow, key) == GLFW_PRESS;
        }

        void getCursorPos(const Window& window, double* x, double* y) {
            glfwGetCursorPos(window.m_pWindow, x, y);
        }

    }

}
