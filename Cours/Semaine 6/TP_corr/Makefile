CXXFLAGS = -Wall -g

PROGS = tests

all: $(PROGS)

tests: tests.o matrices.o vector.o
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

tests.o: tests.cpp vector.hpp matrices.hpp GC.hpp
	$(CXX) -c $< $(CXXFLAGS) $(LDFLAGS)

clean:
	-rm -f $(PROGS) *.o *~
