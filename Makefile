# Compiler
CPP = cl.exe
CPPFLAGS = /c /Wall /std:c++latest

# Linker
LINKER = link.exe

# Project's important folders
HEADERS_FOLDER = headers
SOURCES_FOLDER = sources
RESOURCES_FOLDER = resources
LIB_FOLDER = lib
OBJECTS_FOLDER = objects
BUILD_FOLDER = build

# Project's important files
MAIN_SOURCE_FILE = $(SOURCES_FOLDER)\main.cpp
MAIN_OBJECT_FILE = $(OBJECTS_FOLDER)\main.obj

# Libraries' important folders and files
LIB_WINTOAST_FOLDER = $(LIB_FOLDER)\WinToast
LIB_WINTOAST_HEADERS_FOLDER = $(LIB_WINTOAST_FOLDER)\src
LIB_WINTOAST_SOURCE = $(LIB_WINTOAST_HEADERS_FOLDER)\wintoastlib.cpp
LIB_WINTOAST_OBJECT_FILE = $(OBJECTS_FOLDER)\wintoastlib.obj

# Final executable
EXECUTABLE_FILE = $(BUILD_FOLDER)\EyeglassesNotification.exe

# Target for running the installation targets
all: clean build_project schedule

# Target for scheduling a task for running the program
schedule:
	schtasks.exe /Create /SC ONLOGON /DELAY 0000:30 /TN EyeglassesNotification /TR $(MAKEDIR)\$(EXECUTABLE_FILE) /F

# Target for un-scheduling the task
unschedule:
	schtasks.exe /Delete /TN EyeglassesNotification /F

# Target for building the project
build_project:
	$(CPP) $(CPPFLAGS) $(LIB_WINTOAST_SOURCE) /Fo$(MAIN_OBJECT_FILE)
	$(CPP) $(CPPFLAGS) $(MAIN_SOURCE_FILE) /Fo$(LIB_WINTOAST_OBJECT_FILE) /I $(HEADERS_FOLDER) /I $(LIB_WINTOAST_HEADERS_FOLDER)
	$(LINKER) /out:$(EXECUTABLE_FILE) $(MAIN_OBJECT_FILE) $(LIB_WINTOAST_OBJECT_FILE)

# Target for cleaning the project
clean:
	del /Q $(OBJECTS_FOLDER)\*
	del /Q $(BUILD_FOLDER)\*