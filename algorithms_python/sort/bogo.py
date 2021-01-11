#source: https://github.com/TheAlgorithms/Python/blob/master/sorts/bogo_sort.py
import random
def bogoSort(collection):
	def is_sorted(collection):
		if len(collection) < 2:
			return True
		for i in range(len(collection) - 1):
			if collection[i] > collection[i + 1]:
				return False
		return True

	while not is_sorted(collection):
		random.shuffle(collection)
	return collection
