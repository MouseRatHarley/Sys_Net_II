OBJS    = main.o user.o parser.o multiServer.o
CXX     = g++
DEBUG   = -g
CXXFLAGS  = -Wall $(DEBUG) -std=c++11 -pthread
LDFLAGS = -pthread

main: $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LIBS)

clean:
	rm *.o main
