cmake_minimum_required(VERSION 3.5)

project(4-1Lambda LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(4-1Lambda main.cpp)

include(GNUInstallDirs)
install(TARGETS 4-1Lambda
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
