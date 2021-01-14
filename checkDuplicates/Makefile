./checkDuplicates.out ./removeDuplicates.out: *.c *.h
	gcc -g checkDuplicates.c quick.c quick.h -lm -o checkDuplicates.out
	gcc -g removeDuplicates.c quick.c quick.h quickt.c quickt.h -lm -o removeDuplicates.out

clean:
	rm -f checkDuplicates.out
	rm -f removeDuplicates.out
	rm -f *sorted.dat
	rm -f *.log
