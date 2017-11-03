all: dirinfo.c
	gcc -o dirinfo dirinfo.c

run: all
	./dirinfo

clean:
	rm -f *.o
	rm -f *~
	rm -f dirinfo