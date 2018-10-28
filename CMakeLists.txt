cmake_minimum_required(VERSION 3.12)
project(Tema_1 C)

set(CMAKE_C_STANDARD 11)

add_executable(Tema_1 main.c Helpers/TerminalHelper.h Handlers/LogInHandler.h Models/Command.h Models/Argument.h Models/LogInData.h)