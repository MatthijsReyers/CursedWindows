
# CXX = g++
# CXXFLAGS = -xc++ -Wall -shared-libgcc -lncursesw -O3
# LIBFILE = cursedwindows.dll

CC = gcc
CXX = g++
CXXFLAGS = -lncurses -fPIC
CCFLAGS = -lncursesw -fPIC

LIBNAME = libcursedwindows

HEADERFOLDER = lib
SOURCEFOLDER = src
OBJECTFOLDER = obj
OUTPUTFOLDER = bin

CXXFLAGS += -I $(HEADERFOLDER) 
ARFLAGS = rcs

SOURCES := $(shell find $(SOURCEFOLDER) | grep -F ".cpp")
OBJECTS := $(patsubst $(SOURCEFOLDER)%.cpp,$(OBJECTFOLDER)%.o,$(SOURCES))


$(OBJECTFOLDER)/%.o: $(SOURCEFOLDER)/%.c
	$(CC) $(CCFLAGS) -c -o $@ $<

$(OBJECTFOLDER)/%.o: $(SOURCEFOLDER)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

staticlib: $(OBJECTS)
	ar ${ARFLAGS} $(OUTPUTFOLDER)/$(LIBNAME).a $(OBJECTS)

sharedlib: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -shared $(OBJECTS) -o $(OUTPUTFOLDER)/$(LIBNAME).so

documentation:
	doxygen doxygen.config

setup:
	mkdir -p $(OBJECTFOLDER) $(OUTPUTFOLDER)
	mkdir -p obj/layouts obj/widgets

clean:
	rm -rf $(OUTPUTFOLDER)/*
	rm -rf $(OBJECTFOLDER)/*.o
	rm -rf $(OBJECTFOLDER)/*/*.o
	rm -rf $(OBJECTFOLDER)/*/*/*.o
	rm -rf $(OBJECTFOLDER)/*/*/*/*.o

