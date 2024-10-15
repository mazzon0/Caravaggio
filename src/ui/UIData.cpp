#include "engine/ui/UIData.h"
#include <random>

namespace engine {

    WidgetID UIData::randomID() {
        static std::random_device rd;
        static std::mt19937 engine(rd());
        static std::uniform_int_distribution<uint32_t> dist(0, UINT32_MAX);

        return dist(engine);
    }
    
}