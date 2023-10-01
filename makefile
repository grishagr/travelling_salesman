CFLAGS=-Wall -Werror -Wfatal-errors

travel: travel.o singly_linked_list.o
	g++ -o travel travel.o singly_linked_list.o

travel.o: travel.cpp singly_linked_list.h
	g++ -c $(CFLAGS) travel.cpp

signly_linked_list.o: singly_linked_list.cpp singly_linked_list.h
	g++ -c $(CFLAGS) singly_linked_list.cpp

clean:
	rm -rf *.o main