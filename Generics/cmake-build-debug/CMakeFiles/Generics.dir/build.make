# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.6

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\JetBrains\CLion 2016.3.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\JetBrains\CLion 2016.3.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\drake\Repositories\cs1440\Generics

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\drake\Repositories\cs1440\Generics\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Generics.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Generics.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Generics.dir/flags.make

CMakeFiles/Generics.dir/main.cpp.obj: CMakeFiles/Generics.dir/flags.make
CMakeFiles/Generics.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\drake\Repositories\cs1440\Generics\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Generics.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-6~1.0-P\mingw32\bin\G__~1.EXE   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Generics.dir\main.cpp.obj -c C:\Users\drake\Repositories\cs1440\Generics\main.cpp

CMakeFiles/Generics.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Generics.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-6~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\drake\Repositories\cs1440\Generics\main.cpp > CMakeFiles\Generics.dir\main.cpp.i

CMakeFiles/Generics.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Generics.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-6~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\drake\Repositories\cs1440\Generics\main.cpp -o CMakeFiles\Generics.dir\main.cpp.s

CMakeFiles/Generics.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/Generics.dir/main.cpp.obj.requires

CMakeFiles/Generics.dir/main.cpp.obj.provides: CMakeFiles/Generics.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Generics.dir\build.make CMakeFiles/Generics.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/Generics.dir/main.cpp.obj.provides

CMakeFiles/Generics.dir/main.cpp.obj.provides.build: CMakeFiles/Generics.dir/main.cpp.obj


# Object files for target Generics
Generics_OBJECTS = \
"CMakeFiles/Generics.dir/main.cpp.obj"

# External object files for target Generics
Generics_EXTERNAL_OBJECTS =

Generics.exe: CMakeFiles/Generics.dir/main.cpp.obj
Generics.exe: CMakeFiles/Generics.dir/build.make
Generics.exe: CMakeFiles/Generics.dir/linklibs.rsp
Generics.exe: CMakeFiles/Generics.dir/objects1.rsp
Generics.exe: CMakeFiles/Generics.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\drake\Repositories\cs1440\Generics\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Generics.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Generics.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Generics.dir/build: Generics.exe

.PHONY : CMakeFiles/Generics.dir/build

CMakeFiles/Generics.dir/requires: CMakeFiles/Generics.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/Generics.dir/requires

CMakeFiles/Generics.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Generics.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Generics.dir/clean

CMakeFiles/Generics.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\drake\Repositories\cs1440\Generics C:\Users\drake\Repositories\cs1440\Generics C:\Users\drake\Repositories\cs1440\Generics\cmake-build-debug C:\Users\drake\Repositories\cs1440\Generics\cmake-build-debug C:\Users\drake\Repositories\cs1440\Generics\cmake-build-debug\CMakeFiles\Generics.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Generics.dir/depend

