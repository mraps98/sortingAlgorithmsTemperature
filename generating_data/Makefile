./*.out: ./*.c
	gcc ./int.c -lm -o ./generateIntData.out
	gcc ./long.c -lm -o ./generateLongData.out
	gcc ./random_long_file.c -lm -o generate_random_numbers_file.out


clean:
	rm -f ./data/int/*
	rm -f ./data/long/*
	rm -f ./output/*
	rm -f *.out
