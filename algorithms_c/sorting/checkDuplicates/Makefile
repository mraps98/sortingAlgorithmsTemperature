./checkDuplicates.out: *.c *.h
	gcc checkDuplicates.c quick.c quick.h -lm -o checkDuplicates.out
	gcc removeDuplicates.c quick.c quick.h -lm -o removeDuplicates.out

clean:
	rm checkDuplicates.out
	rn removeDuplicates.out
	rm -f *sorted.dat
