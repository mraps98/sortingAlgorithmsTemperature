#source: https://github.com/TheAlgorithms/Python/blob/master/sorts/selection_sort.py
def selectionSort(collection):
	length = len(collection)
	for i in range(length - 1):
		least = i
		for k in range(i + 1, length):
			if collection[k] < collection[least]:
				least = k
		if least != i:
			collection[least], collection[i] = (collection[i], collection[least])
	return collection
