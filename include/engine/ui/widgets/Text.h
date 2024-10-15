#ifndef CRVG_TEXT
#define CRVG_TEXT

#include <vector>
#include <string>
#include "Widget.h"

namespace engine {

    class Text final : public Widget {
    public:
        Text();
        Text(std::string str, std::string fontName);
        Text(const std::vector<uint32_t>& chars, std::string fontName);
    private:
        std::vector<uint32_t> m_chars;
        std::string m_fontName;
    };

}

#endif
