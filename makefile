var:=$(patsubst %.c, %.o, $(wildcard *.c))
run.exe:$(var)
	gcc -o $@ $^
clean:
	rm *.exe *.o
	
