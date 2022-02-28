all: comp exec

comp:
	cc -g repl-bf.c -o repl-bf
	#tcc -g repl-bf.c -o repl-bf                         # <- u.u

exec: comp
	./repl-bf

debug: comp
	gdb repl-bf

clean:
	rm repl-bf
