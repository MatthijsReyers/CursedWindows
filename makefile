
# CXX = g++
# CXXFLAGS = -xc++ -Wall -shared-libgcc -lncursesw -O3
# LIBFILE = cursedwindows.dll

CXX = g++
CXXFLAGS = -xc++ -Wall -shared-libgcc -lncursesw -O3
LIBFILE = cursedwindows

EXECNAME = cursedwindows

HEADERFOLDER = lib
SOURCEFOLDER = src
OBJECTFOLDER = obj
OUTPUTFOLDER = bin

CXXFLAGS += -I $(HEADERFOLDER)

SOURCES := $(shell find $(SOURCEFOLDER) | grep -F ".cpp")
OBJECTS := $(patsubst $(SOURCEFOLDER)%.cpp,$(OBJECTFOLDER)%.o,$(SOURCES))


# setup:
# 	mkdir obj

# $(EXECNAME): $(OBJECTS)

$(OBJECTFOLDER)/%.o: $(SOURCEFOLDER)/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

$(OBJECTFOLDER)/%.o: $(SOURCEFOLDER)/%.c
	$(CXX) $(CXXFLAGS) -o $@ $<

main: $(OBJECTS)
	echo $(OBJECTS)

setup:
	mkdir -p $(OBJECTFOLDER) $(OUTPUTFOLDER)
	mkdir -p obj/layouts
