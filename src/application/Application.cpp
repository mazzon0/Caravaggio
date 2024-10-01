#include "engine/application/Application.h"

namespace engine {

    void Application::iInit(const char* exePath, GameScript* script) {
        // TODO: check gameScript not nullptr
        executablePath = exePath;
        running = true;
        gameScript = script;

        gameScript->init();
    }

    void Application::iRun() {
        gameScript->update();
    }

    void Application::iExit() {
        gameScript->exit();
        delete gameScript;
    }

}