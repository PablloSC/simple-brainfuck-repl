all: comp exec

comp:
	tcc ./repl-bf.c -o repl-bf

exec: comp
	./repl-bf

ascci: comp_ascci
	./ascci | less

comp_ascci:
	tcc ./ascii.c -o ascci
