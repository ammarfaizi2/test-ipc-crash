
CXX=g++
CXX_FLAGS= -ggdb3 -Og -std=c++2a -Wall -Wextra -I.
LINK_LIBS= -lrt -lpthread

all: worker dispatcher

worker: worker.cpp
	$(CXX) $(CXX_FLAGS) $(<) -o $(@) $(LINK_LIBS)

dispatcher: dispatcher.cpp
	$(CXX) $(CXX_FLAGS) $(<) -o $(@) $(LINK_LIBS)
