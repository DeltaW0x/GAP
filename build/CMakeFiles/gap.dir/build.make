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
CMAKE_SOURCE_DIR = /home/delta/proto

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/delta/proto/build

# Include any dependencies generated for this target.
include CMakeFiles/gap.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gap.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gap.dir/flags.make

CMakeFiles/gap.dir/src/main.cpp.o: CMakeFiles/gap.dir/flags.make
CMakeFiles/gap.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/delta/proto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gap.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gap.dir/src/main.cpp.o -c /home/delta/proto/src/main.cpp

CMakeFiles/gap.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gap.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/delta/proto/src/main.cpp > CMakeFiles/gap.dir/src/main.cpp.i

CMakeFiles/gap.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gap.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/delta/proto/src/main.cpp -o CMakeFiles/gap.dir/src/main.cpp.s

# Object files for target gap
gap_OBJECTS = \
"CMakeFiles/gap.dir/src/main.cpp.o"

# External object files for target gap
gap_EXTERNAL_OBJECTS =

gap: CMakeFiles/gap.dir/src/main.cpp.o
gap: CMakeFiles/gap.dir/build.make
gap: CMakeFiles/gap.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/delta/proto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable gap"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gap.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gap.dir/build: gap

.PHONY : CMakeFiles/gap.dir/build

CMakeFiles/gap.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gap.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gap.dir/clean

CMakeFiles/gap.dir/depend:
	cd /home/delta/proto/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/delta/proto /home/delta/proto /home/delta/proto/build /home/delta/proto/build /home/delta/proto/build/CMakeFiles/gap.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gap.dir/depend

