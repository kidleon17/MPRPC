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
CMAKE_SOURCE_DIR = /home/kidleon/桌面/MPRPC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kidleon/桌面/MPRPC/build

# Include any dependencies generated for this target.
include example/Callee/CMakeFiles/provider.dir/depend.make

# Include the progress variables for this target.
include example/Callee/CMakeFiles/provider.dir/progress.make

# Include the compile flags for this target's objects.
include example/Callee/CMakeFiles/provider.dir/flags.make

example/Callee/CMakeFiles/provider.dir/friendservice.cc.o: example/Callee/CMakeFiles/provider.dir/flags.make
example/Callee/CMakeFiles/provider.dir/friendservice.cc.o: ../example/Callee/friendservice.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kidleon/桌面/MPRPC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object example/Callee/CMakeFiles/provider.dir/friendservice.cc.o"
	cd /home/kidleon/桌面/MPRPC/build/example/Callee && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/provider.dir/friendservice.cc.o -c /home/kidleon/桌面/MPRPC/example/Callee/friendservice.cc

example/Callee/CMakeFiles/provider.dir/friendservice.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/provider.dir/friendservice.cc.i"
	cd /home/kidleon/桌面/MPRPC/build/example/Callee && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kidleon/桌面/MPRPC/example/Callee/friendservice.cc > CMakeFiles/provider.dir/friendservice.cc.i

example/Callee/CMakeFiles/provider.dir/friendservice.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/provider.dir/friendservice.cc.s"
	cd /home/kidleon/桌面/MPRPC/build/example/Callee && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kidleon/桌面/MPRPC/example/Callee/friendservice.cc -o CMakeFiles/provider.dir/friendservice.cc.s

example/Callee/CMakeFiles/provider.dir/friendservice.cc.o.requires:

.PHONY : example/Callee/CMakeFiles/provider.dir/friendservice.cc.o.requires

example/Callee/CMakeFiles/provider.dir/friendservice.cc.o.provides: example/Callee/CMakeFiles/provider.dir/friendservice.cc.o.requires
	$(MAKE) -f example/Callee/CMakeFiles/provider.dir/build.make example/Callee/CMakeFiles/provider.dir/friendservice.cc.o.provides.build
.PHONY : example/Callee/CMakeFiles/provider.dir/friendservice.cc.o.provides

example/Callee/CMakeFiles/provider.dir/friendservice.cc.o.provides.build: example/Callee/CMakeFiles/provider.dir/friendservice.cc.o


example/Callee/CMakeFiles/provider.dir/__/friend.pb.cc.o: example/Callee/CMakeFiles/provider.dir/flags.make
example/Callee/CMakeFiles/provider.dir/__/friend.pb.cc.o: ../example/friend.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kidleon/桌面/MPRPC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object example/Callee/CMakeFiles/provider.dir/__/friend.pb.cc.o"
	cd /home/kidleon/桌面/MPRPC/build/example/Callee && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/provider.dir/__/friend.pb.cc.o -c /home/kidleon/桌面/MPRPC/example/friend.pb.cc

example/Callee/CMakeFiles/provider.dir/__/friend.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/provider.dir/__/friend.pb.cc.i"
	cd /home/kidleon/桌面/MPRPC/build/example/Callee && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kidleon/桌面/MPRPC/example/friend.pb.cc > CMakeFiles/provider.dir/__/friend.pb.cc.i

example/Callee/CMakeFiles/provider.dir/__/friend.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/provider.dir/__/friend.pb.cc.s"
	cd /home/kidleon/桌面/MPRPC/build/example/Callee && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kidleon/桌面/MPRPC/example/friend.pb.cc -o CMakeFiles/provider.dir/__/friend.pb.cc.s

example/Callee/CMakeFiles/provider.dir/__/friend.pb.cc.o.requires:

.PHONY : example/Callee/CMakeFiles/provider.dir/__/friend.pb.cc.o.requires

example/Callee/CMakeFiles/provider.dir/__/friend.pb.cc.o.provides: example/Callee/CMakeFiles/provider.dir/__/friend.pb.cc.o.requires
	$(MAKE) -f example/Callee/CMakeFiles/provider.dir/build.make example/Callee/CMakeFiles/provider.dir/__/friend.pb.cc.o.provides.build
.PHONY : example/Callee/CMakeFiles/provider.dir/__/friend.pb.cc.o.provides

example/Callee/CMakeFiles/provider.dir/__/friend.pb.cc.o.provides.build: example/Callee/CMakeFiles/provider.dir/__/friend.pb.cc.o


# Object files for target provider
provider_OBJECTS = \
"CMakeFiles/provider.dir/friendservice.cc.o" \
"CMakeFiles/provider.dir/__/friend.pb.cc.o"

# External object files for target provider
provider_EXTERNAL_OBJECTS =

../bin/provider: example/Callee/CMakeFiles/provider.dir/friendservice.cc.o
../bin/provider: example/Callee/CMakeFiles/provider.dir/__/friend.pb.cc.o
../bin/provider: example/Callee/CMakeFiles/provider.dir/build.make
../bin/provider: ../lib/libmprpc.a
../bin/provider: example/Callee/CMakeFiles/provider.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kidleon/桌面/MPRPC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../../bin/provider"
	cd /home/kidleon/桌面/MPRPC/build/example/Callee && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/provider.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
example/Callee/CMakeFiles/provider.dir/build: ../bin/provider

.PHONY : example/Callee/CMakeFiles/provider.dir/build

example/Callee/CMakeFiles/provider.dir/requires: example/Callee/CMakeFiles/provider.dir/friendservice.cc.o.requires
example/Callee/CMakeFiles/provider.dir/requires: example/Callee/CMakeFiles/provider.dir/__/friend.pb.cc.o.requires

.PHONY : example/Callee/CMakeFiles/provider.dir/requires

example/Callee/CMakeFiles/provider.dir/clean:
	cd /home/kidleon/桌面/MPRPC/build/example/Callee && $(CMAKE_COMMAND) -P CMakeFiles/provider.dir/cmake_clean.cmake
.PHONY : example/Callee/CMakeFiles/provider.dir/clean

example/Callee/CMakeFiles/provider.dir/depend:
	cd /home/kidleon/桌面/MPRPC/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kidleon/桌面/MPRPC /home/kidleon/桌面/MPRPC/example/Callee /home/kidleon/桌面/MPRPC/build /home/kidleon/桌面/MPRPC/build/example/Callee /home/kidleon/桌面/MPRPC/build/example/Callee/CMakeFiles/provider.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : example/Callee/CMakeFiles/provider.dir/depend

