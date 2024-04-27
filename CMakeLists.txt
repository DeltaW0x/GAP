cmake_minimum_required(VERSION 3.22)

project(GAP VERSION 1.0 LANGUAGES C CXX)
set (CMAKE_CXX_STANDARD 17)
include(FetchContent)


include_directories(${PROJECT_SOURCE_DIR}/rpi-rgb-led-matrix/lib)
include_directories(${PROJECT_SOURCE_DIR}/rpi-rgb-led-matrix/include)
file(GLOB_RECURSE RGB_SRC_FILES ${PROJECT_SOURCE_DIR}/rpi-rgb-led-matrix/lib/*.c*)
file(GLOB_RECURSE RGB_HEADER_FILES ${PROJECT_SOURCE_DIR}/rpi-rgb-led-matrix/include/*.h)

FetchContent_Declare(cglm GIT_REPOSITORY https://github.com/recp/cglm.git)
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(cglm json)


add_executable(${PROJECT_NAME}
    src/main.cpp
    src/objects/protogenFace.hpp
    src/utility/shader.hpp
    src/utility/mesh.hpp
    ${RGB_SRC_FILES}
    ${RGB_HEADER_FILES}
)

target_include_directories(${PROJECT_NAME} PRIVATE /opt/vc/include)
target_link_directories(${PROJECT_NAME} PRIVATE /opt/vc/lib)
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json cglm brcmGLESv2 brcmEGL -lpthread)

add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${PROJECT_NAME}
)

