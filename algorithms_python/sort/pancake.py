#source: https://github.com/TheAlgorithms/Python/blob/master/sorts/pancake_sort.py
def pancakeSort(arr):
	cur = len(arr)
	while cur > 1:
		# Find the maximum number in arr
		mi = arr.index(max(arr[0:cur]))
        # Reverse from 0 to mi
		arr = arr[mi::-1] + arr[mi + 1 : len(arr)]
		# Reverse whole list
		arr = arr[cur - 1 :: -1] + arr[cur : len(arr)]
		cur -= 1
	return arr
