
VERSION = 0.1

# CXX = g++
# CXXFLAGS = -xc++ -Wall -shared-libgcc -lncursesw -O3
# SHAREDLIBNAME = cursedwindows.dll

CC = gcc
CXX = g++
CXXFLAGS = -lncurses -fPIC
CCFLAGS = -lncursesw -fPIC
INCLUDESINSTALLFOLDER = /usr/include
LIBRARYINSTALLFOLDER = /lib

STATICLIBNAME = libcursedwindows.a
SHAREDLIBNAME = libcursedwindows.so

HEADERFOLDER = lib
SOURCEFOLDER = src
OBJECTFOLDER = obj
OUTPUTFOLDER = bin

CXXFLAGS += -I $(HEADERFOLDER) 
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

$(OBJECTFOLDER)/%.o: $(SOURCEFOLDER)/%.c
	$(CC) $(CCFLAGS) -c -o $@ $<

$(OBJECTFOLDER)/%.o: $(SOURCEFOLDER)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

staticlib: setup $(OBJECTS)
	ar ${ARFLAGS} $(OUTPUTFOLDER)/$(STATICLIBNAME) $(OBJECTS)

sharedlib: setup $(OBJECTS)
	$(CXX) $(CXXFLAGS) -shared $(OBJECTS) -o $(OUTPUTFOLDER)/$(SHAREDLIBNAME)

documentation:
	doxygen doxygen.conf
	firefox doc/index.html

install:
	sudo cp -r $(HEADERFOLDER) $(INCLUDESINSTALLFOLDER)/cursedwindows
	sudo cp $(OUTPUTFOLDER)/$(SHAREDLIBNAME) $(LIBRARYINSTALLFOLDER)/$(SHAREDLIBNAME)

uninstall:
	sudo rm -rf $(INCLUDESINSTALLFOLDER)/cursedwindows
	sudo rm -rf $(LIBRARYINSTALLFOLDER)/$(SHAREDLIBNAME)

setup:
	mkdir -p $(OBJECTFOLDER) $(OUTPUTFOLDER)
	mkdir -p obj/layouts obj/widgets

clean:
	rm -rf doc/*
	rm -rf $(OUTPUTFOLDER)/*
	rm -rf $(OBJECTFOLDER)/*.o
	rm -rf $(OBJECTFOLDER)/*/*.o
	rm -rf $(OBJECTFOLDER)/*/*/*.o
	rm -rf $(OBJECTFOLDER)/*/*/*/*.o
