cmake_minimum_required(VERSION 3.12)
project(terminal)

set(CMAKE_CXX_STANDARD 17)

add_executable(terminal main.cpp Models/Command.cpp Models/Command.h Models/Argument.cpp Models/Argument.h Helpers/TermianlHelper.h Handlers/Handler.h Handlers/LogInHandler.cpp Handlers/LogInHandler.h Handlers/QuitHandler.cpp Handlers/QuitHandler.h Handlers/Container.h Handlers/MyFindHandler.cpp Handlers/MyFindHandler.h Handlers/MyStatHandler.cpp Handlers/MyStatHandler.h Helpers/FileHelper.h Helpers/PipeHelper.h Services/LogInService.cpp Services/LogInService.h)