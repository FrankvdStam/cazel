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
include lib/cazel/lib/glfw/tests/CMakeFiles/icon.dir/depend.make

# Include the progress variables for this target.
include lib/cazel/lib/glfw/tests/CMakeFiles/icon.dir/progress.make

# Include the compile flags for this target's objects.
include lib/cazel/lib/glfw/tests/CMakeFiles/icon.dir/flags.make

lib/cazel/lib/glfw/tests/CMakeFiles/icon.dir/icon.c.obj: lib/cazel/lib/glfw/tests/CMakeFiles/icon.dir/flags.make
lib/cazel/lib/glfw/tests/CMakeFiles/icon.dir/icon.c.obj: lib/cazel/lib/glfw/tests/CMakeFiles/icon.dir/includes_C.rsp
lib/cazel/lib/glfw/tests/CMakeFiles/icon.dir/icon.c.obj: ../lib/cazel/lib/glfw/tests/icon.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\projects\graphics\Cazel\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/cazel/lib/glfw/tests/CMakeFiles/icon.dir/icon.c.obj"
	cd /d C:\projects\graphics\Cazel\cmake-build-release\lib\cazel\lib\glfw\tests && C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\icon.dir\icon.c.obj   -c C:\projects\graphics\Cazel\lib\cazel\lib\glfw\tests\icon.c

lib/cazel/lib/glfw/tests/CMakeFiles/icon.dir/icon.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/icon.dir/icon.c.i"
	cd /d C:\projects\graphics\Cazel\cmake-build-release\lib\cazel\lib\glfw\tests && C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\projects\graphics\Cazel\lib\cazel\lib\glfw\tests\icon.c > CMakeFiles\icon.dir\icon.c.i

lib/cazel/lib/glfw/tests/CMakeFiles/icon.dir/icon.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/icon.dir/icon.c.s"
	cd /d C:\projects\graphics\Cazel\cmake-build-release\lib\cazel\lib\glfw\tests && C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\projects\graphics\Cazel\lib\cazel\lib\glfw\tests\icon.c -o CMakeFiles\icon.dir\icon.c.s

lib/cazel/lib/glfw/tests/CMakeFiles/icon.dir/__/deps/glad_gl.c.obj: lib/cazel/lib/glfw/tests/CMakeFiles/icon.dir/flags.make
lib/cazel/lib/glfw/tests/CMakeFiles/icon.dir/__/deps/glad_gl.c.obj: lib/cazel/lib/glfw/tests/CMakeFiles/icon.dir/includes_C.rsp
lib/cazel/lib/glfw/tests/CMakeFiles/icon.dir/__/deps/glad_gl.c.obj: ../lib/cazel/lib/glfw/deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\projects\graphics\Cazel\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object lib/cazel/lib/glfw/tests/CMakeFiles/icon.dir/__/deps/glad_gl.c.obj"
	cd /d C:\projects\graphics\Cazel\cmake-build-release\lib\cazel\lib\glfw\tests && C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\icon.dir\__\deps\glad_gl.c.obj   -c C:\projects\graphics\Cazel\lib\cazel\lib\glfw\deps\glad_gl.c

lib/cazel/lib/glfw/tests/CMakeFiles/icon.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/icon.dir/__/deps/glad_gl.c.i"
	cd /d C:\projects\graphics\Cazel\cmake-build-release\lib\cazel\lib\glfw\tests && C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\projects\graphics\Cazel\lib\cazel\lib\glfw\deps\glad_gl.c > CMakeFiles\icon.dir\__\deps\glad_gl.c.i

lib/cazel/lib/glfw/tests/CMakeFiles/icon.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/icon.dir/__/deps/glad_gl.c.s"
	cd /d C:\projects\graphics\Cazel\cmake-build-release\lib\cazel\lib\glfw\tests && C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\projects\graphics\Cazel\lib\cazel\lib\glfw\deps\glad_gl.c -o CMakeFiles\icon.dir\__\deps\glad_gl.c.s

# Object files for target icon
icon_OBJECTS = \
"CMakeFiles/icon.dir/icon.c.obj" \
"CMakeFiles/icon.dir/__/deps/glad_gl.c.obj"

# External object files for target icon
icon_EXTERNAL_OBJECTS =

lib/cazel/lib/glfw/tests/icon.exe: lib/cazel/lib/glfw/tests/CMakeFiles/icon.dir/icon.c.obj
lib/cazel/lib/glfw/tests/icon.exe: lib/cazel/lib/glfw/tests/CMakeFiles/icon.dir/__/deps/glad_gl.c.obj
lib/cazel/lib/glfw/tests/icon.exe: lib/cazel/lib/glfw/tests/CMakeFiles/icon.dir/build.make
lib/cazel/lib/glfw/tests/icon.exe: lib/cazel/lib/glfw/src/libglfw3.a
lib/cazel/lib/glfw/tests/icon.exe: lib/cazel/lib/glfw/tests/CMakeFiles/icon.dir/linklibs.rsp
lib/cazel/lib/glfw/tests/icon.exe: lib/cazel/lib/glfw/tests/CMakeFiles/icon.dir/objects1.rsp
lib/cazel/lib/glfw/tests/icon.exe: lib/cazel/lib/glfw/tests/CMakeFiles/icon.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\projects\graphics\Cazel\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable icon.exe"
	cd /d C:\projects\graphics\Cazel\cmake-build-release\lib\cazel\lib\glfw\tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\icon.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/cazel/lib/glfw/tests/CMakeFiles/icon.dir/build: lib/cazel/lib/glfw/tests/icon.exe

.PHONY : lib/cazel/lib/glfw/tests/CMakeFiles/icon.dir/build

lib/cazel/lib/glfw/tests/CMakeFiles/icon.dir/clean:
	cd /d C:\projects\graphics\Cazel\cmake-build-release\lib\cazel\lib\glfw\tests && $(CMAKE_COMMAND) -P CMakeFiles\icon.dir\cmake_clean.cmake
.PHONY : lib/cazel/lib/glfw/tests/CMakeFiles/icon.dir/clean

lib/cazel/lib/glfw/tests/CMakeFiles/icon.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\projects\graphics\Cazel C:\projects\graphics\Cazel\lib\cazel\lib\glfw\tests C:\projects\graphics\Cazel\cmake-build-release C:\projects\graphics\Cazel\cmake-build-release\lib\cazel\lib\glfw\tests C:\projects\graphics\Cazel\cmake-build-release\lib\cazel\lib\glfw\tests\CMakeFiles\icon.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : lib/cazel/lib/glfw/tests/CMakeFiles/icon.dir/depend

