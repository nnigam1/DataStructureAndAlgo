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
CMAKE_SOURCE_DIR = /Users/nnigam1/CLionProjects/SingleServerNeed

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/nnigam1/CLionProjects/SingleServerNeed/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AtlassianProj.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AtlassianProj.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AtlassianProj.dir/flags.make

CMakeFiles/AtlassianProj.dir/RateLimiter2.cpp.o: CMakeFiles/AtlassianProj.dir/flags.make
CMakeFiles/AtlassianProj.dir/RateLimiter2.cpp.o: ../RateLimiter2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nnigam1/CLionProjects/SingleServerNeed/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AtlassianProj.dir/RateLimiter2.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AtlassianProj.dir/RateLimiter2.cpp.o -c /Users/nnigam1/CLionProjects/SingleServerNeed/RateLimiter2.cpp

CMakeFiles/AtlassianProj.dir/RateLimiter2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AtlassianProj.dir/RateLimiter2.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nnigam1/CLionProjects/SingleServerNeed/RateLimiter2.cpp > CMakeFiles/AtlassianProj.dir/RateLimiter2.cpp.i

CMakeFiles/AtlassianProj.dir/RateLimiter2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AtlassianProj.dir/RateLimiter2.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nnigam1/CLionProjects/SingleServerNeed/RateLimiter2.cpp -o CMakeFiles/AtlassianProj.dir/RateLimiter2.cpp.s

# Object files for target AtlassianProj
AtlassianProj_OBJECTS = \
"CMakeFiles/AtlassianProj.dir/RateLimiter2.cpp.o"

# External object files for target AtlassianProj
AtlassianProj_EXTERNAL_OBJECTS =

AtlassianProj: CMakeFiles/AtlassianProj.dir/RateLimiter2.cpp.o
AtlassianProj: CMakeFiles/AtlassianProj.dir/build.make
AtlassianProj: CMakeFiles/AtlassianProj.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/nnigam1/CLionProjects/SingleServerNeed/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable AtlassianProj"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AtlassianProj.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AtlassianProj.dir/build: AtlassianProj

.PHONY : CMakeFiles/AtlassianProj.dir/build

CMakeFiles/AtlassianProj.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AtlassianProj.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AtlassianProj.dir/clean

CMakeFiles/AtlassianProj.dir/depend:
	cd /Users/nnigam1/CLionProjects/SingleServerNeed/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/nnigam1/CLionProjects/SingleServerNeed /Users/nnigam1/CLionProjects/SingleServerNeed /Users/nnigam1/CLionProjects/SingleServerNeed/cmake-build-debug /Users/nnigam1/CLionProjects/SingleServerNeed/cmake-build-debug /Users/nnigam1/CLionProjects/SingleServerNeed/cmake-build-debug/CMakeFiles/AtlassianProj.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AtlassianProj.dir/depend

