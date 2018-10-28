cmake_minimum_required(VERSION 3.12)
project(Tema_1 C)

set(CMAKE_C_STANDARD 11)

add_executable(Tema_1 main.c terminalHelper.h loginService.h models.h Models/Argument.h Models/Command.h)