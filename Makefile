# Based on https://github.com/ocornut/imgui/blob/master/examples/example_glfw_opengl3/Makefile

EXE = monopoly.out
IMGUI_DIR = imgui/
SRC_DIR = src/

SOURCES = $(wildcard $(SRC_DIR)*.cpp) # Get all .cpp files in src
SOURCES += $(IMGUI_DIR)/imgui.cpp $(IMGUI_DIR)/imgui_demo.cpp $(IMGUI_DIR)/imgui_draw.cpp $(IMGUI_DIR)/imgui_tables.cpp $(IMGUI_DIR)/imgui_widgets.cpp $(IMGUI_DIR)/misc/cpp/imgui_stdlib.cpp

UNAME_S := $(shell uname -s)

CXXFLAGS = -std=c++11 -I$(IMGUI_DIR) -I$(IMGUI_DIR)/backends -I$(SRC_DIR) $(shell pkg-config --cflags glfw3)
CXXFLAGS += -g -Wall -Wformat
LIBS = -lGL -lglfw -lrt -lm -ldl


all: $(EXE)
	@echo Build completed.

clean: 
	@rm -f $(EXE) $(OBJS)
	@rm -f imgui.ini

##---------------------------------------------------------------------
## BUILD RULES
##---------------------------------------------------------------------

$(EXE): $(OBJS)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)

$(OBJDIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(IMGUI_DIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(IMGUI_DIR)/backends/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(IMGUI_DIR)/misc/cpp/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@