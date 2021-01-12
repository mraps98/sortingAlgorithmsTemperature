#source: https://www.geeksforgeeks.org/recursive-bubble-sort/
def bubbleRecSort(array, n=None):
	if n is None:
		n = len(array)

	if n == 1:
		return
	
	for i in range(n - 1):
		if array[i] > array[i+1]:
			array[i], array[i+1] = array[i+1], array[i]

	bubbleRecSort(array, n-1)
