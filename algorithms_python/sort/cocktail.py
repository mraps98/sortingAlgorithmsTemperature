#source: https://github.com/TheAlgorithms/Python/blob/master/sorts/cocktail_shaker_sort.py
def cocktailSort(unsorted):
	for i in range(len(unsorted) - 1, 0, -1):
		swapped = False

		for j in range(i, 0, -1):
			if unsorted[j] < unsorted[j - 1]:
				unsorted[j], unsorted[j - 1] = unsorted[j - 1], unsorted[j]
				swapped = True

		for j in range(i):
			if unsorted[j] > unsorted[j + 1]:
				unsorted[j], unsorted[j + 1] = unsorted[j + 1], unsorted[j]
				swapped = True

		if not swapped:
			return unsorted 
