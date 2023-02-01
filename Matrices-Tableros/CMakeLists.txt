cmake_minimum_required(VERSION 3.5)
project(L07-MatricesYTableros)

# Algunos flags para pasar al compilador (gnu++11 en vez de c++11 para que sea cross-plat)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -ggdb3 -g --coverage -Wno-deprecated-declarations")

# Leemos todos los archivos fuentes en ./src
file(GLOB SOURCE_FILES src/*.cpp src/*.h src/*.hpp)

add_executable(MatricesYTableros main.cpp ${SOURCE_FILES} lib/gtest-1.8.1/gtest_main.cc lib/gtest-1.8.1/gtest-all.cc)

# Mantenemos la informacion de coverage en el linkeo
set_target_properties(MatricesYTableros PROPERTIES LINK_FLAGS "-g --coverage")



#[[
# Dependencia de Google Test
SET(BUILD_GMOCK OFF)
SET(BUILD_GTEST ON)
add_library(gtest STATIC lib/gtest-1.8.1/gtest-all.cc)
add_library(gtest_main STATIC lib/gtest-1.8.1/gtest_main.cc)

# Leemos todos los archivos de test en ./tests
file(GLOB TEST_FILES tests/*.cpp)
add_executable(MatricesYTablerosTest ${SOURCE_FILES} ${TEST_FILES} )
# Mantenemos la informacion de coverage en el linkeo
set_target_properties(MatricesYTablerosTest PROPERTIES LINK_FLAGS "-g --coverage")

# Necesitamos asociar los archivos del framework de testing
target_link_libraries(MatricesYTablerosTest gtest gtest_main)

# Test suites a ejecutar
add_test(MatricesYTablerosTest matrices_tableros_test)]]
