CC=g++
INCPATH = -ID:\work\cpp_test\PDCurses
LIBS = D:\work\cpp_test\PDCurses\wincon\pdcurses.a

all:
	$(CC) $(INCPATH) virt_drawer.cpp border.cpp snake.cpp food.cpp game.cpp main.cpp $(LIBS)  -o snake_con
	
clean:
	rm -rf *.o snake_con