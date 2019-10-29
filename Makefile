CXX=g++
CXXFLAGS= -g -std=c++11 -fPIC -D_FILE_OFFSET_BITS=64 -D_LARGE_FILES -D__WXGTK__

#LIBS= -pthread -lwx_gtk2u_richtext-2.8 -lwx_gtk2u_aui-2.8 -lwx_gtk2u_xrc-2.8 -lwx_gtk2u_qa-2.8 -lwx_gtk2u_html-2.8 -lwx_gtk2u_adv-2.8 -lwx_gtk2u_core-2.8 -lwx_baseu_xml-2.8 -lwx_baseu_net-2.8 -lwx_baseu-2.8
CB_CFLAGS = `pkg-config --cflags codeblocks`
CB_LIBS = `pkg-config --libs codeblocks`

WX_CFLAGS = `wx-config --cflags  --version=2.8`
WX_LIBS = `wx-config --libs  --version=2.8`


SRC_DIR = src
SRC_INCLUDE = include
SRCS = $(SRC_DIR)/Wordfisher.cpp $(SRC_DIR)/History.cpp $(SRC_DIR)/SuccesfullyReplaced.cpp $(SRC_DIR)/ViewerDialog.cpp $(SRC_DIR)/Targets.cpp $(SRC_DIR)/SearchFile.cpp $(SRC_DIR)/HistoryWindow.cpp

TEST_DIR = test
TEST_INCLUDE = test

INCLUDE = -I ${SRC_INCLUDE} -I ${TEST_INCLUDE}

ZIP = zip
ZIP_FLAGS = -j

PLUGIN = Wordfisher
PLUGIN_TEST = test_$(PLUGIN)

.PHONY: all
all: bundle

# default rule for compiling .cc to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(PLUGIN).so $(PLUGIN).zip $(PLUGIN).cbplugin

$(PLUGIN).so: $(SRC_DIR)/$(PLUGIN).cpp
	$(CXX) $(CXXFLAGS) -o $(PLUGIN).o -c $(SRC_DIR)/$(PLUGIN).cpp $(CB_CFLAGS) $(WX_CFLAGS)
	$(CXX) -shared $(PLUGIN).o  -o $(PLUGIN).so $(CB_LIBS) $(WX_LIBS)

bundle: $(PLUGIN).so manifest.xml
		$(ZIP) $(ZIP_FLAGS) $(PLUGIN).zip manifest.xml
		$(ZIP) $(ZIP_FLAGS) $(PLUGIN).cbplugin $(PLUGIN).so $(PLUGIN).zip
