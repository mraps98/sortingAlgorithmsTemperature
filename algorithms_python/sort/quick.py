#source: https://github.com/TheAlgorithms/Python/blob/master/sorts/quickSort.py
def quickSort(collection):
	if len(collection) < 2:
		return collection
	pivot = collection.pop()  # Use the last element as the first pivot
	greater = []  # All elements greater than pivot
	lesser = []  # All elements less than or equal to pivot
	for element in collection:
		(greater if element > pivot else lesser).append(element)
	return quickSort(lesser) + [pivot] + quickSort(greater)	
