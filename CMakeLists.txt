cmake_minimum_required(VERSION 3.29)
project(Minesweeper)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ruta a los archivos fuente
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Incluir el directorio de encabezados
include_directories(include)

# Crear el ejecutable
add_executable(${PROJECT_NAME} ${SOURCES})
