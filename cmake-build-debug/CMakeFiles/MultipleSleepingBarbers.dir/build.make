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
CMAKE_COMMAND = /cygdrive/c/Users/John/AppData/Local/JetBrains/CLion2020.1/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/John/AppData/Local/JetBrains/CLion2020.1/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/John/Desktop/CLionProjects/MultipleSleepingBarbers

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/John/Desktop/CLionProjects/MultipleSleepingBarbers/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MultipleSleepingBarbers.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MultipleSleepingBarbers.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MultipleSleepingBarbers.dir/flags.make

CMakeFiles/MultipleSleepingBarbers.dir/main.cpp.o: CMakeFiles/MultipleSleepingBarbers.dir/flags.make
CMakeFiles/MultipleSleepingBarbers.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/John/Desktop/CLionProjects/MultipleSleepingBarbers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MultipleSleepingBarbers.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MultipleSleepingBarbers.dir/main.cpp.o -c /cygdrive/c/Users/John/Desktop/CLionProjects/MultipleSleepingBarbers/main.cpp

CMakeFiles/MultipleSleepingBarbers.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MultipleSleepingBarbers.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/John/Desktop/CLionProjects/MultipleSleepingBarbers/main.cpp > CMakeFiles/MultipleSleepingBarbers.dir/main.cpp.i

CMakeFiles/MultipleSleepingBarbers.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MultipleSleepingBarbers.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/John/Desktop/CLionProjects/MultipleSleepingBarbers/main.cpp -o CMakeFiles/MultipleSleepingBarbers.dir/main.cpp.s

CMakeFiles/MultipleSleepingBarbers.dir/Shop_org.cpp.o: CMakeFiles/MultipleSleepingBarbers.dir/flags.make
CMakeFiles/MultipleSleepingBarbers.dir/Shop_org.cpp.o: ../Shop_org.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/John/Desktop/CLionProjects/MultipleSleepingBarbers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MultipleSleepingBarbers.dir/Shop_org.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MultipleSleepingBarbers.dir/Shop_org.cpp.o -c /cygdrive/c/Users/John/Desktop/CLionProjects/MultipleSleepingBarbers/Shop_org.cpp

CMakeFiles/MultipleSleepingBarbers.dir/Shop_org.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MultipleSleepingBarbers.dir/Shop_org.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/John/Desktop/CLionProjects/MultipleSleepingBarbers/Shop_org.cpp > CMakeFiles/MultipleSleepingBarbers.dir/Shop_org.cpp.i

CMakeFiles/MultipleSleepingBarbers.dir/Shop_org.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MultipleSleepingBarbers.dir/Shop_org.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/John/Desktop/CLionProjects/MultipleSleepingBarbers/Shop_org.cpp -o CMakeFiles/MultipleSleepingBarbers.dir/Shop_org.cpp.s

# Object files for target MultipleSleepingBarbers
MultipleSleepingBarbers_OBJECTS = \
"CMakeFiles/MultipleSleepingBarbers.dir/main.cpp.o" \
"CMakeFiles/MultipleSleepingBarbers.dir/Shop_org.cpp.o"

# External object files for target MultipleSleepingBarbers
MultipleSleepingBarbers_EXTERNAL_OBJECTS =

MultipleSleepingBarbers.exe: CMakeFiles/MultipleSleepingBarbers.dir/main.cpp.o
MultipleSleepingBarbers.exe: CMakeFiles/MultipleSleepingBarbers.dir/Shop_org.cpp.o
MultipleSleepingBarbers.exe: CMakeFiles/MultipleSleepingBarbers.dir/build.make
MultipleSleepingBarbers.exe: CMakeFiles/MultipleSleepingBarbers.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/John/Desktop/CLionProjects/MultipleSleepingBarbers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable MultipleSleepingBarbers.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MultipleSleepingBarbers.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MultipleSleepingBarbers.dir/build: MultipleSleepingBarbers.exe

.PHONY : CMakeFiles/MultipleSleepingBarbers.dir/build

CMakeFiles/MultipleSleepingBarbers.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MultipleSleepingBarbers.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MultipleSleepingBarbers.dir/clean

CMakeFiles/MultipleSleepingBarbers.dir/depend:
	cd /cygdrive/c/Users/John/Desktop/CLionProjects/MultipleSleepingBarbers/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/John/Desktop/CLionProjects/MultipleSleepingBarbers /cygdrive/c/Users/John/Desktop/CLionProjects/MultipleSleepingBarbers /cygdrive/c/Users/John/Desktop/CLionProjects/MultipleSleepingBarbers/cmake-build-debug /cygdrive/c/Users/John/Desktop/CLionProjects/MultipleSleepingBarbers/cmake-build-debug /cygdrive/c/Users/John/Desktop/CLionProjects/MultipleSleepingBarbers/cmake-build-debug/CMakeFiles/MultipleSleepingBarbers.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MultipleSleepingBarbers.dir/depend

