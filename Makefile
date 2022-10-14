# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/apowell/projects/ProjectGO/CMakeFiles /home/apowell/projects/ProjectGO/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/apowell/projects/ProjectGO/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named TestLibrary

# Build rule for target.
TestLibrary: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 TestLibrary
.PHONY : TestLibrary

# fast build rule for target.
TestLibrary/fast:
	$(MAKE) -f CMakeFiles/TestLibrary.dir/build.make CMakeFiles/TestLibrary.dir/build
.PHONY : TestLibrary/fast

#=============================================================================
# Target rules for targets named TestGo

# Build rule for target.
TestGo: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 TestGo
.PHONY : TestGo

# fast build rule for target.
TestGo/fast:
	$(MAKE) -f CMakeFiles/TestGo.dir/build.make CMakeFiles/TestGo.dir/build
.PHONY : TestGo/fast

#=============================================================================
# Target rules for targets named MainLibrary

# Build rule for target.
MainLibrary: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 MainLibrary
.PHONY : MainLibrary

# fast build rule for target.
MainLibrary/fast:
	$(MAKE) -f CMakeFiles/MainLibrary.dir/build.make CMakeFiles/MainLibrary.dir/build
.PHONY : MainLibrary/fast

#=============================================================================
# Target rules for targets named PlayGo

# Build rule for target.
PlayGo: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 PlayGo
.PHONY : PlayGo

# fast build rule for target.
PlayGo/fast:
	$(MAKE) -f CMakeFiles/PlayGo.dir/build.make CMakeFiles/PlayGo.dir/build
.PHONY : PlayGo/fast

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/MainLibrary.dir/build.make CMakeFiles/MainLibrary.dir/main.cpp.o
	$(MAKE) -f CMakeFiles/PlayGo.dir/build.make CMakeFiles/PlayGo.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/MainLibrary.dir/build.make CMakeFiles/MainLibrary.dir/main.cpp.i
	$(MAKE) -f CMakeFiles/PlayGo.dir/build.make CMakeFiles/PlayGo.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/MainLibrary.dir/build.make CMakeFiles/MainLibrary.dir/main.cpp.s
	$(MAKE) -f CMakeFiles/PlayGo.dir/build.make CMakeFiles/PlayGo.dir/main.cpp.s
.PHONY : main.cpp.s

src/board.o: src/board.cpp.o

.PHONY : src/board.o

# target to build an object file
src/board.cpp.o:
	$(MAKE) -f CMakeFiles/TestLibrary.dir/build.make CMakeFiles/TestLibrary.dir/src/board.cpp.o
	$(MAKE) -f CMakeFiles/TestGo.dir/build.make CMakeFiles/TestGo.dir/src/board.cpp.o
	$(MAKE) -f CMakeFiles/MainLibrary.dir/build.make CMakeFiles/MainLibrary.dir/src/board.cpp.o
	$(MAKE) -f CMakeFiles/PlayGo.dir/build.make CMakeFiles/PlayGo.dir/src/board.cpp.o
.PHONY : src/board.cpp.o

src/board.i: src/board.cpp.i

.PHONY : src/board.i

# target to preprocess a source file
src/board.cpp.i:
	$(MAKE) -f CMakeFiles/TestLibrary.dir/build.make CMakeFiles/TestLibrary.dir/src/board.cpp.i
	$(MAKE) -f CMakeFiles/TestGo.dir/build.make CMakeFiles/TestGo.dir/src/board.cpp.i
	$(MAKE) -f CMakeFiles/MainLibrary.dir/build.make CMakeFiles/MainLibrary.dir/src/board.cpp.i
	$(MAKE) -f CMakeFiles/PlayGo.dir/build.make CMakeFiles/PlayGo.dir/src/board.cpp.i
.PHONY : src/board.cpp.i

src/board.s: src/board.cpp.s

.PHONY : src/board.s

# target to generate assembly for a file
src/board.cpp.s:
	$(MAKE) -f CMakeFiles/TestLibrary.dir/build.make CMakeFiles/TestLibrary.dir/src/board.cpp.s
	$(MAKE) -f CMakeFiles/TestGo.dir/build.make CMakeFiles/TestGo.dir/src/board.cpp.s
	$(MAKE) -f CMakeFiles/MainLibrary.dir/build.make CMakeFiles/MainLibrary.dir/src/board.cpp.s
	$(MAKE) -f CMakeFiles/PlayGo.dir/build.make CMakeFiles/PlayGo.dir/src/board.cpp.s
.PHONY : src/board.cpp.s

src/group.o: src/group.cpp.o

.PHONY : src/group.o

# target to build an object file
src/group.cpp.o:
	$(MAKE) -f CMakeFiles/TestLibrary.dir/build.make CMakeFiles/TestLibrary.dir/src/group.cpp.o
	$(MAKE) -f CMakeFiles/TestGo.dir/build.make CMakeFiles/TestGo.dir/src/group.cpp.o
	$(MAKE) -f CMakeFiles/MainLibrary.dir/build.make CMakeFiles/MainLibrary.dir/src/group.cpp.o
	$(MAKE) -f CMakeFiles/PlayGo.dir/build.make CMakeFiles/PlayGo.dir/src/group.cpp.o
.PHONY : src/group.cpp.o

src/group.i: src/group.cpp.i

.PHONY : src/group.i

# target to preprocess a source file
src/group.cpp.i:
	$(MAKE) -f CMakeFiles/TestLibrary.dir/build.make CMakeFiles/TestLibrary.dir/src/group.cpp.i
	$(MAKE) -f CMakeFiles/TestGo.dir/build.make CMakeFiles/TestGo.dir/src/group.cpp.i
	$(MAKE) -f CMakeFiles/MainLibrary.dir/build.make CMakeFiles/MainLibrary.dir/src/group.cpp.i
	$(MAKE) -f CMakeFiles/PlayGo.dir/build.make CMakeFiles/PlayGo.dir/src/group.cpp.i
.PHONY : src/group.cpp.i

src/group.s: src/group.cpp.s

.PHONY : src/group.s

# target to generate assembly for a file
src/group.cpp.s:
	$(MAKE) -f CMakeFiles/TestLibrary.dir/build.make CMakeFiles/TestLibrary.dir/src/group.cpp.s
	$(MAKE) -f CMakeFiles/TestGo.dir/build.make CMakeFiles/TestGo.dir/src/group.cpp.s
	$(MAKE) -f CMakeFiles/MainLibrary.dir/build.make CMakeFiles/MainLibrary.dir/src/group.cpp.s
	$(MAKE) -f CMakeFiles/PlayGo.dir/build.make CMakeFiles/PlayGo.dir/src/group.cpp.s
.PHONY : src/group.cpp.s

src/piece.o: src/piece.cpp.o

.PHONY : src/piece.o

# target to build an object file
src/piece.cpp.o:
	$(MAKE) -f CMakeFiles/TestLibrary.dir/build.make CMakeFiles/TestLibrary.dir/src/piece.cpp.o
	$(MAKE) -f CMakeFiles/TestGo.dir/build.make CMakeFiles/TestGo.dir/src/piece.cpp.o
	$(MAKE) -f CMakeFiles/MainLibrary.dir/build.make CMakeFiles/MainLibrary.dir/src/piece.cpp.o
	$(MAKE) -f CMakeFiles/PlayGo.dir/build.make CMakeFiles/PlayGo.dir/src/piece.cpp.o
.PHONY : src/piece.cpp.o

src/piece.i: src/piece.cpp.i

.PHONY : src/piece.i

# target to preprocess a source file
src/piece.cpp.i:
	$(MAKE) -f CMakeFiles/TestLibrary.dir/build.make CMakeFiles/TestLibrary.dir/src/piece.cpp.i
	$(MAKE) -f CMakeFiles/TestGo.dir/build.make CMakeFiles/TestGo.dir/src/piece.cpp.i
	$(MAKE) -f CMakeFiles/MainLibrary.dir/build.make CMakeFiles/MainLibrary.dir/src/piece.cpp.i
	$(MAKE) -f CMakeFiles/PlayGo.dir/build.make CMakeFiles/PlayGo.dir/src/piece.cpp.i
.PHONY : src/piece.cpp.i

src/piece.s: src/piece.cpp.s

.PHONY : src/piece.s

# target to generate assembly for a file
src/piece.cpp.s:
	$(MAKE) -f CMakeFiles/TestLibrary.dir/build.make CMakeFiles/TestLibrary.dir/src/piece.cpp.s
	$(MAKE) -f CMakeFiles/TestGo.dir/build.make CMakeFiles/TestGo.dir/src/piece.cpp.s
	$(MAKE) -f CMakeFiles/MainLibrary.dir/build.make CMakeFiles/MainLibrary.dir/src/piece.cpp.s
	$(MAKE) -f CMakeFiles/PlayGo.dir/build.make CMakeFiles/PlayGo.dir/src/piece.cpp.s
.PHONY : src/piece.cpp.s

test/test.o: test/test.cpp.o

.PHONY : test/test.o

# target to build an object file
test/test.cpp.o:
	$(MAKE) -f CMakeFiles/TestLibrary.dir/build.make CMakeFiles/TestLibrary.dir/test/test.cpp.o
	$(MAKE) -f CMakeFiles/TestGo.dir/build.make CMakeFiles/TestGo.dir/test/test.cpp.o
.PHONY : test/test.cpp.o

test/test.i: test/test.cpp.i

.PHONY : test/test.i

# target to preprocess a source file
test/test.cpp.i:
	$(MAKE) -f CMakeFiles/TestLibrary.dir/build.make CMakeFiles/TestLibrary.dir/test/test.cpp.i
	$(MAKE) -f CMakeFiles/TestGo.dir/build.make CMakeFiles/TestGo.dir/test/test.cpp.i
.PHONY : test/test.cpp.i

test/test.s: test/test.cpp.s

.PHONY : test/test.s

# target to generate assembly for a file
test/test.cpp.s:
	$(MAKE) -f CMakeFiles/TestLibrary.dir/build.make CMakeFiles/TestLibrary.dir/test/test.cpp.s
	$(MAKE) -f CMakeFiles/TestGo.dir/build.make CMakeFiles/TestGo.dir/test/test.cpp.s
.PHONY : test/test.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... TestLibrary"
	@echo "... TestGo"
	@echo "... MainLibrary"
	@echo "... PlayGo"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... src/board.o"
	@echo "... src/board.i"
	@echo "... src/board.s"
	@echo "... src/group.o"
	@echo "... src/group.i"
	@echo "... src/group.s"
	@echo "... src/piece.o"
	@echo "... src/piece.i"
	@echo "... src/piece.s"
	@echo "... test/test.o"
	@echo "... test/test.i"
	@echo "... test/test.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

