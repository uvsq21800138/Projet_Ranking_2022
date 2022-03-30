run: ranking
	./ranking Data/wb-cs-stanford.txt wb-cs-st.txt 

ranking : ranking.o list_column.o debug.o IOrank.o vector.o
	gcc -Wall -o ranking ranking.o list_column.o debug.o IOrank.o vector.o
	

ranking.o : ranking.c list_column.h debug.h IOrank.h vector.h
	gcc -Wall -c ranking.c

list_column.o : list_column.c list_column.h
	gcc -Wall -c list_column.c

vector.o : vector.c vector.h
	gcc -Wall -c vector.c

IOrank.o : IOrank.c IOrank.h list_column.o debug.o
	gcc -Wall -c IOrank.c

debug.o : debug.c debug.h
	gcc -Wall -c debug.c

debug: ranking
	valgrind ./ranking  Data/wb-cs-stanford.txt wb-cs-st.txt 
	./ranking  Data/wb-cs-stanford.txt wb-cs-st.txt 

clean :
	rm -rf *.o
	rm -rf ranking
	ls -l
