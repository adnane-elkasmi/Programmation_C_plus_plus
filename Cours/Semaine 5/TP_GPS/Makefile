CXXFLAGS = -Wall -g

PROGS = GPS

all: $(PROGS)

GPS: GPS.o Graphe.o
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

GPS.o: GPS.cpp Graphe.hpp
	$(CXX) -c $< $(CXXFLAGS) $(LDFLAGS)

clean:
	-rm -f $(PROGS) *.o *~
