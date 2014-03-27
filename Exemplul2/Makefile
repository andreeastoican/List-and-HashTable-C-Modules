build: hashtable

hashtable: exemplul2.o hashtable.o list.o hash.o
	gcc -Wall -o hashtable exemplul2.o hashtable.o list.o hash.o

exemplul2.o: Exemplul2.c list.h hashtable.h
	gcc -Wall -o exemplul2.o -c Exemplul2.c

hashtable.o: hashtable.c list.h hash.h hashtable.h
	gcc -Wall -o hashtable.o -c hashtable.c

list.o: list.c list.h
	gcc -Wall -o list.o -c list.c

hash.o: hash.c
	gcc -Wall -o hash.o -c hash.c

clean:
	rm -f *.o hashtable
