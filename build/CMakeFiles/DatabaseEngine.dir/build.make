# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zhaolingmei/Documents/MyCode/C++/Database-Engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zhaolingmei/Documents/MyCode/C++/Database-Engine/build

# Include any dependencies generated for this target.
include CMakeFiles/DatabaseEngine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DatabaseEngine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DatabaseEngine.dir/flags.make

CMakeFiles/DatabaseEngine.dir/main.cpp.o: CMakeFiles/DatabaseEngine.dir/flags.make
CMakeFiles/DatabaseEngine.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhaolingmei/Documents/MyCode/C++/Database-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DatabaseEngine.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DatabaseEngine.dir/main.cpp.o -c /home/zhaolingmei/Documents/MyCode/C++/Database-Engine/main.cpp

CMakeFiles/DatabaseEngine.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DatabaseEngine.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhaolingmei/Documents/MyCode/C++/Database-Engine/main.cpp > CMakeFiles/DatabaseEngine.dir/main.cpp.i

CMakeFiles/DatabaseEngine.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DatabaseEngine.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhaolingmei/Documents/MyCode/C++/Database-Engine/main.cpp -o CMakeFiles/DatabaseEngine.dir/main.cpp.s

CMakeFiles/DatabaseEngine.dir/src/BPlusTree.cpp.o: CMakeFiles/DatabaseEngine.dir/flags.make
CMakeFiles/DatabaseEngine.dir/src/BPlusTree.cpp.o: ../src/BPlusTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhaolingmei/Documents/MyCode/C++/Database-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DatabaseEngine.dir/src/BPlusTree.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DatabaseEngine.dir/src/BPlusTree.cpp.o -c /home/zhaolingmei/Documents/MyCode/C++/Database-Engine/src/BPlusTree.cpp

CMakeFiles/DatabaseEngine.dir/src/BPlusTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DatabaseEngine.dir/src/BPlusTree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhaolingmei/Documents/MyCode/C++/Database-Engine/src/BPlusTree.cpp > CMakeFiles/DatabaseEngine.dir/src/BPlusTree.cpp.i

CMakeFiles/DatabaseEngine.dir/src/BPlusTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DatabaseEngine.dir/src/BPlusTree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhaolingmei/Documents/MyCode/C++/Database-Engine/src/BPlusTree.cpp -o CMakeFiles/DatabaseEngine.dir/src/BPlusTree.cpp.s

CMakeFiles/DatabaseEngine.dir/src/DataReader.cpp.o: CMakeFiles/DatabaseEngine.dir/flags.make
CMakeFiles/DatabaseEngine.dir/src/DataReader.cpp.o: ../src/DataReader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhaolingmei/Documents/MyCode/C++/Database-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DatabaseEngine.dir/src/DataReader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DatabaseEngine.dir/src/DataReader.cpp.o -c /home/zhaolingmei/Documents/MyCode/C++/Database-Engine/src/DataReader.cpp

CMakeFiles/DatabaseEngine.dir/src/DataReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DatabaseEngine.dir/src/DataReader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhaolingmei/Documents/MyCode/C++/Database-Engine/src/DataReader.cpp > CMakeFiles/DatabaseEngine.dir/src/DataReader.cpp.i

CMakeFiles/DatabaseEngine.dir/src/DataReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DatabaseEngine.dir/src/DataReader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhaolingmei/Documents/MyCode/C++/Database-Engine/src/DataReader.cpp -o CMakeFiles/DatabaseEngine.dir/src/DataReader.cpp.s

CMakeFiles/DatabaseEngine.dir/src/DataWriter.cpp.o: CMakeFiles/DatabaseEngine.dir/flags.make
CMakeFiles/DatabaseEngine.dir/src/DataWriter.cpp.o: ../src/DataWriter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhaolingmei/Documents/MyCode/C++/Database-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/DatabaseEngine.dir/src/DataWriter.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DatabaseEngine.dir/src/DataWriter.cpp.o -c /home/zhaolingmei/Documents/MyCode/C++/Database-Engine/src/DataWriter.cpp

CMakeFiles/DatabaseEngine.dir/src/DataWriter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DatabaseEngine.dir/src/DataWriter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhaolingmei/Documents/MyCode/C++/Database-Engine/src/DataWriter.cpp > CMakeFiles/DatabaseEngine.dir/src/DataWriter.cpp.i

CMakeFiles/DatabaseEngine.dir/src/DataWriter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DatabaseEngine.dir/src/DataWriter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhaolingmei/Documents/MyCode/C++/Database-Engine/src/DataWriter.cpp -o CMakeFiles/DatabaseEngine.dir/src/DataWriter.cpp.s

CMakeFiles/DatabaseEngine.dir/src/Field.cpp.o: CMakeFiles/DatabaseEngine.dir/flags.make
CMakeFiles/DatabaseEngine.dir/src/Field.cpp.o: ../src/Field.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhaolingmei/Documents/MyCode/C++/Database-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/DatabaseEngine.dir/src/Field.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DatabaseEngine.dir/src/Field.cpp.o -c /home/zhaolingmei/Documents/MyCode/C++/Database-Engine/src/Field.cpp

CMakeFiles/DatabaseEngine.dir/src/Field.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DatabaseEngine.dir/src/Field.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhaolingmei/Documents/MyCode/C++/Database-Engine/src/Field.cpp > CMakeFiles/DatabaseEngine.dir/src/Field.cpp.i

CMakeFiles/DatabaseEngine.dir/src/Field.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DatabaseEngine.dir/src/Field.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhaolingmei/Documents/MyCode/C++/Database-Engine/src/Field.cpp -o CMakeFiles/DatabaseEngine.dir/src/Field.cpp.s

CMakeFiles/DatabaseEngine.dir/src/Page.cpp.o: CMakeFiles/DatabaseEngine.dir/flags.make
CMakeFiles/DatabaseEngine.dir/src/Page.cpp.o: ../src/Page.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhaolingmei/Documents/MyCode/C++/Database-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/DatabaseEngine.dir/src/Page.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DatabaseEngine.dir/src/Page.cpp.o -c /home/zhaolingmei/Documents/MyCode/C++/Database-Engine/src/Page.cpp

CMakeFiles/DatabaseEngine.dir/src/Page.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DatabaseEngine.dir/src/Page.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhaolingmei/Documents/MyCode/C++/Database-Engine/src/Page.cpp > CMakeFiles/DatabaseEngine.dir/src/Page.cpp.i

CMakeFiles/DatabaseEngine.dir/src/Page.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DatabaseEngine.dir/src/Page.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhaolingmei/Documents/MyCode/C++/Database-Engine/src/Page.cpp -o CMakeFiles/DatabaseEngine.dir/src/Page.cpp.s

CMakeFiles/DatabaseEngine.dir/src/PageReader.cpp.o: CMakeFiles/DatabaseEngine.dir/flags.make
CMakeFiles/DatabaseEngine.dir/src/PageReader.cpp.o: ../src/PageReader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhaolingmei/Documents/MyCode/C++/Database-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/DatabaseEngine.dir/src/PageReader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DatabaseEngine.dir/src/PageReader.cpp.o -c /home/zhaolingmei/Documents/MyCode/C++/Database-Engine/src/PageReader.cpp

CMakeFiles/DatabaseEngine.dir/src/PageReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DatabaseEngine.dir/src/PageReader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhaolingmei/Documents/MyCode/C++/Database-Engine/src/PageReader.cpp > CMakeFiles/DatabaseEngine.dir/src/PageReader.cpp.i

CMakeFiles/DatabaseEngine.dir/src/PageReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DatabaseEngine.dir/src/PageReader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhaolingmei/Documents/MyCode/C++/Database-Engine/src/PageReader.cpp -o CMakeFiles/DatabaseEngine.dir/src/PageReader.cpp.s

# Object files for target DatabaseEngine
DatabaseEngine_OBJECTS = \
"CMakeFiles/DatabaseEngine.dir/main.cpp.o" \
"CMakeFiles/DatabaseEngine.dir/src/BPlusTree.cpp.o" \
"CMakeFiles/DatabaseEngine.dir/src/DataReader.cpp.o" \
"CMakeFiles/DatabaseEngine.dir/src/DataWriter.cpp.o" \
"CMakeFiles/DatabaseEngine.dir/src/Field.cpp.o" \
"CMakeFiles/DatabaseEngine.dir/src/Page.cpp.o" \
"CMakeFiles/DatabaseEngine.dir/src/PageReader.cpp.o"

# External object files for target DatabaseEngine
DatabaseEngine_EXTERNAL_OBJECTS =

DatabaseEngine: CMakeFiles/DatabaseEngine.dir/main.cpp.o
DatabaseEngine: CMakeFiles/DatabaseEngine.dir/src/BPlusTree.cpp.o
DatabaseEngine: CMakeFiles/DatabaseEngine.dir/src/DataReader.cpp.o
DatabaseEngine: CMakeFiles/DatabaseEngine.dir/src/DataWriter.cpp.o
DatabaseEngine: CMakeFiles/DatabaseEngine.dir/src/Field.cpp.o
DatabaseEngine: CMakeFiles/DatabaseEngine.dir/src/Page.cpp.o
DatabaseEngine: CMakeFiles/DatabaseEngine.dir/src/PageReader.cpp.o
DatabaseEngine: CMakeFiles/DatabaseEngine.dir/build.make
DatabaseEngine: CMakeFiles/DatabaseEngine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zhaolingmei/Documents/MyCode/C++/Database-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable DatabaseEngine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DatabaseEngine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DatabaseEngine.dir/build: DatabaseEngine

.PHONY : CMakeFiles/DatabaseEngine.dir/build

CMakeFiles/DatabaseEngine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DatabaseEngine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DatabaseEngine.dir/clean

CMakeFiles/DatabaseEngine.dir/depend:
	cd /home/zhaolingmei/Documents/MyCode/C++/Database-Engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhaolingmei/Documents/MyCode/C++/Database-Engine /home/zhaolingmei/Documents/MyCode/C++/Database-Engine /home/zhaolingmei/Documents/MyCode/C++/Database-Engine/build /home/zhaolingmei/Documents/MyCode/C++/Database-Engine/build /home/zhaolingmei/Documents/MyCode/C++/Database-Engine/build/CMakeFiles/DatabaseEngine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DatabaseEngine.dir/depend

