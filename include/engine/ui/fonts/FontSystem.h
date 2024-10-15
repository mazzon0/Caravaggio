#ifndef CRVG_FONTSYSTEM
#define CRVG_FONTSYSTEM

#include <string>
#include <unordered_map>
#include "engine/ui/fonts/Font.h"

namespace engine {

    /* TODO: optimize string usage */
    class FontSystem {
    public:
        static void registerFont(std::string name, std::string filename) {getInstance().iRegisterFont(name, filename);}
        static void unregisterFont(std::string name) {getInstance().iUnregisterFont(name);}

    private:
        void iRegisterFont(std::string name, std::string filename);
        void iUnregisterFont(std::string name);

        std::unordered_map<std::string, Font> m_fonts;

    private:
        static FontSystem& getInstance() {
            static FontSystem instance;  
            return instance;
        }

        FontSystem(const FontSystem&) = delete;
        FontSystem& operator=(const FontSystem&) = delete;

        FontSystem() = default;
        ~FontSystem() = default;
    };

}

#endif
