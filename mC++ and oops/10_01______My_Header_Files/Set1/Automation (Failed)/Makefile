program: main.o defination.o
	g++ main.o defination.o -o program

main.o: main.cpp myheader.h
	g++ -c main.cpp

defination.o: defination.cpp myheader.h
	g++ -c defination.cpp

clean:
	del *.o program
