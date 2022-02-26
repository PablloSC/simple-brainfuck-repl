all: comp exec ascci

comp:
	tcc ./interpreter-bf.c -o interpreter-bf

exec: comp
	./interpreter-bf

ascci: comp_ascci
	./ascci

comp_ascci:
	tcc ./ascii.c -o ascci
