# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\projects\graphics\Cazel

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\projects\graphics\Cazel\cmake-build-release

# Include any dependencies generated for this target.
include lib/cazel/lib/glfw/tests/CMakeFiles/tearing.dir/depend.make

# Include the progress variables for this target.
include lib/cazel/lib/glfw/tests/CMakeFiles/tearing.dir/progress.make

# Include the compile flags for this target's objects.
include lib/cazel/lib/glfw/tests/CMakeFiles/tearing.dir/flags.make

lib/cazel/lib/glfw/tests/CMakeFiles/tearing.dir/tearing.c.obj: lib/cazel/lib/glfw/tests/CMakeFiles/tearing.dir/flags.make
lib/cazel/lib/glfw/tests/CMakeFiles/tearing.dir/tearing.c.obj: lib/cazel/lib/glfw/tests/CMakeFiles/tearing.dir/includes_C.rsp
lib/cazel/lib/glfw/tests/CMakeFiles/tearing.dir/tearing.c.obj: ../lib/cazel/lib/glfw/tests/tearing.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\projects\graphics\Cazel\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/cazel/lib/glfw/tests/CMakeFiles/tearing.dir/tearing.c.obj"
	cd /d C:\projects\graphics\Cazel\cmake-build-release\lib\cazel\lib\glfw\tests && C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\tearing.dir\tearing.c.obj   -c C:\projects\graphics\Cazel\lib\cazel\lib\glfw\tests\tearing.c

lib/cazel/lib/glfw/tests/CMakeFiles/tearing.dir/tearing.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tearing.dir/tearing.c.i"
	cd /d C:\projects\graphics\Cazel\cmake-build-release\lib\cazel\lib\glfw\tests && C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\projects\graphics\Cazel\lib\cazel\lib\glfw\tests\tearing.c > CMakeFiles\tearing.dir\tearing.c.i

lib/cazel/lib/glfw/tests/CMakeFiles/tearing.dir/tearing.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tearing.dir/tearing.c.s"
	cd /d C:\projects\graphics\Cazel\cmake-build-release\lib\cazel\lib\glfw\tests && C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\projects\graphics\Cazel\lib\cazel\lib\glfw\tests\tearing.c -o CMakeFiles\tearing.dir\tearing.c.s

lib/cazel/lib/glfw/tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.obj: lib/cazel/lib/glfw/tests/CMakeFiles/tearing.dir/flags.make
lib/cazel/lib/glfw/tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.obj: lib/cazel/lib/glfw/tests/CMakeFiles/tearing.dir/includes_C.rsp
lib/cazel/lib/glfw/tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.obj: ../lib/cazel/lib/glfw/deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\projects\graphics\Cazel\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object lib/cazel/lib/glfw/tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.obj"
	cd /d C:\projects\graphics\Cazel\cmake-build-release\lib\cazel\lib\glfw\tests && C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\tearing.dir\__\deps\glad_gl.c.obj   -c C:\projects\graphics\Cazel\lib\cazel\lib\glfw\deps\glad_gl.c

lib/cazel/lib/glfw/tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tearing.dir/__/deps/glad_gl.c.i"
	cd /d C:\projects\graphics\Cazel\cmake-build-release\lib\cazel\lib\glfw\tests && C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\projects\graphics\Cazel\lib\cazel\lib\glfw\deps\glad_gl.c > CMakeFiles\tearing.dir\__\deps\glad_gl.c.i

lib/cazel/lib/glfw/tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tearing.dir/__/deps/glad_gl.c.s"
	cd /d C:\projects\graphics\Cazel\cmake-build-release\lib\cazel\lib\glfw\tests && C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\projects\graphics\Cazel\lib\cazel\lib\glfw\deps\glad_gl.c -o CMakeFiles\tearing.dir\__\deps\glad_gl.c.s

# Object files for target tearing
tearing_OBJECTS = \
"CMakeFiles/tearing.dir/tearing.c.obj" \
"CMakeFiles/tearing.dir/__/deps/glad_gl.c.obj"

# External object files for target tearing
tearing_EXTERNAL_OBJECTS =

lib/cazel/lib/glfw/tests/tearing.exe: lib/cazel/lib/glfw/tests/CMakeFiles/tearing.dir/tearing.c.obj
lib/cazel/lib/glfw/tests/tearing.exe: lib/cazel/lib/glfw/tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.obj
lib/cazel/lib/glfw/tests/tearing.exe: lib/cazel/lib/glfw/tests/CMakeFiles/tearing.dir/build.make
lib/cazel/lib/glfw/tests/tearing.exe: lib/cazel/lib/glfw/src/libglfw3.a
lib/cazel/lib/glfw/tests/tearing.exe: lib/cazel/lib/glfw/tests/CMakeFiles/tearing.dir/linklibs.rsp
lib/cazel/lib/glfw/tests/tearing.exe: lib/cazel/lib/glfw/tests/CMakeFiles/tearing.dir/objects1.rsp
lib/cazel/lib/glfw/tests/tearing.exe: lib/cazel/lib/glfw/tests/CMakeFiles/tearing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\projects\graphics\Cazel\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable tearing.exe"
	cd /d C:\projects\graphics\Cazel\cmake-build-release\lib\cazel\lib\glfw\tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\tearing.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/cazel/lib/glfw/tests/CMakeFiles/tearing.dir/build: lib/cazel/lib/glfw/tests/tearing.exe

.PHONY : lib/cazel/lib/glfw/tests/CMakeFiles/tearing.dir/build

lib/cazel/lib/glfw/tests/CMakeFiles/tearing.dir/clean:
	cd /d C:\projects\graphics\Cazel\cmake-build-release\lib\cazel\lib\glfw\tests && $(CMAKE_COMMAND) -P CMakeFiles\tearing.dir\cmake_clean.cmake
.PHONY : lib/cazel/lib/glfw/tests/CMakeFiles/tearing.dir/clean

lib/cazel/lib/glfw/tests/CMakeFiles/tearing.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\projects\graphics\Cazel C:\projects\graphics\Cazel\lib\cazel\lib\glfw\tests C:\projects\graphics\Cazel\cmake-build-release C:\projects\graphics\Cazel\cmake-build-release\lib\cazel\lib\glfw\tests C:\projects\graphics\Cazel\cmake-build-release\lib\cazel\lib\glfw\tests\CMakeFiles\tearing.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : lib/cazel/lib/glfw/tests/CMakeFiles/tearing.dir/depend

