#source: https://github.com/TheAlgorithms/Python/blob/master/sorts/shell_sort.py
def shellSort(collection):
	gaps = [701, 301, 132, 57, 23, 10, 4, 1]
	for gap in gaps:
		for i in range(gap, len(collection)):
			insert_value = collection[i]
			j = i
			while j >= gap and collection[j - gap] > insert_value:
				collection[j] = collection[j - gap]
				j -= gap
			collection[j] = insert_value
	return collection
