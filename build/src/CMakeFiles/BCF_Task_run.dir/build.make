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
CMAKE_SOURCE_DIR = /mnt/d/_programowanie/BCF_task

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/_programowanie/BCF_task/build

# Include any dependencies generated for this target.
include src/CMakeFiles/BCF_Task_run.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/BCF_Task_run.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/BCF_Task_run.dir/flags.make

src/CMakeFiles/BCF_Task_run.dir/main.cpp.o: src/CMakeFiles/BCF_Task_run.dir/flags.make
src/CMakeFiles/BCF_Task_run.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/_programowanie/BCF_task/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/BCF_Task_run.dir/main.cpp.o"
	cd /mnt/d/_programowanie/BCF_task/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BCF_Task_run.dir/main.cpp.o -c /mnt/d/_programowanie/BCF_task/src/main.cpp

src/CMakeFiles/BCF_Task_run.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BCF_Task_run.dir/main.cpp.i"
	cd /mnt/d/_programowanie/BCF_task/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/_programowanie/BCF_task/src/main.cpp > CMakeFiles/BCF_Task_run.dir/main.cpp.i

src/CMakeFiles/BCF_Task_run.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BCF_Task_run.dir/main.cpp.s"
	cd /mnt/d/_programowanie/BCF_task/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/_programowanie/BCF_task/src/main.cpp -o CMakeFiles/BCF_Task_run.dir/main.cpp.s

# Object files for target BCF_Task_run
BCF_Task_run_OBJECTS = \
"CMakeFiles/BCF_Task_run.dir/main.cpp.o"

# External object files for target BCF_Task_run
BCF_Task_run_EXTERNAL_OBJECTS =

src/BCF_Task_run: src/CMakeFiles/BCF_Task_run.dir/main.cpp.o
src/BCF_Task_run: src/CMakeFiles/BCF_Task_run.dir/build.make
src/BCF_Task_run: src/CMakeFiles/BCF_Task_run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/_programowanie/BCF_task/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BCF_Task_run"
	cd /mnt/d/_programowanie/BCF_task/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BCF_Task_run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/BCF_Task_run.dir/build: src/BCF_Task_run

.PHONY : src/CMakeFiles/BCF_Task_run.dir/build

src/CMakeFiles/BCF_Task_run.dir/clean:
	cd /mnt/d/_programowanie/BCF_task/build/src && $(CMAKE_COMMAND) -P CMakeFiles/BCF_Task_run.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/BCF_Task_run.dir/clean

src/CMakeFiles/BCF_Task_run.dir/depend:
	cd /mnt/d/_programowanie/BCF_task/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/_programowanie/BCF_task /mnt/d/_programowanie/BCF_task/src /mnt/d/_programowanie/BCF_task/build /mnt/d/_programowanie/BCF_task/build/src /mnt/d/_programowanie/BCF_task/build/src/CMakeFiles/BCF_Task_run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/BCF_Task_run.dir/depend
