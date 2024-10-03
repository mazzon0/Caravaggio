#include "engine/platform/Platform.h"
#include <glfw/glfw3.h>

namespace engine {

    namespace Platform {
        void SendEvents() {
            glfwPollEvents();
        }
    }

}
