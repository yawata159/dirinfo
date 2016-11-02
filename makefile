default: dirinfo

dirinfo: dirinfo.c
	gcc -o dirinfo dirinfo.c

run: dirinfo
	./dirinfo

clean:
	-rm *~
	-rm dirinfo
