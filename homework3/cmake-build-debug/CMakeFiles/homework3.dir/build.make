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
CMAKE_SOURCE_DIR = /cygdrive/d/UCI_MCS/238P/homework3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/d/UCI_MCS/238P/homework3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/homework3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/homework3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/homework3.dir/flags.make

CMakeFiles/homework3.dir/main.c.o: CMakeFiles/homework3.dir/flags.make
CMakeFiles/homework3.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/UCI_MCS/238P/homework3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/homework3.dir/main.c.o"
	/usr/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/homework3.dir/main.c.o   -c /cygdrive/d/UCI_MCS/238P/homework3/main.c

CMakeFiles/homework3.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/homework3.dir/main.c.i"
	/usr/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/d/UCI_MCS/238P/homework3/main.c > CMakeFiles/homework3.dir/main.c.i

CMakeFiles/homework3.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/homework3.dir/main.c.s"
	/usr/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/d/UCI_MCS/238P/homework3/main.c -o CMakeFiles/homework3.dir/main.c.s

# Object files for target homework3
homework3_OBJECTS = \
"CMakeFiles/homework3.dir/main.c.o"

# External object files for target homework3
homework3_EXTERNAL_OBJECTS =

homework3.exe: CMakeFiles/homework3.dir/main.c.o
homework3.exe: CMakeFiles/homework3.dir/build.make
homework3.exe: CMakeFiles/homework3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/d/UCI_MCS/238P/homework3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable homework3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/homework3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/homework3.dir/build: homework3.exe

.PHONY : CMakeFiles/homework3.dir/build

CMakeFiles/homework3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/homework3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/homework3.dir/clean

CMakeFiles/homework3.dir/depend:
	cd /cygdrive/d/UCI_MCS/238P/homework3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/d/UCI_MCS/238P/homework3 /cygdrive/d/UCI_MCS/238P/homework3 /cygdrive/d/UCI_MCS/238P/homework3/cmake-build-debug /cygdrive/d/UCI_MCS/238P/homework3/cmake-build-debug /cygdrive/d/UCI_MCS/238P/homework3/cmake-build-debug/CMakeFiles/homework3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/homework3.dir/depend

