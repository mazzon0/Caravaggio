#include "engine/ui/fonts/FontSystem.h"

namespace engine {

    void FontSystem::iRegisterFont(std::string name, std::string filename) {
        m_fonts[name]=Font();
        /* TODO: load the actual font file */
    }

    void FontSystem::iUnregisterFont(std::string name) {
        m_fonts.erase(name);
    }

}