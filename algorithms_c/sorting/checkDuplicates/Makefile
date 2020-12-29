./checkDuplicates.out: *.c *.h
	gcc checkDuplicates.c quick.c quick.h -lm -o checkDuplicates.out
	gcc removeDuplicates.c quickt.c quickt.h -lm -o removeDuplicates.out

clean:
	rm -f checkDuplicates.out
	rm -f removeDuplicates.out
	rm -f *sorted.dat
