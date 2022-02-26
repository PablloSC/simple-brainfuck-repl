all: comp exec

comp:
	tcc ./interpreter-bf.c -o interpreter-bf

exec: comp
	./interpreter-bf
