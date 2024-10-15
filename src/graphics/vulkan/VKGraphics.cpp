#include "engine/graphics/vulkan/VKGraphics.h"
#include "engine/graphics/Device.h"
#include <glfw/glfw3.h>
#include <iostream>

namespace engine {

    VKGraphics::VKGraphics() {
        volkInitialize();

        VkApplicationInfo appInfo{};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = "Application";   /* TODO: add custom info */
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.pEngineName = "Engine";
        appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.apiVersion = VK_API_VERSION_1_2;

        VkInstanceCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInfo.pApplicationInfo = &appInfo;
        
#   ifdef CP_MACOS
        createInfo.flags |= VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;
#   endif

        std::vector<const char*> requiredExtensions;
        getRequiredExtensions(requiredExtensions);
        createInfo.enabledExtensionCount = (uint32_t) requiredExtensions.size();
        createInfo.ppEnabledExtensionNames = requiredExtensions.data();
        
        std::vector<const char*> layers;
        getLayers(layers);
        createInfo.enabledLayerCount = layers.size();
        createInfo.ppEnabledLayerNames = layers.data();

        VkResult result;
        if ((result=vkCreateInstance(&createInfo, nullptr, &m_instance)) != VK_SUCCESS) {
            std::cout << "ERROR: failed to create the Vulkan instance (VKGraphics::constructor)" << std::endl;
        }

        volkLoadInstance(m_instance);

        createDebugMessenger();
    }

    VKGraphics::~VKGraphics() {
#   ifdef CB_DEBUG
        vkDestroyDebugUtilsMessengerEXT(m_instance, m_debugMessenger, nullptr);
#   endif
        vkDestroyInstance(m_instance, nullptr);
    }

    void VKGraphics::getDevices(std::vector<DeviceData>& devicesData) const {
        VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
        uint32_t deviceCount = 0;
        vkEnumeratePhysicalDevices(m_instance, &deviceCount, nullptr);
        if (deviceCount == 0) {
            std::cout << "ERROR: no GPU with Vulkan support found (VKGraphics::getDevices)" << std::endl;
        }
        std::vector<VkPhysicalDevice> devices(deviceCount);
        vkEnumeratePhysicalDevices(m_instance, &deviceCount, devices.data());

        devicesData.reserve(deviceCount);
        for(auto& device : devices) {
            devicesData.emplace_back(getProperties(device));
        }
    }

    void VKGraphics::getRequiredExtensions(std::vector<const char*>& extensions) {
        uint32_t glfwExtensionCount = 0;
        const char** glfwExtensions;
        glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
        extensions.reserve(glfwExtensionCount+2);
        for(int i=0; i<glfwExtensionCount; ++i) {
            extensions.emplace_back(glfwExtensions[i]);
        }

#   ifdef CP_MACOS
        extensions.emplace_back(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME);
#   endif
#   ifdef CB_DEBUG
        extensions.emplace_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
#   endif
    }

    void VKGraphics::getLayers(std::vector<const char*>& layers) {
#   ifdef CB_DEBUG
        layers.emplace_back("VK_LAYER_KHRONOS_validation");

        // check if validation layers are present
        uint32_t layerCount;
        vkEnumerateInstanceLayerProperties(&layerCount, nullptr);
        std::vector<VkLayerProperties> availableLayers(layerCount);
        vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

        bool allLayersSupported = true;
        for (const char* layerName : layers) {
            bool layerFound = false;

            for (const auto& layerProperties : availableLayers) {
                if (strcmp(layerName, layerProperties.layerName) == 0) {
                    layerFound = true;
                    break;
                }
            }

            if (!layerFound) {
                allLayersSupported = false;
                break;
            }
        }

        if(!allLayersSupported) {
            std::cout << "ERROR: some validation layers are not supported" << std::endl;
        }
#   endif
    }

    DeviceData VKGraphics::getProperties(VkPhysicalDevice device) const {
        DeviceData data{};  /* TODO: implement */
        return data;
    }

#   ifdef CB_DEBUG
        void VKGraphics::createDebugMessenger() {
            VkDebugUtilsMessengerCreateInfoEXT createInfo{};
            createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
            createInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
            createInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
            createInfo.pfnUserCallback = debugCallback;
            createInfo.pUserData = nullptr;

            if(vkCreateDebugUtilsMessengerEXT(m_instance, &createInfo, nullptr, &m_debugMessenger) != VK_SUCCESS) {
                std::cout << "ERROR: failed to create the Vulkan debug messenger (VKGraphics::createDebugMessenger)" << std::endl;
            }
        }
#   endif

}