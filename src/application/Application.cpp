#include "engine/application/Application.h"
#include "engine/platform/Platform.h"

namespace engine {

    void Application::iInit(const char* exePath, GameScript* script) {
        // TODO: check gameScript not nullptr
        m_executablePath = exePath;
        m_running = true;
        m_gameScript = script;

        m_gameScript->init();
    }

    void Application::iRun() {
        while(m_running) {
            m_gameScript->update();
            Platform::sendEvents();
        }
    }

    void Application::iExit() {
        m_gameScript->exit();
        delete m_gameScript;
    }

}