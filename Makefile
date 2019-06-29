lines: lines.o
	gcc -o lines lines.o

lines.o: lines.c
	gcc -c lines.c
