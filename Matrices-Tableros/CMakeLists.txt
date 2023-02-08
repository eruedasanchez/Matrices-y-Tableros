cmake_minimum_required(VERSION 3.5)
project(Matrices-Tableros)

# Algunos flags para pasar al compilador (gnu++11 en vez de c++11 para que sea cross-plat)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-pthread")

add_library(gtest lib/gtest-1.8.1/gtest-all.cc lib/gtest-1.8.1/gtest_main.cc)

# Leemos todos los archivos fuentes en ./src
add_executable(Matrices-Tableros
        main.cpp
        src/solucion.cpp
        src/solucion.h
        )
# Mantenemos la informacion de coverage en el linkeo
set_target_properties(Matrices-Tableros PROPERTIES COMPILE_FLAGS "-g --coverage")
set_target_properties(Matrices-Tableros PROPERTIES LINK_FLAGS "-g --coverage")

target_link_libraries(Matrices-Tableros gtest)


