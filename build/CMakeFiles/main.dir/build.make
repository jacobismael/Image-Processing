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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.17.0_1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.17.0_1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jacob/projects/ocv

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jacob/projects/ocv/build

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/src/box.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/box.cpp.o: ../src/box.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jacob/projects/ocv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/src/box.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/box.cpp.o -c /Users/jacob/projects/ocv/src/box.cpp

CMakeFiles/main.dir/src/box.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/box.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jacob/projects/ocv/src/box.cpp > CMakeFiles/main.dir/src/box.cpp.i

CMakeFiles/main.dir/src/box.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/box.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jacob/projects/ocv/src/box.cpp -o CMakeFiles/main.dir/src/box.cpp.s

CMakeFiles/main.dir/src/image.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/image.cpp.o: ../src/image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jacob/projects/ocv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/src/image.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/image.cpp.o -c /Users/jacob/projects/ocv/src/image.cpp

CMakeFiles/main.dir/src/image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/image.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jacob/projects/ocv/src/image.cpp > CMakeFiles/main.dir/src/image.cpp.i

CMakeFiles/main.dir/src/image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/image.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jacob/projects/ocv/src/image.cpp -o CMakeFiles/main.dir/src/image.cpp.s

CMakeFiles/main.dir/src/main.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jacob/projects/ocv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/src/main.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/main.cpp.o -c /Users/jacob/projects/ocv/src/main.cpp

CMakeFiles/main.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jacob/projects/ocv/src/main.cpp > CMakeFiles/main.dir/src/main.cpp.i

CMakeFiles/main.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jacob/projects/ocv/src/main.cpp -o CMakeFiles/main.dir/src/main.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/src/box.cpp.o" \
"CMakeFiles/main.dir/src/image.cpp.o" \
"CMakeFiles/main.dir/src/main.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/src/box.cpp.o
main: CMakeFiles/main.dir/src/image.cpp.o
main: CMakeFiles/main.dir/src/main.cpp.o
main: CMakeFiles/main.dir/build.make
main: /usr/local/lib/libopencv_gapi.4.2.0.dylib
main: /usr/local/lib/libopencv_stitching.4.2.0.dylib
main: /usr/local/lib/libopencv_aruco.4.2.0.dylib
main: /usr/local/lib/libopencv_bgsegm.4.2.0.dylib
main: /usr/local/lib/libopencv_bioinspired.4.2.0.dylib
main: /usr/local/lib/libopencv_ccalib.4.2.0.dylib
main: /usr/local/lib/libopencv_dnn_objdetect.4.2.0.dylib
main: /usr/local/lib/libopencv_dnn_superres.4.2.0.dylib
main: /usr/local/lib/libopencv_dpm.4.2.0.dylib
main: /usr/local/lib/libopencv_face.4.2.0.dylib
main: /usr/local/lib/libopencv_freetype.4.2.0.dylib
main: /usr/local/lib/libopencv_fuzzy.4.2.0.dylib
main: /usr/local/lib/libopencv_hfs.4.2.0.dylib
main: /usr/local/lib/libopencv_img_hash.4.2.0.dylib
main: /usr/local/lib/libopencv_line_descriptor.4.2.0.dylib
main: /usr/local/lib/libopencv_quality.4.2.0.dylib
main: /usr/local/lib/libopencv_reg.4.2.0.dylib
main: /usr/local/lib/libopencv_rgbd.4.2.0.dylib
main: /usr/local/lib/libopencv_saliency.4.2.0.dylib
main: /usr/local/lib/libopencv_sfm.4.2.0.dylib
main: /usr/local/lib/libopencv_stereo.4.2.0.dylib
main: /usr/local/lib/libopencv_structured_light.4.2.0.dylib
main: /usr/local/lib/libopencv_superres.4.2.0.dylib
main: /usr/local/lib/libopencv_surface_matching.4.2.0.dylib
main: /usr/local/lib/libopencv_tracking.4.2.0.dylib
main: /usr/local/lib/libopencv_videostab.4.2.0.dylib
main: /usr/local/lib/libopencv_xfeatures2d.4.2.0.dylib
main: /usr/local/lib/libopencv_xobjdetect.4.2.0.dylib
main: /usr/local/lib/libopencv_xphoto.4.2.0.dylib
main: /usr/local/lib/libopencv_highgui.4.2.0.dylib
main: /usr/local/lib/libopencv_shape.4.2.0.dylib
main: /usr/local/lib/libopencv_datasets.4.2.0.dylib
main: /usr/local/lib/libopencv_plot.4.2.0.dylib
main: /usr/local/lib/libopencv_text.4.2.0.dylib
main: /usr/local/lib/libopencv_dnn.4.2.0.dylib
main: /usr/local/lib/libopencv_ml.4.2.0.dylib
main: /usr/local/lib/libopencv_phase_unwrapping.4.2.0.dylib
main: /usr/local/lib/libopencv_optflow.4.2.0.dylib
main: /usr/local/lib/libopencv_ximgproc.4.2.0.dylib
main: /usr/local/lib/libopencv_video.4.2.0.dylib
main: /usr/local/lib/libopencv_videoio.4.2.0.dylib
main: /usr/local/lib/libopencv_imgcodecs.4.2.0.dylib
main: /usr/local/lib/libopencv_objdetect.4.2.0.dylib
main: /usr/local/lib/libopencv_calib3d.4.2.0.dylib
main: /usr/local/lib/libopencv_features2d.4.2.0.dylib
main: /usr/local/lib/libopencv_flann.4.2.0.dylib
main: /usr/local/lib/libopencv_photo.4.2.0.dylib
main: /usr/local/lib/libopencv_imgproc.4.2.0.dylib
main: /usr/local/lib/libopencv_core.4.2.0.dylib
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jacob/projects/ocv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main

.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /Users/jacob/projects/ocv/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jacob/projects/ocv /Users/jacob/projects/ocv /Users/jacob/projects/ocv/build /Users/jacob/projects/ocv/build /Users/jacob/projects/ocv/build/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

