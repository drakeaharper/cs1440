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
include CMakeFiles/Dictionary.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Dictionary.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Dictionary.dir/flags.make

CMakeFiles/Dictionary.dir/main.cpp.obj: CMakeFiles/Dictionary.dir/flags.make
CMakeFiles/Dictionary.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\drake\Repositories\cs1440\Generics\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Dictionary.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-6~1.0-P\mingw32\bin\G__~1.EXE   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Dictionary.dir\main.cpp.obj -c C:\Users\drake\Repositories\cs1440\Generics\main.cpp

CMakeFiles/Dictionary.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Dictionary.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-6~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\drake\Repositories\cs1440\Generics\main.cpp > CMakeFiles\Dictionary.dir\main.cpp.i

CMakeFiles/Dictionary.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Dictionary.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-6~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\drake\Repositories\cs1440\Generics\main.cpp -o CMakeFiles\Dictionary.dir\main.cpp.s

CMakeFiles/Dictionary.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/Dictionary.dir/main.cpp.obj.requires

CMakeFiles/Dictionary.dir/main.cpp.obj.provides: CMakeFiles/Dictionary.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Dictionary.dir\build.make CMakeFiles/Dictionary.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/Dictionary.dir/main.cpp.obj.provides

CMakeFiles/Dictionary.dir/main.cpp.obj.provides.build: CMakeFiles/Dictionary.dir/main.cpp.obj


CMakeFiles/Dictionary.dir/UserInterface.cpp.obj: CMakeFiles/Dictionary.dir/flags.make
CMakeFiles/Dictionary.dir/UserInterface.cpp.obj: ../UserInterface.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\drake\Repositories\cs1440\Generics\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Dictionary.dir/UserInterface.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-6~1.0-P\mingw32\bin\G__~1.EXE   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Dictionary.dir\UserInterface.cpp.obj -c C:\Users\drake\Repositories\cs1440\Generics\UserInterface.cpp

CMakeFiles/Dictionary.dir/UserInterface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Dictionary.dir/UserInterface.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-6~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\drake\Repositories\cs1440\Generics\UserInterface.cpp > CMakeFiles\Dictionary.dir\UserInterface.cpp.i

CMakeFiles/Dictionary.dir/UserInterface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Dictionary.dir/UserInterface.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-6~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\drake\Repositories\cs1440\Generics\UserInterface.cpp -o CMakeFiles\Dictionary.dir\UserInterface.cpp.s

CMakeFiles/Dictionary.dir/UserInterface.cpp.obj.requires:

.PHONY : CMakeFiles/Dictionary.dir/UserInterface.cpp.obj.requires

CMakeFiles/Dictionary.dir/UserInterface.cpp.obj.provides: CMakeFiles/Dictionary.dir/UserInterface.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Dictionary.dir\build.make CMakeFiles/Dictionary.dir/UserInterface.cpp.obj.provides.build
.PHONY : CMakeFiles/Dictionary.dir/UserInterface.cpp.obj.provides

CMakeFiles/Dictionary.dir/UserInterface.cpp.obj.provides.build: CMakeFiles/Dictionary.dir/UserInterface.cpp.obj


# Object files for target Dictionary
Dictionary_OBJECTS = \
"CMakeFiles/Dictionary.dir/main.cpp.obj" \
"CMakeFiles/Dictionary.dir/UserInterface.cpp.obj"

# External object files for target Dictionary
Dictionary_EXTERNAL_OBJECTS =

Dictionary.exe: CMakeFiles/Dictionary.dir/main.cpp.obj
Dictionary.exe: CMakeFiles/Dictionary.dir/UserInterface.cpp.obj
Dictionary.exe: CMakeFiles/Dictionary.dir/build.make
Dictionary.exe: CMakeFiles/Dictionary.dir/linklibs.rsp
Dictionary.exe: CMakeFiles/Dictionary.dir/objects1.rsp
Dictionary.exe: CMakeFiles/Dictionary.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\drake\Repositories\cs1440\Generics\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Dictionary.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Dictionary.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Dictionary.dir/build: Dictionary.exe

.PHONY : CMakeFiles/Dictionary.dir/build

CMakeFiles/Dictionary.dir/requires: CMakeFiles/Dictionary.dir/main.cpp.obj.requires
CMakeFiles/Dictionary.dir/requires: CMakeFiles/Dictionary.dir/UserInterface.cpp.obj.requires

.PHONY : CMakeFiles/Dictionary.dir/requires

CMakeFiles/Dictionary.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Dictionary.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Dictionary.dir/clean

CMakeFiles/Dictionary.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\drake\Repositories\cs1440\Generics C:\Users\drake\Repositories\cs1440\Generics C:\Users\drake\Repositories\cs1440\Generics\cmake-build-debug C:\Users\drake\Repositories\cs1440\Generics\cmake-build-debug C:\Users\drake\Repositories\cs1440\Generics\cmake-build-debug\CMakeFiles\Dictionary.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Dictionary.dir/depend

