# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/44/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/44/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ursaciuc/_Work/computer-networks/terminal

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ursaciuc/_Work/computer-networks/terminal/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/terminal.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/terminal.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/terminal.dir/flags.make

CMakeFiles/terminal.dir/main.cpp.o: CMakeFiles/terminal.dir/flags.make
CMakeFiles/terminal.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ursaciuc/_Work/computer-networks/terminal/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/terminal.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/terminal.dir/main.cpp.o -c /home/ursaciuc/_Work/computer-networks/terminal/main.cpp

CMakeFiles/terminal.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/terminal.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ursaciuc/_Work/computer-networks/terminal/main.cpp > CMakeFiles/terminal.dir/main.cpp.i

CMakeFiles/terminal.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/terminal.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ursaciuc/_Work/computer-networks/terminal/main.cpp -o CMakeFiles/terminal.dir/main.cpp.s

CMakeFiles/terminal.dir/Models/Command.cpp.o: CMakeFiles/terminal.dir/flags.make
CMakeFiles/terminal.dir/Models/Command.cpp.o: ../Models/Command.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ursaciuc/_Work/computer-networks/terminal/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/terminal.dir/Models/Command.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/terminal.dir/Models/Command.cpp.o -c /home/ursaciuc/_Work/computer-networks/terminal/Models/Command.cpp

CMakeFiles/terminal.dir/Models/Command.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/terminal.dir/Models/Command.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ursaciuc/_Work/computer-networks/terminal/Models/Command.cpp > CMakeFiles/terminal.dir/Models/Command.cpp.i

CMakeFiles/terminal.dir/Models/Command.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/terminal.dir/Models/Command.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ursaciuc/_Work/computer-networks/terminal/Models/Command.cpp -o CMakeFiles/terminal.dir/Models/Command.cpp.s

CMakeFiles/terminal.dir/Models/Argument.cpp.o: CMakeFiles/terminal.dir/flags.make
CMakeFiles/terminal.dir/Models/Argument.cpp.o: ../Models/Argument.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ursaciuc/_Work/computer-networks/terminal/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/terminal.dir/Models/Argument.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/terminal.dir/Models/Argument.cpp.o -c /home/ursaciuc/_Work/computer-networks/terminal/Models/Argument.cpp

CMakeFiles/terminal.dir/Models/Argument.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/terminal.dir/Models/Argument.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ursaciuc/_Work/computer-networks/terminal/Models/Argument.cpp > CMakeFiles/terminal.dir/Models/Argument.cpp.i

CMakeFiles/terminal.dir/Models/Argument.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/terminal.dir/Models/Argument.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ursaciuc/_Work/computer-networks/terminal/Models/Argument.cpp -o CMakeFiles/terminal.dir/Models/Argument.cpp.s

CMakeFiles/terminal.dir/Handlers/LogInHandler.cpp.o: CMakeFiles/terminal.dir/flags.make
CMakeFiles/terminal.dir/Handlers/LogInHandler.cpp.o: ../Handlers/LogInHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ursaciuc/_Work/computer-networks/terminal/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/terminal.dir/Handlers/LogInHandler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/terminal.dir/Handlers/LogInHandler.cpp.o -c /home/ursaciuc/_Work/computer-networks/terminal/Handlers/LogInHandler.cpp

CMakeFiles/terminal.dir/Handlers/LogInHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/terminal.dir/Handlers/LogInHandler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ursaciuc/_Work/computer-networks/terminal/Handlers/LogInHandler.cpp > CMakeFiles/terminal.dir/Handlers/LogInHandler.cpp.i

CMakeFiles/terminal.dir/Handlers/LogInHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/terminal.dir/Handlers/LogInHandler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ursaciuc/_Work/computer-networks/terminal/Handlers/LogInHandler.cpp -o CMakeFiles/terminal.dir/Handlers/LogInHandler.cpp.s

CMakeFiles/terminal.dir/Handlers/QuitHandler.cpp.o: CMakeFiles/terminal.dir/flags.make
CMakeFiles/terminal.dir/Handlers/QuitHandler.cpp.o: ../Handlers/QuitHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ursaciuc/_Work/computer-networks/terminal/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/terminal.dir/Handlers/QuitHandler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/terminal.dir/Handlers/QuitHandler.cpp.o -c /home/ursaciuc/_Work/computer-networks/terminal/Handlers/QuitHandler.cpp

CMakeFiles/terminal.dir/Handlers/QuitHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/terminal.dir/Handlers/QuitHandler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ursaciuc/_Work/computer-networks/terminal/Handlers/QuitHandler.cpp > CMakeFiles/terminal.dir/Handlers/QuitHandler.cpp.i

CMakeFiles/terminal.dir/Handlers/QuitHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/terminal.dir/Handlers/QuitHandler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ursaciuc/_Work/computer-networks/terminal/Handlers/QuitHandler.cpp -o CMakeFiles/terminal.dir/Handlers/QuitHandler.cpp.s

# Object files for target terminal
terminal_OBJECTS = \
"CMakeFiles/terminal.dir/main.cpp.o" \
"CMakeFiles/terminal.dir/Models/Command.cpp.o" \
"CMakeFiles/terminal.dir/Models/Argument.cpp.o" \
"CMakeFiles/terminal.dir/Handlers/LogInHandler.cpp.o" \
"CMakeFiles/terminal.dir/Handlers/QuitHandler.cpp.o"

# External object files for target terminal
terminal_EXTERNAL_OBJECTS =

terminal: CMakeFiles/terminal.dir/main.cpp.o
terminal: CMakeFiles/terminal.dir/Models/Command.cpp.o
terminal: CMakeFiles/terminal.dir/Models/Argument.cpp.o
terminal: CMakeFiles/terminal.dir/Handlers/LogInHandler.cpp.o
terminal: CMakeFiles/terminal.dir/Handlers/QuitHandler.cpp.o
terminal: CMakeFiles/terminal.dir/build.make
terminal: CMakeFiles/terminal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ursaciuc/_Work/computer-networks/terminal/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable terminal"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/terminal.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/terminal.dir/build: terminal

.PHONY : CMakeFiles/terminal.dir/build

CMakeFiles/terminal.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/terminal.dir/cmake_clean.cmake
.PHONY : CMakeFiles/terminal.dir/clean

CMakeFiles/terminal.dir/depend:
	cd /home/ursaciuc/_Work/computer-networks/terminal/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ursaciuc/_Work/computer-networks/terminal /home/ursaciuc/_Work/computer-networks/terminal /home/ursaciuc/_Work/computer-networks/terminal/cmake-build-debug /home/ursaciuc/_Work/computer-networks/terminal/cmake-build-debug /home/ursaciuc/_Work/computer-networks/terminal/cmake-build-debug/CMakeFiles/terminal.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/terminal.dir/depend

