set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
file(GLOB_RECURSE SRC_FILES "*.cpp")

add_library(engine STATIC "${SRC_FILES}")

if(CRVG_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(engine PUBLIC CB_DEBUG)
elseif(CRVG_BUILD_TYPE STREQUAL "Profile")
    target_compile_definitions(engine PUBLIC CB_PROFILE)
else()
    target_compile_definitions(engine PUBLIC CB_RELEASE)
endif()

if(CRVG_PLATFORM STREQUAL "Windows")
    target_compile_definitions(engine PUBLIC CP_WINDOWS)
endif()

target_include_directories(engine PRIVATE
    "${PROJECT_SOURCE_DIR}/include"
    "${PROJECT_SOURCE_DIR}/ext")

target_link_libraries(engine PUBLIC glfw)