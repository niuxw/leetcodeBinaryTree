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
CMAKE_SOURCE_DIR = /Users/xiangweiniu/Documents/Alltree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/xiangweiniu/Documents/Alltree/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Alltree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Alltree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Alltree.dir/flags.make

CMakeFiles/Alltree.dir/main.cpp.o: CMakeFiles/Alltree.dir/flags.make
CMakeFiles/Alltree.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xiangweiniu/Documents/Alltree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Alltree.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Alltree.dir/main.cpp.o -c /Users/xiangweiniu/Documents/Alltree/main.cpp

CMakeFiles/Alltree.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Alltree.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xiangweiniu/Documents/Alltree/main.cpp > CMakeFiles/Alltree.dir/main.cpp.i

CMakeFiles/Alltree.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Alltree.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xiangweiniu/Documents/Alltree/main.cpp -o CMakeFiles/Alltree.dir/main.cpp.s

# Object files for target Alltree
Alltree_OBJECTS = \
"CMakeFiles/Alltree.dir/main.cpp.o"

# External object files for target Alltree
Alltree_EXTERNAL_OBJECTS =

Alltree: CMakeFiles/Alltree.dir/main.cpp.o
Alltree: CMakeFiles/Alltree.dir/build.make
Alltree: CMakeFiles/Alltree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/xiangweiniu/Documents/Alltree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Alltree"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Alltree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Alltree.dir/build: Alltree

.PHONY : CMakeFiles/Alltree.dir/build

CMakeFiles/Alltree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Alltree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Alltree.dir/clean

CMakeFiles/Alltree.dir/depend:
	cd /Users/xiangweiniu/Documents/Alltree/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/xiangweiniu/Documents/Alltree /Users/xiangweiniu/Documents/Alltree /Users/xiangweiniu/Documents/Alltree/cmake-build-debug /Users/xiangweiniu/Documents/Alltree/cmake-build-debug /Users/xiangweiniu/Documents/Alltree/cmake-build-debug/CMakeFiles/Alltree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Alltree.dir/depend
