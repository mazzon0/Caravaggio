#ifndef CRVG_VKGRAPHICS
#define CRVG_VKGRAPHICS

#include "engine/graphics/Graphics.h"
#include "vk.h"
#include <iostream>

namespace engine {

    class VKGraphics final : public Graphics {
    public:
        VKGraphics();
        ~VKGraphics();

        void getDevices(std::vector<DeviceData>& devicesData) const override;

    private:
        void getRequiredExtensions(std::vector<const char*>& extensions);
        void getLayers(std::vector<const char*>& layers);
        DeviceData getProperties(VkPhysicalDevice device) const;

#   ifdef CB_DEBUG
        void createDebugMessenger();
#   endif

    private:
        VkInstance m_instance;
#   ifdef CB_DEBUG
        VkDebugUtilsMessengerEXT m_debugMessenger;
#   endif
    };

}

#ifdef CB_DEBUG
static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
        VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
        VkDebugUtilsMessageTypeFlagsEXT messageType,
        const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
        void* pUserData) {
        switch(messageSeverity) {
            case VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT:
                std::cout << "ERROR: Vulkan validation layer" << std::endl << pCallbackData->pMessage << std::endl;
                break;
            case VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT:
                std::cout << "WARN: Vulkan validation layer" << std::endl << pCallbackData->pMessage << std::endl;
                break;
        }

        return VK_FALSE;
    }
#endif

#endif
