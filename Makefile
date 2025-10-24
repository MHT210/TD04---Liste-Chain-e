run: struct
	./struct


struct: struct.c
	gcc -Wall -o struct struct.c


clean:
	rm -f struct
