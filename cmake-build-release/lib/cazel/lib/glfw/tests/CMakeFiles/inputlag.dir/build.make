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
include lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/depend.make

# Include the progress variables for this target.
include lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/progress.make

# Include the compile flags for this target's objects.
include lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/flags.make

lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/inputlag.c.obj: lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/flags.make
lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/inputlag.c.obj: lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/includes_C.rsp
lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/inputlag.c.obj: ../lib/cazel/lib/glfw/tests/inputlag.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\projects\graphics\Cazel\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/inputlag.c.obj"
	cd /d C:\projects\graphics\Cazel\cmake-build-release\lib\cazel\lib\glfw\tests && C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\inputlag.dir\inputlag.c.obj   -c C:\projects\graphics\Cazel\lib\cazel\lib\glfw\tests\inputlag.c

lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/inputlag.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/inputlag.dir/inputlag.c.i"
	cd /d C:\projects\graphics\Cazel\cmake-build-release\lib\cazel\lib\glfw\tests && C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\projects\graphics\Cazel\lib\cazel\lib\glfw\tests\inputlag.c > CMakeFiles\inputlag.dir\inputlag.c.i

lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/inputlag.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/inputlag.dir/inputlag.c.s"
	cd /d C:\projects\graphics\Cazel\cmake-build-release\lib\cazel\lib\glfw\tests && C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\projects\graphics\Cazel\lib\cazel\lib\glfw\tests\inputlag.c -o CMakeFiles\inputlag.dir\inputlag.c.s

lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/__/deps/getopt.c.obj: lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/flags.make
lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/__/deps/getopt.c.obj: lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/includes_C.rsp
lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/__/deps/getopt.c.obj: ../lib/cazel/lib/glfw/deps/getopt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\projects\graphics\Cazel\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/__/deps/getopt.c.obj"
	cd /d C:\projects\graphics\Cazel\cmake-build-release\lib\cazel\lib\glfw\tests && C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\inputlag.dir\__\deps\getopt.c.obj   -c C:\projects\graphics\Cazel\lib\cazel\lib\glfw\deps\getopt.c

lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/inputlag.dir/__/deps/getopt.c.i"
	cd /d C:\projects\graphics\Cazel\cmake-build-release\lib\cazel\lib\glfw\tests && C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\projects\graphics\Cazel\lib\cazel\lib\glfw\deps\getopt.c > CMakeFiles\inputlag.dir\__\deps\getopt.c.i

lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/inputlag.dir/__/deps/getopt.c.s"
	cd /d C:\projects\graphics\Cazel\cmake-build-release\lib\cazel\lib\glfw\tests && C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\projects\graphics\Cazel\lib\cazel\lib\glfw\deps\getopt.c -o CMakeFiles\inputlag.dir\__\deps\getopt.c.s

lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/__/deps/glad_gl.c.obj: lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/flags.make
lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/__/deps/glad_gl.c.obj: lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/includes_C.rsp
lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/__/deps/glad_gl.c.obj: ../lib/cazel/lib/glfw/deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\projects\graphics\Cazel\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/__/deps/glad_gl.c.obj"
	cd /d C:\projects\graphics\Cazel\cmake-build-release\lib\cazel\lib\glfw\tests && C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\inputlag.dir\__\deps\glad_gl.c.obj   -c C:\projects\graphics\Cazel\lib\cazel\lib\glfw\deps\glad_gl.c

lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/inputlag.dir/__/deps/glad_gl.c.i"
	cd /d C:\projects\graphics\Cazel\cmake-build-release\lib\cazel\lib\glfw\tests && C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\projects\graphics\Cazel\lib\cazel\lib\glfw\deps\glad_gl.c > CMakeFiles\inputlag.dir\__\deps\glad_gl.c.i

lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/inputlag.dir/__/deps/glad_gl.c.s"
	cd /d C:\projects\graphics\Cazel\cmake-build-release\lib\cazel\lib\glfw\tests && C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\projects\graphics\Cazel\lib\cazel\lib\glfw\deps\glad_gl.c -o CMakeFiles\inputlag.dir\__\deps\glad_gl.c.s

# Object files for target inputlag
inputlag_OBJECTS = \
"CMakeFiles/inputlag.dir/inputlag.c.obj" \
"CMakeFiles/inputlag.dir/__/deps/getopt.c.obj" \
"CMakeFiles/inputlag.dir/__/deps/glad_gl.c.obj"

# External object files for target inputlag
inputlag_EXTERNAL_OBJECTS =

lib/cazel/lib/glfw/tests/inputlag.exe: lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/inputlag.c.obj
lib/cazel/lib/glfw/tests/inputlag.exe: lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/__/deps/getopt.c.obj
lib/cazel/lib/glfw/tests/inputlag.exe: lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/__/deps/glad_gl.c.obj
lib/cazel/lib/glfw/tests/inputlag.exe: lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/build.make
lib/cazel/lib/glfw/tests/inputlag.exe: lib/cazel/lib/glfw/src/libglfw3.a
lib/cazel/lib/glfw/tests/inputlag.exe: lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/linklibs.rsp
lib/cazel/lib/glfw/tests/inputlag.exe: lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/objects1.rsp
lib/cazel/lib/glfw/tests/inputlag.exe: lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\projects\graphics\Cazel\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable inputlag.exe"
	cd /d C:\projects\graphics\Cazel\cmake-build-release\lib\cazel\lib\glfw\tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\inputlag.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/build: lib/cazel/lib/glfw/tests/inputlag.exe

.PHONY : lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/build

lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/clean:
	cd /d C:\projects\graphics\Cazel\cmake-build-release\lib\cazel\lib\glfw\tests && $(CMAKE_COMMAND) -P CMakeFiles\inputlag.dir\cmake_clean.cmake
.PHONY : lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/clean

lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\projects\graphics\Cazel C:\projects\graphics\Cazel\lib\cazel\lib\glfw\tests C:\projects\graphics\Cazel\cmake-build-release C:\projects\graphics\Cazel\cmake-build-release\lib\cazel\lib\glfw\tests C:\projects\graphics\Cazel\cmake-build-release\lib\cazel\lib\glfw\tests\CMakeFiles\inputlag.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : lib/cazel/lib/glfw/tests/CMakeFiles/inputlag.dir/depend

