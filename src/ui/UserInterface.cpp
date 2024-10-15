#include "engine/ui/UserInterface.h"
#include <iostream>

namespace engine {

    UserInterface::UserInterface() : m_currentState(-1), m_pWindow(nullptr) {}

    void UserInterface::setWindow(Window* window) {
        if(window==nullptr) {
            std::cout << "ERROR: window passed is nullptr (UserInterface)" << std::endl;
        }
        
        /* TODO: update if there are data about the old window */
        m_pWindow = window;
    }

    DrawArea& UserInterface::setCurrentState(int state) {
        if(state<0) {
            std::cout << "WARN: invalid UI state, setCurrentState(" << state << ") failed (UserInterface)" << std::endl;
            return DrawArea();  // this returns an invalid pointer, maybe i should add exceptions to the library ? nah too basic
            /* TODO: add exceptions */
        }

        // create state if it doesn't exist
        if(states.find(state) != states.end()) {
            int w, h;
            m_pWindow->getSize(&w, &h);
            states.emplace(std::piecewise_construct, std::forward_as_tuple(state), std::forward_as_tuple(0, 0, w, h));
        }

        // set current state
        m_currentState = state;

        return states[m_currentState];
    }

}