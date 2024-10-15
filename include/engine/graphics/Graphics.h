#ifndef CRVG_GRAPHICS
#define CRVG_GRAPHICS

#include "Device.h"
#include <vector>

namespace engine {

    class Graphics {
    public:
        virtual void getDevices(std::vector<DeviceData>& devicesData) const = 0;
    };

}

#endif
