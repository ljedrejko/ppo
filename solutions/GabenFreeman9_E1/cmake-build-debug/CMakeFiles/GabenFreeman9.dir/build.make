# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Gaben\C++\Studia\solutions\GabenFreeman9_E1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Gaben\C++\Studia\solutions\GabenFreeman9_E1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\GabenFreeman9.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\GabenFreeman9.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\GabenFreeman9.dir\flags.make

CMakeFiles\GabenFreeman9.dir\main.cpp.obj: CMakeFiles\GabenFreeman9.dir\flags.make
CMakeFiles\GabenFreeman9.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Gaben\C++\Studia\solutions\GabenFreeman9_E1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GabenFreeman9.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\GabenFreeman9.dir\main.cpp.obj /FdCMakeFiles\GabenFreeman9.dir\ /FS -c D:\Gaben\C++\Studia\solutions\GabenFreeman9_E1\main.cpp
<<

CMakeFiles\GabenFreeman9.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GabenFreeman9.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx86\x86\cl.exe > CMakeFiles\GabenFreeman9.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Gaben\C++\Studia\solutions\GabenFreeman9_E1\main.cpp
<<

CMakeFiles\GabenFreeman9.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GabenFreeman9.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\GabenFreeman9.dir\main.cpp.s /c D:\Gaben\C++\Studia\solutions\GabenFreeman9_E1\main.cpp
<<

# Object files for target GabenFreeman9
GabenFreeman9_OBJECTS = \
"CMakeFiles\GabenFreeman9.dir\main.cpp.obj"

# External object files for target GabenFreeman9
GabenFreeman9_EXTERNAL_OBJECTS =

GabenFreeman9.exe: CMakeFiles\GabenFreeman9.dir\main.cpp.obj
GabenFreeman9.exe: CMakeFiles\GabenFreeman9.dir\build.make
GabenFreeman9.exe: CMakeFiles\GabenFreeman9.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Gaben\C++\Studia\solutions\GabenFreeman9_E1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable GabenFreeman9.exe"
	"D:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\GabenFreeman9.dir --rc="D:\Windows Kits\10\bin\10.0.18362.0\x86\rc.exe" --mt="D:\Windows Kits\10\bin\10.0.18362.0\x86\mt.exe" --manifests  -- C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\GabenFreeman9.dir\objects1.rsp @<<
 /out:GabenFreeman9.exe /implib:GabenFreeman9.lib /pdb:D:\Gaben\C++\Studia\solutions\GabenFreeman9_E1\cmake-build-debug\GabenFreeman9.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\GabenFreeman9.dir\build: GabenFreeman9.exe

.PHONY : CMakeFiles\GabenFreeman9.dir\build

CMakeFiles\GabenFreeman9.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\GabenFreeman9.dir\cmake_clean.cmake
.PHONY : CMakeFiles\GabenFreeman9.dir\clean

CMakeFiles\GabenFreeman9.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" D:\Gaben\C++\Studia\solutions\GabenFreeman9_E1 D:\Gaben\C++\Studia\solutions\GabenFreeman9_E1 D:\Gaben\C++\Studia\solutions\GabenFreeman9_E1\cmake-build-debug D:\Gaben\C++\Studia\solutions\GabenFreeman9_E1\cmake-build-debug D:\Gaben\C++\Studia\solutions\GabenFreeman9_E1\cmake-build-debug\CMakeFiles\GabenFreeman9.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\GabenFreeman9.dir\depend

