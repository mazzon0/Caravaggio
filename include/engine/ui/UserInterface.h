#ifndef CRVG_UI
#define CRVG_UI

#include <unordered_map>
#include "DrawArea.h"
#include "UIContent.h"
#include "Window.h"

namespace engine {

    /* TODO: find a way to unify Window and UserInterface (they have a 1 to 1 correlation) */
    class UserInterface {
    public:
        UserInterface();
        ~UserInterface() = default;
        UserInterface(const UserInterface&) = delete;
        UserInterface& operator = (const UserInterface&) = delete;

        void setWindow(Window* window);
        DrawArea& setCurrentState(int state);

    private:
        std::unordered_map<int, DrawArea> states;
        Window* m_pWindow;
        int m_currentState;
    };

}

#endif
