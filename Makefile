all:
	touch disk.txt
	rm disk.txt
	gcc lsm.c test.c -o lsm -Wall -g