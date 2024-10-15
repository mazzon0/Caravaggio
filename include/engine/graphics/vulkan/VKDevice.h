#ifndef CRVG_VKDEVICE
#define CRVG_VKDEVICE

#include "engine/graphics/Device.h"
#include <stdint.h>

namespace engine {

    class VKDevice final : public Device {
    public:
        VKDevice();
        ~VKDevice();

    private:
        static uint32_t s_numInstances;
    };

}

#endif
