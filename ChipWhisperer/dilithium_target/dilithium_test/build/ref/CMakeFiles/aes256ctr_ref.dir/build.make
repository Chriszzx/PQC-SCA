# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Github\dilithium

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Github\dilithium\build

# Include any dependencies generated for this target.
include ref/CMakeFiles/aes256ctr_ref.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include ref/CMakeFiles/aes256ctr_ref.dir/compiler_depend.make

# Include the progress variables for this target.
include ref/CMakeFiles/aes256ctr_ref.dir/progress.make

# Include the compile flags for this target's objects.
include ref/CMakeFiles/aes256ctr_ref.dir/flags.make

ref/CMakeFiles/aes256ctr_ref.dir/aes256ctr.c.obj: ref/CMakeFiles/aes256ctr_ref.dir/flags.make
ref/CMakeFiles/aes256ctr_ref.dir/aes256ctr.c.obj: D:/Github/dilithium/ref/aes256ctr.c
ref/CMakeFiles/aes256ctr_ref.dir/aes256ctr.c.obj: ref/CMakeFiles/aes256ctr_ref.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Github\dilithium\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object ref/CMakeFiles/aes256ctr_ref.dir/aes256ctr.c.obj"
	cd /d D:\Github\dilithium\build\ref && C:\msys64\ucrt64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT ref/CMakeFiles/aes256ctr_ref.dir/aes256ctr.c.obj -MF CMakeFiles\aes256ctr_ref.dir\aes256ctr.c.obj.d -o CMakeFiles\aes256ctr_ref.dir\aes256ctr.c.obj -c D:\Github\dilithium\ref\aes256ctr.c

ref/CMakeFiles/aes256ctr_ref.dir/aes256ctr.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/aes256ctr_ref.dir/aes256ctr.c.i"
	cd /d D:\Github\dilithium\build\ref && C:\msys64\ucrt64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Github\dilithium\ref\aes256ctr.c > CMakeFiles\aes256ctr_ref.dir\aes256ctr.c.i

ref/CMakeFiles/aes256ctr_ref.dir/aes256ctr.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/aes256ctr_ref.dir/aes256ctr.c.s"
	cd /d D:\Github\dilithium\build\ref && C:\msys64\ucrt64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Github\dilithium\ref\aes256ctr.c -o CMakeFiles\aes256ctr_ref.dir\aes256ctr.c.s

# Object files for target aes256ctr_ref
aes256ctr_ref_OBJECTS = \
"CMakeFiles/aes256ctr_ref.dir/aes256ctr.c.obj"

# External object files for target aes256ctr_ref
aes256ctr_ref_EXTERNAL_OBJECTS =

ref/libaes256ctr_ref.a: ref/CMakeFiles/aes256ctr_ref.dir/aes256ctr.c.obj
ref/libaes256ctr_ref.a: ref/CMakeFiles/aes256ctr_ref.dir/build.make
ref/libaes256ctr_ref.a: ref/CMakeFiles/aes256ctr_ref.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\Github\dilithium\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libaes256ctr_ref.a"
	cd /d D:\Github\dilithium\build\ref && $(CMAKE_COMMAND) -P CMakeFiles\aes256ctr_ref.dir\cmake_clean_target.cmake
	cd /d D:\Github\dilithium\build\ref && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\aes256ctr_ref.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ref/CMakeFiles/aes256ctr_ref.dir/build: ref/libaes256ctr_ref.a
.PHONY : ref/CMakeFiles/aes256ctr_ref.dir/build

ref/CMakeFiles/aes256ctr_ref.dir/clean:
	cd /d D:\Github\dilithium\build\ref && $(CMAKE_COMMAND) -P CMakeFiles\aes256ctr_ref.dir\cmake_clean.cmake
.PHONY : ref/CMakeFiles/aes256ctr_ref.dir/clean

ref/CMakeFiles/aes256ctr_ref.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Github\dilithium D:\Github\dilithium\ref D:\Github\dilithium\build D:\Github\dilithium\build\ref D:\Github\dilithium\build\ref\CMakeFiles\aes256ctr_ref.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : ref/CMakeFiles/aes256ctr_ref.dir/depend
