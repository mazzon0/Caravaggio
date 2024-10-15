cmake_minimum_required(VERSION 3.21)

project(Caravaggio VERSION 0.0.1 LANGUAGES CXX)

add_subdirectory(ext/glfw)
if (WIN32)
   set(VOLK_STATIC_DEFINES VK_USE_PLATFORM_WIN32_KHR)
endif()
add_subdirectory(ext/volk)
add_subdirectory(src)
add_subdirectory(sandbox)