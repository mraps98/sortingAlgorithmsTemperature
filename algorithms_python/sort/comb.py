# source: https://github.com/TheAlgorithms/Python/blob/master/sorts/comb_sort.py
def combSort(data):
	shrink_factor = 1.3
	gap = len(data)
	completed = False

	while not completed:

		# Update the gap value for a next comb
		gap = int(gap / shrink_factor)
		if gap <= 1:
			completed = True

		index = 0
		while index + gap < len(data):
			if data[index] > data[index + gap]:
                # Swap values
				data[index], data[index + gap] = data[index + gap], data[index]
				completed = False
			index += 1

	return data
