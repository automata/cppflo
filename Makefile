CXX_STD=c++11
CPP=g++

BUILD_DIR=$(shell echo `pwd`/build)
THIRDPARTY=$(shell echo `pwd`/thirdparty)

CXXFLAGS=-I$(THIRDPARTY)/json11/ -I$(THIRDPARTY)/websocketpp/
LDFLAGS=-lboost_system -pthread

all: cppflo

dirs:
	mkdir -p $(BUILD_DIR)

cppflo: dirs
	$(CPP) -std=$(CXX_STD) -o $(BUILD_DIR)/cppflo ./src/*.cpp $(CXXFLAGS) $(LDFLAGS)
