# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /cygdrive/c/Users/SQ/AppData/Local/JetBrains/CLion2020.2/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/SQ/AppData/Local/JetBrains/CLion2020.2/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/d/UCI_MCS/238P/homework2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/d/UCI_MCS/238P/homework2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/homework2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/homework2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/homework2.dir/flags.make

CMakeFiles/homework2.dir/sh238p.c.o: CMakeFiles/homework2.dir/flags.make
CMakeFiles/homework2.dir/sh238p.c.o: ../sh238p.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/UCI_MCS/238P/homework2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/homework2.dir/sh238p.c.o"
	/usr/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/homework2.dir/sh238p.c.o   -c /cygdrive/d/UCI_MCS/238P/homework2/sh238p.c

CMakeFiles/homework2.dir/sh238p.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/homework2.dir/sh238p.c.i"
	/usr/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/d/UCI_MCS/238P/homework2/sh238p.c > CMakeFiles/homework2.dir/sh238p.c.i

CMakeFiles/homework2.dir/sh238p.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/homework2.dir/sh238p.c.s"
	/usr/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/d/UCI_MCS/238P/homework2/sh238p.c -o CMakeFiles/homework2.dir/sh238p.c.s

# Object files for target homework2
homework2_OBJECTS = \
"CMakeFiles/homework2.dir/sh238p.c.o"

# External object files for target homework2
homework2_EXTERNAL_OBJECTS =

homework2.exe: CMakeFiles/homework2.dir/sh238p.c.o
homework2.exe: CMakeFiles/homework2.dir/build.make
homework2.exe: CMakeFiles/homework2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/d/UCI_MCS/238P/homework2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable homework2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/homework2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/homework2.dir/build: homework2.exe

.PHONY : CMakeFiles/homework2.dir/build

CMakeFiles/homework2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/homework2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/homework2.dir/clean

CMakeFiles/homework2.dir/depend:
	cd /cygdrive/d/UCI_MCS/238P/homework2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/d/UCI_MCS/238P/homework2 /cygdrive/d/UCI_MCS/238P/homework2 /cygdrive/d/UCI_MCS/238P/homework2/cmake-build-debug /cygdrive/d/UCI_MCS/238P/homework2/cmake-build-debug /cygdrive/d/UCI_MCS/238P/homework2/cmake-build-debug/CMakeFiles/homework2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/homework2.dir/depend
