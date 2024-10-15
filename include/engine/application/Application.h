#ifndef CVRG_APP
#define CVRG_APP

#include "engine/scripting/GameScript.h"
#include "engine/graphics/Graphics.h"

namespace engine {

    class Application {
    public:
        static inline void init(const char* exePath, GameScript* script) { getInstance().iInit(exePath, script); }
        static inline void run() { getInstance().iRun();}
        static inline void exit() { getInstance().iExit();}

        static inline void close() { getInstance().iClose(); }

    private:
        void iInit(const char* exePath, GameScript* script);
        void iRun();
        void iExit();
        void iClose() { m_running = false; }

        Graphics* m_graphics;
        const char* m_executablePath;
        bool m_running;
        GameScript* m_gameScript;

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