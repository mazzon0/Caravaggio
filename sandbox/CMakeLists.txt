file(GLOB_RECURSE SCRIPT_FILES "*.cpp")

add_executable(sandbox "${SCRIPT_FILES}")

target_link_libraries(sandbox PUBLIC engine)
target_include_directories(sandbox PRIVATE "../include/")