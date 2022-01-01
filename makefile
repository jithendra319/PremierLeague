premierleague.out: main.c sortpt.o 
	gcc main.c sortpt.o -o premierleague.out
	
sortpt.o: sortpt.c sortpoints.h
	gcc -c sortpt.c

clean:
	rm -f *.o *.out


