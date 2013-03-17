###
### Casey Miles
### EECS 560
### Lab 7: Binary Search Tree
###

all: lab7

treeNode.o: treeNode.cpp treeNode.h
	g++ -c -g treeNode.cpp

main.o: main.cpp treeNode.h
	g++ -c -g main.cpp

lab7: main.o treeNode.o
	g++ -g -o lab7 main.o treeNode.o

clean:
	rm -f lab7 *.o

#Make the deliverable tar file. Clean first.
tar-file: clean
	@ cd .. ; \
	tar -cvzf CaseyMiles_Lab7.tar.gz CaseyMiles_Lab7 ; \
	echo "************************************"; \
	echo "****      TAR FILE CREATED      ****"; \
	echo "************************************";
