#include "engine/application/Application.h"

namespace engine {

    void Application::iInit(const char* exePath, GameScript* script) {
        // TODO: check gameScript not nullptr
        m_executablePath = exePath;
        m_running = true;
        m_gameScript = script;

        m_gameScript->init();
    }

    void Application::iRun() {
        m_gameScript->update();
    }

    void Application::iExit() {
        m_gameScript->exit();
        delete m_gameScript;
    }

}