cmake_minimum_required(VERSION 3.12)
project(Lista1)

set(CMAKE_CXX_STANDARD 98)

add_executable(Lista1 main.cpp CTable/CTable.cpp CTable/CTable.h Tools/Tools.cpp Tools/Tools.h UserInterface/UserInterface.cpp UserInterface/UserInterface.h CApplicationHandler/CApplicationHandler.cpp CApplicationHandler/CApplicationHandler.h)