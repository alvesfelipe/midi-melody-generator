CXX=g++
INC_MIDIMELODY=-I include/
INC_PSTREAMS=-I ../lib/pstreams-0.8.1
LDFLAGS=-lpython2.7 
PATH_SRC=src/*.cpp test/*.cpp

all: midimelody.bin

midimelody.bin:
	@$(CXX) $(INC_MIDIMELODY) $(INC_PSTREAMS) $(PATH_SRC) -o midimelody.out $(LDFLAGS)

test:
	@./midimelody.out
