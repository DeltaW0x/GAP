cmake_minimum_required(VERSION 3.3)

project(
  GAP
  VERSION 1.0
  LANGUAGES CXX)

  add_executable(gap
    src/main.cpp
    src/objects/protogenFace.hpp
    src/utility/shader.hpp
    src/utility/mesh.hpp)

find_package(cglm REQUIRED)
target_include_directories(gap PUBLIC /opt/vc/include ${cglm_INCLUDE_DIRS})
target_link_directories(gap PUBLIC /opt/vc/lib)
target_link_libraries(gap PUBLIC brcmGLESv2 brcmEGL ${cglm_LIBRARIES})
