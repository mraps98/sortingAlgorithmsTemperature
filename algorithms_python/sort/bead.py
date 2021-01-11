#source: https://github.com/TheAlgorithms/Python/blob/master/sorts/bead_sort.py
def beadSort(sequence):
	if any(not isinstance(x, int) or x < 0 for x in sequence):
		raise TypeError("Sequence must be list of nonnegative integers")
	for _ in range(len(sequence)):
		for i, (rod_upper, rod_lower) in enumerate(zip(sequence, sequence[1:])):
			if rod_upper > rod_lower:
				sequence[i] -= rod_upper - rod_lower
				sequence[i + 1] += rod_upper - rod_lower
	return sequence
