exec=main
cc=gcc
obj=main.o printf.o
cflags=-Wall -g
$(exec):$(obj)
	$(cc) $^ -o $@ $(cflags)
%.o:%.c
	$(cc) -c $< -o $@ $(cflags)
clean:
	rm $(exec) *.o
	
