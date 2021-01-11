#source: https://github.com/TheAlgorithms/Python/blob/master/sorts/cycle_sort.py
def cycleSort(array):
	array_len = len(array)
	for cycle_start in range(0, array_len - 1):
		item = array[cycle_start]

		pos = cycle_start
		for i in range(cycle_start + 1, array_len):
			if array[i] < item:
				pos += 1

		if pos == cycle_start:
			continue

		while item == array[pos]:
			pos += 1

		array[pos], item = item, array[pos]
		while pos != cycle_start:
			pos = cycle_start
			for i in range(cycle_start + 1, array_len):
				if array[i] < item:
					pos += 1

			while item == array[pos]:
				pos += 1

			array[pos], item = item, array[pos]

	return array
