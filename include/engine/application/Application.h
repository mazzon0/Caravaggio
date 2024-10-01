#ifndef CVRG_APP
#define CVRG_APP

#include "engine/scripting/GameScript.h"

namespace engine {

    class Application {
    public:
        static inline void init(const char* exePath, GameScript* script) { getInstance().iInit(exePath, script); }
        static inline void run() { getInstance().iRun();}
        static inline void exit() { getInstance().iExit();}

    private:
        void iInit(const char* exePath, GameScript* script);
        void iRun();
        void iExit();

        const char* executablePath;
        bool running;
        GameScript* gameScript;

    private:
        Application() = default;
        ~Application() = default;
        
        static inline Application& getInstance() {
            static Application instance;
            return instance;
        }

        Application(const Application&) = delete;
        Application& operator=(const Application&) = delete;
    };

}

#endif