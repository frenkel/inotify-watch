all:
	gcc -o filesync main.c
	gcc -o svn_test -I /usr/include/apr-1.0/ -lsvn_client-1 svn.c
