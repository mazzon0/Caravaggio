cmake_minimum_required(VERSION 3.21)

project(Caravaggio VERSION 0.0.1 LANGUAGES CXX)

add_subdirectory(ext/glfw)
add_subdirectory(ext/volk)
add_subdirectory(src)
add_subdirectory(sandbox)