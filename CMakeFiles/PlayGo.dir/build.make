# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/apowell/projects/ProjectGO

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/apowell/projects/ProjectGO

# Include any dependencies generated for this target.
include CMakeFiles/PlayGo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PlayGo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PlayGo.dir/flags.make

CMakeFiles/PlayGo.dir/src/board.cpp.o: CMakeFiles/PlayGo.dir/flags.make
CMakeFiles/PlayGo.dir/src/board.cpp.o: src/board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/apowell/projects/ProjectGO/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PlayGo.dir/src/board.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PlayGo.dir/src/board.cpp.o -c /home/apowell/projects/ProjectGO/src/board.cpp

CMakeFiles/PlayGo.dir/src/board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PlayGo.dir/src/board.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/apowell/projects/ProjectGO/src/board.cpp > CMakeFiles/PlayGo.dir/src/board.cpp.i

CMakeFiles/PlayGo.dir/src/board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PlayGo.dir/src/board.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/apowell/projects/ProjectGO/src/board.cpp -o CMakeFiles/PlayGo.dir/src/board.cpp.s

CMakeFiles/PlayGo.dir/src/group.cpp.o: CMakeFiles/PlayGo.dir/flags.make
CMakeFiles/PlayGo.dir/src/group.cpp.o: src/group.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/apowell/projects/ProjectGO/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PlayGo.dir/src/group.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PlayGo.dir/src/group.cpp.o -c /home/apowell/projects/ProjectGO/src/group.cpp

CMakeFiles/PlayGo.dir/src/group.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PlayGo.dir/src/group.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/apowell/projects/ProjectGO/src/group.cpp > CMakeFiles/PlayGo.dir/src/group.cpp.i

CMakeFiles/PlayGo.dir/src/group.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PlayGo.dir/src/group.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/apowell/projects/ProjectGO/src/group.cpp -o CMakeFiles/PlayGo.dir/src/group.cpp.s

CMakeFiles/PlayGo.dir/src/piece.cpp.o: CMakeFiles/PlayGo.dir/flags.make
CMakeFiles/PlayGo.dir/src/piece.cpp.o: src/piece.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/apowell/projects/ProjectGO/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/PlayGo.dir/src/piece.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PlayGo.dir/src/piece.cpp.o -c /home/apowell/projects/ProjectGO/src/piece.cpp

CMakeFiles/PlayGo.dir/src/piece.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PlayGo.dir/src/piece.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/apowell/projects/ProjectGO/src/piece.cpp > CMakeFiles/PlayGo.dir/src/piece.cpp.i

CMakeFiles/PlayGo.dir/src/piece.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PlayGo.dir/src/piece.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/apowell/projects/ProjectGO/src/piece.cpp -o CMakeFiles/PlayGo.dir/src/piece.cpp.s

CMakeFiles/PlayGo.dir/main.cpp.o: CMakeFiles/PlayGo.dir/flags.make
CMakeFiles/PlayGo.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/apowell/projects/ProjectGO/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/PlayGo.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PlayGo.dir/main.cpp.o -c /home/apowell/projects/ProjectGO/main.cpp

CMakeFiles/PlayGo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PlayGo.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/apowell/projects/ProjectGO/main.cpp > CMakeFiles/PlayGo.dir/main.cpp.i

CMakeFiles/PlayGo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PlayGo.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/apowell/projects/ProjectGO/main.cpp -o CMakeFiles/PlayGo.dir/main.cpp.s

# Object files for target PlayGo
PlayGo_OBJECTS = \
"CMakeFiles/PlayGo.dir/src/board.cpp.o" \
"CMakeFiles/PlayGo.dir/src/group.cpp.o" \
"CMakeFiles/PlayGo.dir/src/piece.cpp.o" \
"CMakeFiles/PlayGo.dir/main.cpp.o"

# External object files for target PlayGo
PlayGo_EXTERNAL_OBJECTS =

PlayGo: CMakeFiles/PlayGo.dir/src/board.cpp.o
PlayGo: CMakeFiles/PlayGo.dir/src/group.cpp.o
PlayGo: CMakeFiles/PlayGo.dir/src/piece.cpp.o
PlayGo: CMakeFiles/PlayGo.dir/main.cpp.o
PlayGo: CMakeFiles/PlayGo.dir/build.make
PlayGo: CMakeFiles/PlayGo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/apowell/projects/ProjectGO/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable PlayGo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PlayGo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PlayGo.dir/build: PlayGo

.PHONY : CMakeFiles/PlayGo.dir/build

CMakeFiles/PlayGo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PlayGo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PlayGo.dir/clean

CMakeFiles/PlayGo.dir/depend:
	cd /home/apowell/projects/ProjectGO && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/apowell/projects/ProjectGO /home/apowell/projects/ProjectGO /home/apowell/projects/ProjectGO /home/apowell/projects/ProjectGO /home/apowell/projects/ProjectGO/CMakeFiles/PlayGo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PlayGo.dir/depend
