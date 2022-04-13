all: comp exec

comp:
	cc -g bf.c -o bf
	#tcc -g bf.c -o bf                         # <- u.u

exec: comp
	./bf

debug: comp
	gdb bf

clean:
	rm bf
