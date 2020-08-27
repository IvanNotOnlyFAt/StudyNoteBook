test: main.o link.o node.o
	g++ -o test main.o link.o node.o
main.o: main.cpp link.h node.h
	g++ -c main.cpp
link.o: link.cpp node.h
	g++ -c link.cpp
node.o: node.cpp
	g++ -c node.cpp

.PHONY: clean
clean:
	rm -f *.o
