# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/nnigam1/CLionProjects/StringDS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/nnigam1/CLionProjects/StringDS/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/StringDS.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/StringDS.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/StringDS.dir/flags.make

CMakeFiles/StringDS.dir/main.cpp.o: CMakeFiles/StringDS.dir/flags.make
CMakeFiles/StringDS.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nnigam1/CLionProjects/StringDS/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/StringDS.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/StringDS.dir/main.cpp.o -c /Users/nnigam1/CLionProjects/StringDS/main.cpp

CMakeFiles/StringDS.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StringDS.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nnigam1/CLionProjects/StringDS/main.cpp > CMakeFiles/StringDS.dir/main.cpp.i

CMakeFiles/StringDS.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StringDS.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nnigam1/CLionProjects/StringDS/main.cpp -o CMakeFiles/StringDS.dir/main.cpp.s

# Object files for target StringDS
StringDS_OBJECTS = \
"CMakeFiles/StringDS.dir/main.cpp.o"

# External object files for target StringDS
StringDS_EXTERNAL_OBJECTS =

StringDS: CMakeFiles/StringDS.dir/main.cpp.o
StringDS: CMakeFiles/StringDS.dir/build.make
StringDS: CMakeFiles/StringDS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/nnigam1/CLionProjects/StringDS/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable StringDS"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/StringDS.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/StringDS.dir/build: StringDS

.PHONY : CMakeFiles/StringDS.dir/build

CMakeFiles/StringDS.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/StringDS.dir/cmake_clean.cmake
.PHONY : CMakeFiles/StringDS.dir/clean

CMakeFiles/StringDS.dir/depend:
	cd /Users/nnigam1/CLionProjects/StringDS/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/nnigam1/CLionProjects/StringDS /Users/nnigam1/CLionProjects/StringDS /Users/nnigam1/CLionProjects/StringDS/cmake-build-debug /Users/nnigam1/CLionProjects/StringDS/cmake-build-debug /Users/nnigam1/CLionProjects/StringDS/cmake-build-debug/CMakeFiles/StringDS.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/StringDS.dir/depend

