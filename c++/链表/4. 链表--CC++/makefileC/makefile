test: main.o link.o node.o
	gcc -o test main.o link.o node.o
main.o: main.cpp link.h node.h
	gcc -c main.c
link.o: link.cpp node.h
	gcc -c link.c
node.o: node.cpp
	gcc -c node.c

.PHONY: clean
clean:
	rm -f *.o
