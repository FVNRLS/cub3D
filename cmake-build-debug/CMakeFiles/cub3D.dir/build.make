# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/rmazurit/Documents/42_Projects/cub3D

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/rmazurit/Documents/42_Projects/cub3D/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cub3D.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cub3D.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cub3D.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cub3D.dir/flags.make

CMakeFiles/cub3D.dir/src/main.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/src/main.c.o: ../src/main.c
CMakeFiles/cub3D.dir/src/main.c.o: CMakeFiles/cub3D.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rmazurit/Documents/42_Projects/cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/cub3D.dir/src/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/cub3D.dir/src/main.c.o -MF CMakeFiles/cub3D.dir/src/main.c.o.d -o CMakeFiles/cub3D.dir/src/main.c.o -c /Users/rmazurit/Documents/42_Projects/cub3D/src/main.c

CMakeFiles/cub3D.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/src/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rmazurit/Documents/42_Projects/cub3D/src/main.c > CMakeFiles/cub3D.dir/src/main.c.i

CMakeFiles/cub3D.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/src/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rmazurit/Documents/42_Projects/cub3D/src/main.c -o CMakeFiles/cub3D.dir/src/main.c.s

CMakeFiles/cub3D.dir/src/initializer/initializer.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/src/initializer/initializer.c.o: ../src/initializer/initializer.c
CMakeFiles/cub3D.dir/src/initializer/initializer.c.o: CMakeFiles/cub3D.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rmazurit/Documents/42_Projects/cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/cub3D.dir/src/initializer/initializer.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/cub3D.dir/src/initializer/initializer.c.o -MF CMakeFiles/cub3D.dir/src/initializer/initializer.c.o.d -o CMakeFiles/cub3D.dir/src/initializer/initializer.c.o -c /Users/rmazurit/Documents/42_Projects/cub3D/src/initializer/initializer.c

CMakeFiles/cub3D.dir/src/initializer/initializer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/src/initializer/initializer.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rmazurit/Documents/42_Projects/cub3D/src/initializer/initializer.c > CMakeFiles/cub3D.dir/src/initializer/initializer.c.i

CMakeFiles/cub3D.dir/src/initializer/initializer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/src/initializer/initializer.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rmazurit/Documents/42_Projects/cub3D/src/initializer/initializer.c -o CMakeFiles/cub3D.dir/src/initializer/initializer.c.s

CMakeFiles/cub3D.dir/src/initializer/map_objects.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/src/initializer/map_objects.c.o: ../src/initializer/map_objects.c
CMakeFiles/cub3D.dir/src/initializer/map_objects.c.o: CMakeFiles/cub3D.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rmazurit/Documents/42_Projects/cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/cub3D.dir/src/initializer/map_objects.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/cub3D.dir/src/initializer/map_objects.c.o -MF CMakeFiles/cub3D.dir/src/initializer/map_objects.c.o.d -o CMakeFiles/cub3D.dir/src/initializer/map_objects.c.o -c /Users/rmazurit/Documents/42_Projects/cub3D/src/initializer/map_objects.c

CMakeFiles/cub3D.dir/src/initializer/map_objects.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/src/initializer/map_objects.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rmazurit/Documents/42_Projects/cub3D/src/initializer/map_objects.c > CMakeFiles/cub3D.dir/src/initializer/map_objects.c.i

CMakeFiles/cub3D.dir/src/initializer/map_objects.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/src/initializer/map_objects.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rmazurit/Documents/42_Projects/cub3D/src/initializer/map_objects.c -o CMakeFiles/cub3D.dir/src/initializer/map_objects.c.s

CMakeFiles/cub3D.dir/src/destructor.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/src/destructor.c.o: ../src/destructor.c
CMakeFiles/cub3D.dir/src/destructor.c.o: CMakeFiles/cub3D.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rmazurit/Documents/42_Projects/cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/cub3D.dir/src/destructor.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/cub3D.dir/src/destructor.c.o -MF CMakeFiles/cub3D.dir/src/destructor.c.o.d -o CMakeFiles/cub3D.dir/src/destructor.c.o -c /Users/rmazurit/Documents/42_Projects/cub3D/src/destructor.c

CMakeFiles/cub3D.dir/src/destructor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/src/destructor.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rmazurit/Documents/42_Projects/cub3D/src/destructor.c > CMakeFiles/cub3D.dir/src/destructor.c.i

CMakeFiles/cub3D.dir/src/destructor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/src/destructor.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rmazurit/Documents/42_Projects/cub3D/src/destructor.c -o CMakeFiles/cub3D.dir/src/destructor.c.s

CMakeFiles/cub3D.dir/src/parser/parser.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/src/parser/parser.c.o: ../src/parser/parser.c
CMakeFiles/cub3D.dir/src/parser/parser.c.o: CMakeFiles/cub3D.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rmazurit/Documents/42_Projects/cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/cub3D.dir/src/parser/parser.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/cub3D.dir/src/parser/parser.c.o -MF CMakeFiles/cub3D.dir/src/parser/parser.c.o.d -o CMakeFiles/cub3D.dir/src/parser/parser.c.o -c /Users/rmazurit/Documents/42_Projects/cub3D/src/parser/parser.c

CMakeFiles/cub3D.dir/src/parser/parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/src/parser/parser.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rmazurit/Documents/42_Projects/cub3D/src/parser/parser.c > CMakeFiles/cub3D.dir/src/parser/parser.c.i

CMakeFiles/cub3D.dir/src/parser/parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/src/parser/parser.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rmazurit/Documents/42_Projects/cub3D/src/parser/parser.c -o CMakeFiles/cub3D.dir/src/parser/parser.c.s

CMakeFiles/cub3D.dir/src/parser/textures_parser.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/src/parser/textures_parser.c.o: ../src/parser/textures_parser.c
CMakeFiles/cub3D.dir/src/parser/textures_parser.c.o: CMakeFiles/cub3D.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rmazurit/Documents/42_Projects/cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/cub3D.dir/src/parser/textures_parser.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/cub3D.dir/src/parser/textures_parser.c.o -MF CMakeFiles/cub3D.dir/src/parser/textures_parser.c.o.d -o CMakeFiles/cub3D.dir/src/parser/textures_parser.c.o -c /Users/rmazurit/Documents/42_Projects/cub3D/src/parser/textures_parser.c

CMakeFiles/cub3D.dir/src/parser/textures_parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/src/parser/textures_parser.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rmazurit/Documents/42_Projects/cub3D/src/parser/textures_parser.c > CMakeFiles/cub3D.dir/src/parser/textures_parser.c.i

CMakeFiles/cub3D.dir/src/parser/textures_parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/src/parser/textures_parser.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rmazurit/Documents/42_Projects/cub3D/src/parser/textures_parser.c -o CMakeFiles/cub3D.dir/src/parser/textures_parser.c.s

CMakeFiles/cub3D.dir/src/parser/colors_parser.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/src/parser/colors_parser.c.o: ../src/parser/colors_parser.c
CMakeFiles/cub3D.dir/src/parser/colors_parser.c.o: CMakeFiles/cub3D.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rmazurit/Documents/42_Projects/cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/cub3D.dir/src/parser/colors_parser.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/cub3D.dir/src/parser/colors_parser.c.o -MF CMakeFiles/cub3D.dir/src/parser/colors_parser.c.o.d -o CMakeFiles/cub3D.dir/src/parser/colors_parser.c.o -c /Users/rmazurit/Documents/42_Projects/cub3D/src/parser/colors_parser.c

CMakeFiles/cub3D.dir/src/parser/colors_parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/src/parser/colors_parser.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rmazurit/Documents/42_Projects/cub3D/src/parser/colors_parser.c > CMakeFiles/cub3D.dir/src/parser/colors_parser.c.i

CMakeFiles/cub3D.dir/src/parser/colors_parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/src/parser/colors_parser.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rmazurit/Documents/42_Projects/cub3D/src/parser/colors_parser.c -o CMakeFiles/cub3D.dir/src/parser/colors_parser.c.s

CMakeFiles/cub3D.dir/src/parser/map_parser.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/src/parser/map_parser.c.o: ../src/parser/map_parser.c
CMakeFiles/cub3D.dir/src/parser/map_parser.c.o: CMakeFiles/cub3D.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rmazurit/Documents/42_Projects/cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/cub3D.dir/src/parser/map_parser.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/cub3D.dir/src/parser/map_parser.c.o -MF CMakeFiles/cub3D.dir/src/parser/map_parser.c.o.d -o CMakeFiles/cub3D.dir/src/parser/map_parser.c.o -c /Users/rmazurit/Documents/42_Projects/cub3D/src/parser/map_parser.c

CMakeFiles/cub3D.dir/src/parser/map_parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/src/parser/map_parser.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rmazurit/Documents/42_Projects/cub3D/src/parser/map_parser.c > CMakeFiles/cub3D.dir/src/parser/map_parser.c.i

CMakeFiles/cub3D.dir/src/parser/map_parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/src/parser/map_parser.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rmazurit/Documents/42_Projects/cub3D/src/parser/map_parser.c -o CMakeFiles/cub3D.dir/src/parser/map_parser.c.s

CMakeFiles/cub3D.dir/src/error_printer.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/src/error_printer.c.o: ../src/error_printer.c
CMakeFiles/cub3D.dir/src/error_printer.c.o: CMakeFiles/cub3D.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rmazurit/Documents/42_Projects/cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/cub3D.dir/src/error_printer.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/cub3D.dir/src/error_printer.c.o -MF CMakeFiles/cub3D.dir/src/error_printer.c.o.d -o CMakeFiles/cub3D.dir/src/error_printer.c.o -c /Users/rmazurit/Documents/42_Projects/cub3D/src/error_printer.c

CMakeFiles/cub3D.dir/src/error_printer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/src/error_printer.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rmazurit/Documents/42_Projects/cub3D/src/error_printer.c > CMakeFiles/cub3D.dir/src/error_printer.c.i

CMakeFiles/cub3D.dir/src/error_printer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/src/error_printer.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rmazurit/Documents/42_Projects/cub3D/src/error_printer.c -o CMakeFiles/cub3D.dir/src/error_printer.c.s

CMakeFiles/cub3D.dir/src/tools/ft_strlen.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/src/tools/ft_strlen.c.o: ../src/tools/ft_strlen.c
CMakeFiles/cub3D.dir/src/tools/ft_strlen.c.o: CMakeFiles/cub3D.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rmazurit/Documents/42_Projects/cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/cub3D.dir/src/tools/ft_strlen.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/cub3D.dir/src/tools/ft_strlen.c.o -MF CMakeFiles/cub3D.dir/src/tools/ft_strlen.c.o.d -o CMakeFiles/cub3D.dir/src/tools/ft_strlen.c.o -c /Users/rmazurit/Documents/42_Projects/cub3D/src/tools/ft_strlen.c

CMakeFiles/cub3D.dir/src/tools/ft_strlen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/src/tools/ft_strlen.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rmazurit/Documents/42_Projects/cub3D/src/tools/ft_strlen.c > CMakeFiles/cub3D.dir/src/tools/ft_strlen.c.i

CMakeFiles/cub3D.dir/src/tools/ft_strlen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/src/tools/ft_strlen.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rmazurit/Documents/42_Projects/cub3D/src/tools/ft_strlen.c -o CMakeFiles/cub3D.dir/src/tools/ft_strlen.c.s

CMakeFiles/cub3D.dir/src/tools/ft_strncmp.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/src/tools/ft_strncmp.c.o: ../src/tools/ft_strncmp.c
CMakeFiles/cub3D.dir/src/tools/ft_strncmp.c.o: CMakeFiles/cub3D.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rmazurit/Documents/42_Projects/cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/cub3D.dir/src/tools/ft_strncmp.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/cub3D.dir/src/tools/ft_strncmp.c.o -MF CMakeFiles/cub3D.dir/src/tools/ft_strncmp.c.o.d -o CMakeFiles/cub3D.dir/src/tools/ft_strncmp.c.o -c /Users/rmazurit/Documents/42_Projects/cub3D/src/tools/ft_strncmp.c

CMakeFiles/cub3D.dir/src/tools/ft_strncmp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/src/tools/ft_strncmp.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rmazurit/Documents/42_Projects/cub3D/src/tools/ft_strncmp.c > CMakeFiles/cub3D.dir/src/tools/ft_strncmp.c.i

CMakeFiles/cub3D.dir/src/tools/ft_strncmp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/src/tools/ft_strncmp.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rmazurit/Documents/42_Projects/cub3D/src/tools/ft_strncmp.c -o CMakeFiles/cub3D.dir/src/tools/ft_strncmp.c.s

CMakeFiles/cub3D.dir/src/tools/ft_split.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/src/tools/ft_split.c.o: ../src/tools/ft_split.c
CMakeFiles/cub3D.dir/src/tools/ft_split.c.o: CMakeFiles/cub3D.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rmazurit/Documents/42_Projects/cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/cub3D.dir/src/tools/ft_split.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/cub3D.dir/src/tools/ft_split.c.o -MF CMakeFiles/cub3D.dir/src/tools/ft_split.c.o.d -o CMakeFiles/cub3D.dir/src/tools/ft_split.c.o -c /Users/rmazurit/Documents/42_Projects/cub3D/src/tools/ft_split.c

CMakeFiles/cub3D.dir/src/tools/ft_split.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/src/tools/ft_split.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rmazurit/Documents/42_Projects/cub3D/src/tools/ft_split.c > CMakeFiles/cub3D.dir/src/tools/ft_split.c.i

CMakeFiles/cub3D.dir/src/tools/ft_split.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/src/tools/ft_split.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rmazurit/Documents/42_Projects/cub3D/src/tools/ft_split.c -o CMakeFiles/cub3D.dir/src/tools/ft_split.c.s

CMakeFiles/cub3D.dir/src/tools/ft_strdup.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/src/tools/ft_strdup.c.o: ../src/tools/ft_strdup.c
CMakeFiles/cub3D.dir/src/tools/ft_strdup.c.o: CMakeFiles/cub3D.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rmazurit/Documents/42_Projects/cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/cub3D.dir/src/tools/ft_strdup.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/cub3D.dir/src/tools/ft_strdup.c.o -MF CMakeFiles/cub3D.dir/src/tools/ft_strdup.c.o.d -o CMakeFiles/cub3D.dir/src/tools/ft_strdup.c.o -c /Users/rmazurit/Documents/42_Projects/cub3D/src/tools/ft_strdup.c

CMakeFiles/cub3D.dir/src/tools/ft_strdup.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/src/tools/ft_strdup.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rmazurit/Documents/42_Projects/cub3D/src/tools/ft_strdup.c > CMakeFiles/cub3D.dir/src/tools/ft_strdup.c.i

CMakeFiles/cub3D.dir/src/tools/ft_strdup.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/src/tools/ft_strdup.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rmazurit/Documents/42_Projects/cub3D/src/tools/ft_strdup.c -o CMakeFiles/cub3D.dir/src/tools/ft_strdup.c.s

CMakeFiles/cub3D.dir/src/tools/ft_atoi.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/src/tools/ft_atoi.c.o: ../src/tools/ft_atoi.c
CMakeFiles/cub3D.dir/src/tools/ft_atoi.c.o: CMakeFiles/cub3D.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rmazurit/Documents/42_Projects/cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/cub3D.dir/src/tools/ft_atoi.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/cub3D.dir/src/tools/ft_atoi.c.o -MF CMakeFiles/cub3D.dir/src/tools/ft_atoi.c.o.d -o CMakeFiles/cub3D.dir/src/tools/ft_atoi.c.o -c /Users/rmazurit/Documents/42_Projects/cub3D/src/tools/ft_atoi.c

CMakeFiles/cub3D.dir/src/tools/ft_atoi.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/src/tools/ft_atoi.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rmazurit/Documents/42_Projects/cub3D/src/tools/ft_atoi.c > CMakeFiles/cub3D.dir/src/tools/ft_atoi.c.i

CMakeFiles/cub3D.dir/src/tools/ft_atoi.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/src/tools/ft_atoi.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rmazurit/Documents/42_Projects/cub3D/src/tools/ft_atoi.c -o CMakeFiles/cub3D.dir/src/tools/ft_atoi.c.s

CMakeFiles/cub3D.dir/src/tools/ft_isdigit.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/src/tools/ft_isdigit.c.o: ../src/tools/ft_isdigit.c
CMakeFiles/cub3D.dir/src/tools/ft_isdigit.c.o: CMakeFiles/cub3D.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rmazurit/Documents/42_Projects/cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building C object CMakeFiles/cub3D.dir/src/tools/ft_isdigit.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/cub3D.dir/src/tools/ft_isdigit.c.o -MF CMakeFiles/cub3D.dir/src/tools/ft_isdigit.c.o.d -o CMakeFiles/cub3D.dir/src/tools/ft_isdigit.c.o -c /Users/rmazurit/Documents/42_Projects/cub3D/src/tools/ft_isdigit.c

CMakeFiles/cub3D.dir/src/tools/ft_isdigit.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/src/tools/ft_isdigit.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rmazurit/Documents/42_Projects/cub3D/src/tools/ft_isdigit.c > CMakeFiles/cub3D.dir/src/tools/ft_isdigit.c.i

CMakeFiles/cub3D.dir/src/tools/ft_isdigit.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/src/tools/ft_isdigit.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rmazurit/Documents/42_Projects/cub3D/src/tools/ft_isdigit.c -o CMakeFiles/cub3D.dir/src/tools/ft_isdigit.c.s

CMakeFiles/cub3D.dir/src/tools/ft_strcmp.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/src/tools/ft_strcmp.c.o: ../src/tools/ft_strcmp.c
CMakeFiles/cub3D.dir/src/tools/ft_strcmp.c.o: CMakeFiles/cub3D.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rmazurit/Documents/42_Projects/cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building C object CMakeFiles/cub3D.dir/src/tools/ft_strcmp.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/cub3D.dir/src/tools/ft_strcmp.c.o -MF CMakeFiles/cub3D.dir/src/tools/ft_strcmp.c.o.d -o CMakeFiles/cub3D.dir/src/tools/ft_strcmp.c.o -c /Users/rmazurit/Documents/42_Projects/cub3D/src/tools/ft_strcmp.c

CMakeFiles/cub3D.dir/src/tools/ft_strcmp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/src/tools/ft_strcmp.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rmazurit/Documents/42_Projects/cub3D/src/tools/ft_strcmp.c > CMakeFiles/cub3D.dir/src/tools/ft_strcmp.c.i

CMakeFiles/cub3D.dir/src/tools/ft_strcmp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/src/tools/ft_strcmp.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rmazurit/Documents/42_Projects/cub3D/src/tools/ft_strcmp.c -o CMakeFiles/cub3D.dir/src/tools/ft_strcmp.c.s

CMakeFiles/cub3D.dir/src/tools/ft_splitlen.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/src/tools/ft_splitlen.c.o: ../src/tools/ft_splitlen.c
CMakeFiles/cub3D.dir/src/tools/ft_splitlen.c.o: CMakeFiles/cub3D.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rmazurit/Documents/42_Projects/cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building C object CMakeFiles/cub3D.dir/src/tools/ft_splitlen.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/cub3D.dir/src/tools/ft_splitlen.c.o -MF CMakeFiles/cub3D.dir/src/tools/ft_splitlen.c.o.d -o CMakeFiles/cub3D.dir/src/tools/ft_splitlen.c.o -c /Users/rmazurit/Documents/42_Projects/cub3D/src/tools/ft_splitlen.c

CMakeFiles/cub3D.dir/src/tools/ft_splitlen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/src/tools/ft_splitlen.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rmazurit/Documents/42_Projects/cub3D/src/tools/ft_splitlen.c > CMakeFiles/cub3D.dir/src/tools/ft_splitlen.c.i

CMakeFiles/cub3D.dir/src/tools/ft_splitlen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/src/tools/ft_splitlen.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rmazurit/Documents/42_Projects/cub3D/src/tools/ft_splitlen.c -o CMakeFiles/cub3D.dir/src/tools/ft_splitlen.c.s

CMakeFiles/cub3D.dir/src/tools/ft_free_split.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/src/tools/ft_free_split.c.o: ../src/tools/ft_free_split.c
CMakeFiles/cub3D.dir/src/tools/ft_free_split.c.o: CMakeFiles/cub3D.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rmazurit/Documents/42_Projects/cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building C object CMakeFiles/cub3D.dir/src/tools/ft_free_split.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/cub3D.dir/src/tools/ft_free_split.c.o -MF CMakeFiles/cub3D.dir/src/tools/ft_free_split.c.o.d -o CMakeFiles/cub3D.dir/src/tools/ft_free_split.c.o -c /Users/rmazurit/Documents/42_Projects/cub3D/src/tools/ft_free_split.c

CMakeFiles/cub3D.dir/src/tools/ft_free_split.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/src/tools/ft_free_split.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rmazurit/Documents/42_Projects/cub3D/src/tools/ft_free_split.c > CMakeFiles/cub3D.dir/src/tools/ft_free_split.c.i

CMakeFiles/cub3D.dir/src/tools/ft_free_split.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/src/tools/ft_free_split.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rmazurit/Documents/42_Projects/cub3D/src/tools/ft_free_split.c -o CMakeFiles/cub3D.dir/src/tools/ft_free_split.c.s

CMakeFiles/cub3D.dir/src/tools/ft_free_all_and_exit.c.o: CMakeFiles/cub3D.dir/flags.make
CMakeFiles/cub3D.dir/src/tools/ft_free_all_and_exit.c.o: ../src/tools/ft_free_all_and_exit.c
CMakeFiles/cub3D.dir/src/tools/ft_free_all_and_exit.c.o: CMakeFiles/cub3D.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rmazurit/Documents/42_Projects/cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building C object CMakeFiles/cub3D.dir/src/tools/ft_free_all_and_exit.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/cub3D.dir/src/tools/ft_free_all_and_exit.c.o -MF CMakeFiles/cub3D.dir/src/tools/ft_free_all_and_exit.c.o.d -o CMakeFiles/cub3D.dir/src/tools/ft_free_all_and_exit.c.o -c /Users/rmazurit/Documents/42_Projects/cub3D/src/tools/ft_free_all_and_exit.c

CMakeFiles/cub3D.dir/src/tools/ft_free_all_and_exit.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cub3D.dir/src/tools/ft_free_all_and_exit.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rmazurit/Documents/42_Projects/cub3D/src/tools/ft_free_all_and_exit.c > CMakeFiles/cub3D.dir/src/tools/ft_free_all_and_exit.c.i

CMakeFiles/cub3D.dir/src/tools/ft_free_all_and_exit.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cub3D.dir/src/tools/ft_free_all_and_exit.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rmazurit/Documents/42_Projects/cub3D/src/tools/ft_free_all_and_exit.c -o CMakeFiles/cub3D.dir/src/tools/ft_free_all_and_exit.c.s

# Object files for target cub3D
cub3D_OBJECTS = \
"CMakeFiles/cub3D.dir/src/main.c.o" \
"CMakeFiles/cub3D.dir/src/initializer/initializer.c.o" \
"CMakeFiles/cub3D.dir/src/initializer/map_objects.c.o" \
"CMakeFiles/cub3D.dir/src/destructor.c.o" \
"CMakeFiles/cub3D.dir/src/parser/parser.c.o" \
"CMakeFiles/cub3D.dir/src/parser/textures_parser.c.o" \
"CMakeFiles/cub3D.dir/src/parser/colors_parser.c.o" \
"CMakeFiles/cub3D.dir/src/parser/map_parser.c.o" \
"CMakeFiles/cub3D.dir/src/error_printer.c.o" \
"CMakeFiles/cub3D.dir/src/tools/ft_strlen.c.o" \
"CMakeFiles/cub3D.dir/src/tools/ft_strncmp.c.o" \
"CMakeFiles/cub3D.dir/src/tools/ft_split.c.o" \
"CMakeFiles/cub3D.dir/src/tools/ft_strdup.c.o" \
"CMakeFiles/cub3D.dir/src/tools/ft_atoi.c.o" \
"CMakeFiles/cub3D.dir/src/tools/ft_isdigit.c.o" \
"CMakeFiles/cub3D.dir/src/tools/ft_strcmp.c.o" \
"CMakeFiles/cub3D.dir/src/tools/ft_splitlen.c.o" \
"CMakeFiles/cub3D.dir/src/tools/ft_free_split.c.o" \
"CMakeFiles/cub3D.dir/src/tools/ft_free_all_and_exit.c.o"

# External object files for target cub3D
cub3D_EXTERNAL_OBJECTS =

cub3D: CMakeFiles/cub3D.dir/src/main.c.o
cub3D: CMakeFiles/cub3D.dir/src/initializer/initializer.c.o
cub3D: CMakeFiles/cub3D.dir/src/initializer/map_objects.c.o
cub3D: CMakeFiles/cub3D.dir/src/destructor.c.o
cub3D: CMakeFiles/cub3D.dir/src/parser/parser.c.o
cub3D: CMakeFiles/cub3D.dir/src/parser/textures_parser.c.o
cub3D: CMakeFiles/cub3D.dir/src/parser/colors_parser.c.o
cub3D: CMakeFiles/cub3D.dir/src/parser/map_parser.c.o
cub3D: CMakeFiles/cub3D.dir/src/error_printer.c.o
cub3D: CMakeFiles/cub3D.dir/src/tools/ft_strlen.c.o
cub3D: CMakeFiles/cub3D.dir/src/tools/ft_strncmp.c.o
cub3D: CMakeFiles/cub3D.dir/src/tools/ft_split.c.o
cub3D: CMakeFiles/cub3D.dir/src/tools/ft_strdup.c.o
cub3D: CMakeFiles/cub3D.dir/src/tools/ft_atoi.c.o
cub3D: CMakeFiles/cub3D.dir/src/tools/ft_isdigit.c.o
cub3D: CMakeFiles/cub3D.dir/src/tools/ft_strcmp.c.o
cub3D: CMakeFiles/cub3D.dir/src/tools/ft_splitlen.c.o
cub3D: CMakeFiles/cub3D.dir/src/tools/ft_free_split.c.o
cub3D: CMakeFiles/cub3D.dir/src/tools/ft_free_all_and_exit.c.o
cub3D: CMakeFiles/cub3D.dir/build.make
cub3D: ../lib/get_next_line/get_next_line.a
cub3D: CMakeFiles/cub3D.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/rmazurit/Documents/42_Projects/cub3D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Linking C executable cub3D"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cub3D.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cub3D.dir/build: cub3D
.PHONY : CMakeFiles/cub3D.dir/build

CMakeFiles/cub3D.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cub3D.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cub3D.dir/clean

CMakeFiles/cub3D.dir/depend:
	cd /Users/rmazurit/Documents/42_Projects/cub3D/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/rmazurit/Documents/42_Projects/cub3D /Users/rmazurit/Documents/42_Projects/cub3D /Users/rmazurit/Documents/42_Projects/cub3D/cmake-build-debug /Users/rmazurit/Documents/42_Projects/cub3D/cmake-build-debug /Users/rmazurit/Documents/42_Projects/cub3D/cmake-build-debug/CMakeFiles/cub3D.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cub3D.dir/depend

