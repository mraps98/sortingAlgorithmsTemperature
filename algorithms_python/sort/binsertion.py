#source: geeksforgeeks.org/python-program-for-binary-insertion-sort/

def binarySearch(arr, val, start, end):
	if start == end:
		if arr[start] > val:
			return start
		else:
			return start+1

	if start > end:
		return start

	mid = int((start + end) / 2)
	if arr[mid] < val:
		return binarySearch(arr, val, mid+1, end)
	elif arr[mid] > val:
		return binarySearch(arr, val, start, mid-1)
	else:
		return mid

def binsertionSort(arr):
	for i in range(1, len(arr)):
		val = arr[i]
		j = binarySearch(arr, val, 0, i-1)
		arr = arr[:j] + [val] + arr[j:i] + arr[i+1:]

	return arr
