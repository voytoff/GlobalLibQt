cmake_minimum_required(VERSION 3.17)
project(GlobalLib LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(GlobalLib SHARED
  GlobalLib_global.h
  globallib.h globallib.cpp
  lib.h lib.cpp
  parameter.h parameter.cpp
  file.cpp file.h
  datablockarray.cpp datablockarray.h
  isensorconverter.h
  qtdynamometer.h qtdynamometer.cpp
  interfacefactory.h interfacefactory.cpp
  #channelblock.cpp channelblock.h
)

# Link your executable against Qt Core
target_link_libraries(GlobalLib PRIVATE Qt${QT_VERSION_MAJOR}::Core)
#target_link_libraries(GlobalLib PRIVATE Qt6::Core)
target_compile_definitions(GlobalLib PUBLIC GLOBALLIB_LIBRARY)
