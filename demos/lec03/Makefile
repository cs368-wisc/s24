myprog : myprog.o libdemo.so
	g++ myprog.o -ldemo -L. -o myprog

myprog.o : myprog.cpp mylib.h
	g++ -c myprog.cpp

libdemo.so : mylib.o
	g++ mylib.o -shared -o libdemo.so

mylib.o : mylib.cpp mylib.h
	g++ -c mylib.cpp -fPIC
