project(SWCF_Shared_Library VERSION 1.0.0)

file(GLOB_RECURSE SWCF_LIBRARY_SOURCES ${PROJECT_SOURCE_DIR}/*/*.cpp)


add_library(
    SWCF SHARED
    ${SWCF_LIBRARY_SOURCES}    
)

target_link_libraries(SWCF PRIVATE wayland-client GL)

target_include_directories(SWCF PUBLIC "${CMAKE_SOURCE_DIR}/include")