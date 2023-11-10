SRCS = playMove.cpp GameState.cpp connectfour.cpp
OBJS = $(patsubst %.cpp,%.o,$(SRCS))

connectfour: $(OBJS)
	g++ $^ -o $@
%.o:	%.cpp
	g++ -c -g $< -o $@
clean:
	rm -f *.o  connectfour core

