# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/mk/work/algorithm/AOJ/ZIMBABWE/memoization

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mk/work/algorithm/AOJ/ZIMBABWE/memoization

# Include any dependencies generated for this target.
include CMakeFiles/foo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/foo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/foo.dir/flags.make

CMakeFiles/foo.dir/main.cpp.o: CMakeFiles/foo.dir/flags.make
CMakeFiles/foo.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mk/work/algorithm/AOJ/ZIMBABWE/memoization/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/foo.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/foo.dir/main.cpp.o -c /home/mk/work/algorithm/AOJ/ZIMBABWE/memoization/main.cpp

CMakeFiles/foo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/foo.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mk/work/algorithm/AOJ/ZIMBABWE/memoization/main.cpp > CMakeFiles/foo.dir/main.cpp.i

CMakeFiles/foo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/foo.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mk/work/algorithm/AOJ/ZIMBABWE/memoization/main.cpp -o CMakeFiles/foo.dir/main.cpp.s

CMakeFiles/foo.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/foo.dir/main.cpp.o.requires

CMakeFiles/foo.dir/main.cpp.o.provides: CMakeFiles/foo.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/foo.dir/build.make CMakeFiles/foo.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/foo.dir/main.cpp.o.provides

CMakeFiles/foo.dir/main.cpp.o.provides.build: CMakeFiles/foo.dir/main.cpp.o


# Object files for target foo
foo_OBJECTS = \
"CMakeFiles/foo.dir/main.cpp.o"

# External object files for target foo
foo_EXTERNAL_OBJECTS =

foo: CMakeFiles/foo.dir/main.cpp.o
foo: CMakeFiles/foo.dir/build.make
foo: CMakeFiles/foo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mk/work/algorithm/AOJ/ZIMBABWE/memoization/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable foo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/foo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/foo.dir/build: foo

.PHONY : CMakeFiles/foo.dir/build

CMakeFiles/foo.dir/requires: CMakeFiles/foo.dir/main.cpp.o.requires

.PHONY : CMakeFiles/foo.dir/requires

CMakeFiles/foo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/foo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/foo.dir/clean

CMakeFiles/foo.dir/depend:
	cd /home/mk/work/algorithm/AOJ/ZIMBABWE/memoization && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mk/work/algorithm/AOJ/ZIMBABWE/memoization /home/mk/work/algorithm/AOJ/ZIMBABWE/memoization /home/mk/work/algorithm/AOJ/ZIMBABWE/memoization /home/mk/work/algorithm/AOJ/ZIMBABWE/memoization /home/mk/work/algorithm/AOJ/ZIMBABWE/memoization/CMakeFiles/foo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/foo.dir/depend

