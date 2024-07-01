project(WaylandClientApplication VERSION 1.0.0)

file(GLOB_RECURSE WAYLAND_CLIENT_APPLICATION_SOURCES ${PROJECT_SOURCE_DIR}/*/*.cpp)

add_executable(
    app
    ${WAYLAND_CLIENT_APPLICATION_SOURCES}
)

target_link_libraries(
    app
    PRIVATE
    SWCF
)

target_include_directories(
    app
    PUBLIC
    "${CMAKE_SOURCE_DIR}/include"
)