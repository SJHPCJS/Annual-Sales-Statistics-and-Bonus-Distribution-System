# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = "D:\CLion\CLion 2023.2.2\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion\CLion 2023.2.2\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\C-C++-code\C\SaleBonusCalculationSystem

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\C-C++-code\C\SaleBonusCalculationSystem\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SaleBonusCalculationSystem.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SaleBonusCalculationSystem.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SaleBonusCalculationSystem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SaleBonusCalculationSystem.dir/flags.make

CMakeFiles/SaleBonusCalculationSystem.dir/main.c.obj: CMakeFiles/SaleBonusCalculationSystem.dir/flags.make
CMakeFiles/SaleBonusCalculationSystem.dir/main.c.obj: D:/C-C++-code/C/SaleBonusCalculationSystem/main.c
CMakeFiles/SaleBonusCalculationSystem.dir/main.c.obj: CMakeFiles/SaleBonusCalculationSystem.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\C-C++-code\C\SaleBonusCalculationSystem\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/SaleBonusCalculationSystem.dir/main.c.obj"
	D:\mingw-18.0\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SaleBonusCalculationSystem.dir/main.c.obj -MF CMakeFiles\SaleBonusCalculationSystem.dir\main.c.obj.d -o CMakeFiles\SaleBonusCalculationSystem.dir\main.c.obj -c D:\C-C++-code\C\SaleBonusCalculationSystem\main.c

CMakeFiles/SaleBonusCalculationSystem.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SaleBonusCalculationSystem.dir/main.c.i"
	D:\mingw-18.0\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\C-C++-code\C\SaleBonusCalculationSystem\main.c > CMakeFiles\SaleBonusCalculationSystem.dir\main.c.i

CMakeFiles/SaleBonusCalculationSystem.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SaleBonusCalculationSystem.dir/main.c.s"
	D:\mingw-18.0\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\C-C++-code\C\SaleBonusCalculationSystem\main.c -o CMakeFiles\SaleBonusCalculationSystem.dir\main.c.s

# Object files for target SaleBonusCalculationSystem
SaleBonusCalculationSystem_OBJECTS = \
"CMakeFiles/SaleBonusCalculationSystem.dir/main.c.obj"

# External object files for target SaleBonusCalculationSystem
SaleBonusCalculationSystem_EXTERNAL_OBJECTS =

SaleBonusCalculationSystem.exe: CMakeFiles/SaleBonusCalculationSystem.dir/main.c.obj
SaleBonusCalculationSystem.exe: CMakeFiles/SaleBonusCalculationSystem.dir/build.make
SaleBonusCalculationSystem.exe: CMakeFiles/SaleBonusCalculationSystem.dir/linkLibs.rsp
SaleBonusCalculationSystem.exe: CMakeFiles/SaleBonusCalculationSystem.dir/objects1.rsp
SaleBonusCalculationSystem.exe: CMakeFiles/SaleBonusCalculationSystem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\C-C++-code\C\SaleBonusCalculationSystem\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable SaleBonusCalculationSystem.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SaleBonusCalculationSystem.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SaleBonusCalculationSystem.dir/build: SaleBonusCalculationSystem.exe
.PHONY : CMakeFiles/SaleBonusCalculationSystem.dir/build

CMakeFiles/SaleBonusCalculationSystem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SaleBonusCalculationSystem.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SaleBonusCalculationSystem.dir/clean

CMakeFiles/SaleBonusCalculationSystem.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\C-C++-code\C\SaleBonusCalculationSystem D:\C-C++-code\C\SaleBonusCalculationSystem D:\C-C++-code\C\SaleBonusCalculationSystem\cmake-build-debug D:\C-C++-code\C\SaleBonusCalculationSystem\cmake-build-debug D:\C-C++-code\C\SaleBonusCalculationSystem\cmake-build-debug\CMakeFiles\SaleBonusCalculationSystem.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SaleBonusCalculationSystem.dir/depend

