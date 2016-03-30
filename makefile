sudoku:a.o main.o
	g++ -o sudoku a.o main.o
a.o:a.cpp a.h
	g++ -c a.cpp
main.o:main.cpp a.h
	g++ -c main.cpp
clean:
	rm a.o main.o
