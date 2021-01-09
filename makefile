
VERSION = 0.1

# Windows specific options. (Change to whatever compiler you use).
# =============================================================================
ifeq ($(OS),Windows_NT)
	SUDO = runas /profile

	AR = ar.exe
	CXX = g++.exe
	CXXFLAGS = -lpdcurses
	CXXFLAGS += -I"C:\Program Files (x86)\mingw64\mingw64\include"
	
	INCLUDESINSTALLFOLDER = "C:\Program Files\Git\include"
	LIBRARYINSTALLFOLDER = "C:\Program Files (x86)\mingw64\mingw64\lib"

	STATICLIBNAME = cursedwindows.lib
	SHAREDLIBNAME = cursedwindows.dll
endif 

# Linux specific options.
# =============================================================================
ifeq ($(shell uname -s),Linux)
	SUDO = sudo

	AR = ar
	CXX = g++
	CXXFLAGS = -lncurses -fPIC
	INCLUDESINSTALLFOLDER = /usr/include
	LIBRARYINSTALLFOLDER = /lib

	STATICLIBNAME = libcursedwindows.a
	SHAREDLIBNAME = libcursedwindows.so
endif

# Debug/release compiler flags.
# =============================================================================
ifeq ($(RELEASE), true)
	CXXFLAGS += -O3
endif 
ifeq ($(DEBUG), true)
	CXXFLAGS += -g
endif

# Project folder names.
# =============================================================================
HEADERFOLDER = lib
SOURCEFOLDER = src
OBJECTFOLDER = obj
OUTPUTFOLDER = bin

CXXFLAGS += -I$(HEADERFOLDER) 
ARFLAGS = rcs

SOURCES := $(shell find $(SOURCEFOLDER) | grep -F ".cpp")
OBJECTS := $(patsubst $(SOURCEFOLDER)%.cpp,$(OBJECTFOLDER)%.o,$(SOURCES))

help:
	@echo "Please use one of the following commands:"
	@echo "    [staticlib] to build the static library binary"
	@echo "    [sharedlib] to build the shared library binary"
	@echo "    [documentation] to generate the documentation"
	@echo "    [install] to install the shared library after building"
	@echo "    [uninstall] to remove the current installation of the library"
	@echo "    [clean] to remove/clear build files"

$(OBJECTFOLDER)/%.o: $(SOURCEFOLDER)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OUTPUTFOLDER)/$(STATICLIBNAME): setup $(OBJECTS)
	$(AR) ${ARFLAGS} $(OUTPUTFOLDER)/$(STATICLIBNAME) $(OBJECTS)

$(OUTPUTFOLDER)/$(SHAREDLIBNAME): setup $(OBJECTS)
	$(CXX) $(CXXFLAGS) -shared -o $(OUTPUTFOLDER)/$(SHAREDLIBNAME) $(OBJECTS)

staticlib: $(OUTPUTFOLDER)/$(STATICLIBNAME)
	@echo "Building static library binary"

sharedlib: $(OUTPUTFOLDER)/$(SHAREDLIBNAME)
	@echo "Building shared library binary"

install: $(OUTPUTFOLDER)/$(SHAREDLIBNAME)
	cp -r $(HEADERFOLDER) $(INCLUDESINSTALLFOLDER)/cursedwindows
	cp $(OUTPUTFOLDER)/$(SHAREDLIBNAME) $(LIBRARYINSTALLFOLDER)/$(SHAREDLIBNAME)

uninstall:
	rm -rf $(INCLUDESINSTALLFOLDER)/cursedwindows
	rm -rf $(LIBRARYINSTALLFOLDER)/$(SHAREDLIBNAME)

setup:
	mkdir -p $(OBJECTFOLDER) $(OUTPUTFOLDER)
	mkdir -p obj/layouts obj/widgets

documentation:
	doxygen doxygen.conf
	firefox doc/index.html

clean:
	rm -rf doc/*
	rm -rf $(OUTPUTFOLDER)/*
	rm -rf $(OBJECTFOLDER)/*.o
	rm -rf $(OBJECTFOLDER)/*/*.o
	rm -rf $(OBJECTFOLDER)/*/*/*.o
	rm -rf $(OBJECTFOLDER)/*/*/*/*.o
