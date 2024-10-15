#include "engine/ui/widgets/Text.h"

namespace engine {

    Text::Text():m_fontName("") {}

    Text::Text(std::string str, std::string fontName):m_fontName(fontName) {
        m_chars.reserve(str.length());
        for(size_t i=0; i<str.length(); ++i) {
            m_chars.push_back(static_cast<uint32_t>(str[i]));
        }
    }

    Text::Text(const std::vector<uint32_t>& chars, std::string fontName):m_chars(chars), m_fontName(fontName) {}

}