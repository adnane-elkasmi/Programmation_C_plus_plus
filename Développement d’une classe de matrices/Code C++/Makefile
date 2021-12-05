CXXFLAGS = -Wall -g

PROGS = tests

all: $(PROGS)

tests: tests.o vector.o matrix.o
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

tests.o: tests.cpp vector.hpp matrix.hpp
	$(CXX) -c $< $(CXXFLAGS) $(LDFLAGS)

clean:
	-rm -f *.o *~ $(PROGS)
