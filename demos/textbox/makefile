
CXX = g++
# CXXFLAGS = -lncursesw 
CXXFLAGS = -lncurses

HEADERFOLDER = src
SOURCEFOLDER = src
OBJECTFOLDER = obj
OUTPUTFOLDER = bin

CXXFLAGS += -g -I $(HEADERFOLDER) -I./../../lib -L./../../bin/ -lcursedwindows

SOURCES := $(shell find $(SOURCEFOLDER) | grep -F ".cpp")
OBJECTS := $(patsubst $(SOURCEFOLDER)%.cpp,$(OBJECTFOLDER)%.o,$(SOURCES))

EXECNAME = textbox

main: setup $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(OUTPUTFOLDER)/$(EXECNAME)

$(OBJECTFOLDER)/%.o: $(SOURCEFOLDER)/%.c
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJECTFOLDER)/%.o: $(SOURCEFOLDER)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

run:
	./$(OUTPUTFOLDER)/$(EXECNAME)

setup:
	mkdir -p $(OBJECTFOLDER) $(OUTPUTFOLDER)

clean:
	rm -rf obj/*.o
	rm -rf obj/*/*.o
	rm -rf obj/*/*/*.o
	rm -rf obj/*/*/*/*.o