#source: https://github.com/TheAlgorithms/Python/blob/master/sorts/gnome_sort.py
def gnomeSort(lst):
	if len(lst) <= 1:
		return lst

	i = 1

	while i < len(lst):
		if lst[i - 1] <= lst[i]:
			i += 1
		else:
			lst[i - 1], lst[i] = lst[i], lst[i - 1]
			i -= 1
			if i == 0:
				i = 1

	return lst
