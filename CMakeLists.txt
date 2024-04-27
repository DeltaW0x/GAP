cmake_minimum_required(VERSION 3.22)

project(GAP VERSION 1.0 LANGUAGES C CXX)
set (CMAKE_CXX_STANDARD 17)
include(FetchContent)


include_directories(${PROJECT_SOURCE_DIR}/rpi-rgb-led-matrix/lib)
include_directories(${PROJECT_SOURCE_DIR}/rpi-rgb-led-matrix/include)
file(GLOB_RECURSE RGB_SRC_FILES ${PROJECT_SOURCE_DIR}/rpi-rgb-led-matrix/lib/*.c*)
file(GLOB_RECURSE RGB_HEADER_FILES ${PROJECT_SOURCE_DIR}/rpi-rgb-led-matrix/include/*.h)

FetchContent_Declare(cglm GIT_REPOSITORY https://github.com/recp/cglm.git)
FetchContent_Declare(assimp GIT_REPOSITORY https://github.com/assimp/assimp.git GIT_TAG master)

FetchContent_MakeAvailable(cglm assimp)


add_executable(${PROJECT_NAME}
    src/main.cpp
    src/objects/protogenFace.hpp
    src/utility/shader.hpp
    src/utility/mesh.hpp
    ${RGB_SRC_FILES}
    ${RGB_HEADER_FILES}
)

target_include_directories(${PROJECT_NAME} PRIVATE /opt/vc/include assimp-src/include)
target_link_directories(${PROJECT_NAME} PRIVATE /opt/vc/lib)
target_link_libraries(${PROJECT_NAME} PRIVATE assimp cglm brcmGLESv2 brcmEGL -lpthread)



add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/Assets
                ${CMAKE_CURRENT_BINARY_DIR}/Assets)

