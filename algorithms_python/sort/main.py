import sys
import time
from datetime import datetime

# import sorts
from bead import beadSort
from binsertion import binsertionSort 
from bogo import bogoSort
from bubble import bubbleSort
from bubble_rec import bubbleRecSort
from cocktail import cocktailSort
from comb import combSort
from cycle import cycleSort
from gnome import gnomeSort
from heap import heapSort
from insertion import insertionSort
from insertion_rec import insertionRecSort
from merge import mergeSort
from mergebu import mergebuSort
from pancake import pancakeSort
from quick import quickSort
from radix import radixSort
from selection import selectionSort
from shell import shellSort
from tim import timSort
from tree import treeSort

# Declaring variables
fileName = ""
sortType = ""
numberOfItems = 0
numberOfIterations = 1
dataOriginal = []
data = []
DEBUG_MODE = False 
totalCopyingTime = 0
totalCpuTime = 0
averageCpuTime = 0

def getNumItemsInFile():
	global numberOfItems
	with open(fileName, "r") as f:
		lines = f.readlines()
		numberOfItems = len(lines)

def readDataFromFile():
	if DEBUG_MODE:
		print("Started loading data at ", end="")
		printCurrentTime()

	global fileName, dataOriginal
	with open(fileName, "r") as f:
		temp = f.readline()
		while temp:
			dataOriginal.append(int(temp))
			temp = f.readline()

	if DEBUG_MODE:
		print("Ended loading data at ", end="")
		printCurrentTime()

def printAllData():
    global dataOriginal
    for n in dataOriginal:
        print(n)

def isSorted(a):
	if(len(a) == 0):
		return False
	flag = 0
	i = 1
	while i < len(a): 
		if(a[i] < a[i - 1]): 
			flag = 1
		i += 1
	if not flag:
		return True
	else:
		return False

def copyList():
	global data, dataOriginal, totalCopyingTime
	start = time.time()
	data = dataOriginal
	end = time.time()
	totalCopyingTime = totalCopyingTime + (end - start)
	if DEBUG_MODE:
		print("Time taken to copy data_original to data: {}".format(end-start))

def printCurrentTime():
	now = datetime.now().time()
	print(now)

def main():
	# Global variables
	global fileName, sortType, numberOfIterations, data, dataOriginal, DEBUG_MODE, totalCpuTime, averageCpuTime

	if DEBUG_MODE:
		print("Started program at: ", end="")
		printCurrentTime()

	#Get Commandline arguments
	if len(sys.argv) < 3:
		print("Usage python(3) {}, <sortType> <fileName> <numberOfIterations>".format(sys.argv[0]))
		return
	else:
		fileName = sys.argv[2] 
		sortType = sys.argv[1]
	if len(sys.argv) == 4:
		numberOfIterations = int(sys.argv[3])

	# Get num items in file
	getNumItemsInFile()

	if not DEBUG_MODE:
		print("{}, {}, {}, *, ".format(sortType, fileName, numberOfIterations), end="")
		printCurrentTime()
	else:
		print("Sort type = {} and number of items is {} and number of iterations is {}".format(sortType, numberOfItems, numberOfIterations))
    
    # Load data form file
	readDataFromFile()

    # Sort based on sort type
	if(sortType == "bead"):
		for i in range(numberOfIterations):
			copyList()
			if not DEBUG_MODE:
				print("{}, {}, {}, {}/{}, ".format(sortType, fileName, numberOfIterations, i+1, numberOfIterations), end="")
				printCurrentTime()
			else:
				print("Started iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
			start = time.time()
			data = beadSort(data)	
			end = time.time()
			totalCpuTime = totalCpuTime + (end - start)
			if DEBUG_MODE:
				print("Stopped iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
	elif(sortType == "binsertion"):
		for i in range(numberOfIterations):
			copyList()
			if not DEBUG_MODE:
				print("{}, {}, {}, {}/{}, ".format(sortType, fileName, numberOfIterations, i+1, numberOfIterations), end="")
				printCurrentTime()
			else:
				print("Started iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
			start = time.time()
			data = binsertionSort(data)	
			end = time.time()
			totalCpuTime = totalCpuTime + (end - start)
			if DEBUG_MODE:
				print("Stopped iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
	elif(sortType == "bogo"):
		for i in range(numberOfIterations):
			copyList()
			if not DEBUG_MODE:
				print("{}, {}, {}, {}/{}, ".format(sortType, fileName, numberOfIterations, i+1, numberOfIterations), end="")
				printCurrentTime()
			else:
				print("Started iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
			start = time.time()
			bogoSort(data)	
			end = time.time()
			totalCpuTime = totalCpuTime + (end - start)
			if DEBUG_MODE:
				print("Stopped iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
	elif(sortType == "bubble"):
		for i in range(numberOfIterations):
			copyList()
			if not DEBUG_MODE:
				print("{}, {}, {}, {}/{}, ".format(sortType, fileName, numberOfIterations, i+1, numberOfIterations), end="")
				printCurrentTime()
			else:
				print("Started iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
			start = time.time()
			bubbleSort(data)	
			end = time.time()
			totalCpuTime = totalCpuTime + (end - start)
			if DEBUG_MODE:
				print("Stopped iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
	elif(sortType == "bubble_rec"):
		for i in range(numberOfIterations):
			copyList()
			if not DEBUG_MODE:
				print("{}, {}, {}, {}/{}, ".format(sortType, fileName, numberOfIterations, i+1, numberOfIterations), end="")
				printCurrentTime()
			else:
				print("Started iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
			start = time.time()
			bubbleRecSort(data)	
			end = time.time()
			totalCpuTime = totalCpuTime + (end - start)
			if DEBUG_MODE:
				print("Stopped iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
	elif(sortType == "cocktail"):
		for i in range(numberOfIterations):
			copyList()
			if not DEBUG_MODE:
				print("{}, {}, {}, {}/{}, ".format(sortType, fileName, numberOfIterations, i+1, numberOfIterations), end="")
				printCurrentTime()
			else:
				print("Started iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
			start = time.time()
			cocktailSort(data)	
			end = time.time()
			totalCpuTime = totalCpuTime + (end - start)
			if DEBUG_MODE:
				print("Stopped iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
	elif(sortType == "comb"):
		for i in range(numberOfIterations):
			copyList()
			if not DEBUG_MODE:
				print("{}, {}, {}, {}/{}, ".format(sortType, fileName, numberOfIterations, i+1, numberOfIterations), end="")
				printCurrentTime()
			else:
				print("Started iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
			start = time.time()
			combSort(data)	
			end = time.time()
			totalCpuTime = totalCpuTime + (end - start)
			if DEBUG_MODE:
				print("Stopped iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
	elif(sortType == "cycle"):
		for i in range(numberOfIterations):
			copyList()
			if not DEBUG_MODE:
				print("{}, {}, {}, {}/{}, ".format(sortType, fileName, numberOfIterations, i+1, numberOfIterations), end="")
				printCurrentTime()
			else:
				print("Started iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
			start = time.time()
			cycleSort(data)	
			end = time.time()
			totalCpuTime = totalCpuTime + (end - start)
			if DEBUG_MODE:
				print("Stopped iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
	elif(sortType == "gnome"):
		for i in range(numberOfIterations):
			copyList()
			if not DEBUG_MODE:
				print("{}, {}, {}, {}/{}, ".format(sortType, fileName, numberOfIterations, i+1, numberOfIterations), end="")
				printCurrentTime()
			else:
				print("Started iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
			start = time.time()
			gnomeSort(data)	
			end = time.time()
			totalCpuTime = totalCpuTime + (end - start)
			if DEBUG_MODE:
				print("Stopped iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
	elif(sortType == "heap"):
		for i in range(numberOfIterations):
			copyList()
			if not DEBUG_MODE:
				print("{}, {}, {}, {}/{}, ".format(sortType, fileName, numberOfIterations, i+1, numberOfIterations), end="")
				printCurrentTime()
			else:
				print("Started iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
			start = time.time()
			heapSort(data)	
			end = time.time()
			totalCpuTime = totalCpuTime + (end - start)
			if DEBUG_MODE:
				print("Stopped iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
	elif(sortType == "insertion"):
		for i in range(numberOfIterations):
			copyList()
			if not DEBUG_MODE:
				print("{}, {}, {}, {}/{}, ".format(sortType, fileName, numberOfIterations, i+1, numberOfIterations), end="")
				printCurrentTime()
			else:
				print("Started iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
			start = time.time()
			insertionSort(data)	
			end = time.time()
			totalCpuTime = totalCpuTime + (end - start)
			if DEBUG_MODE:
				print("Stopped iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
	elif(sortType == "insertion_rec"):
		for i in range(numberOfIterations):
			copyList()
			if not DEBUG_MODE:
				print("{}, {}, {}, {}/{}, ".format(sortType, fileName, numberOfIterations, i+1, numberOfIterations), end="")
				printCurrentTime()
			else:
				print("Started iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
			start = time.time()
			insertionRecSort(data, len(data))	
			end = time.time()
			totalCpuTime = totalCpuTime + (end - start)
			if DEBUG_MODE:
				print("Stopped iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
	elif(sortType == "merge"):
		for i in range(numberOfIterations):
			copyList()
			if not DEBUG_MODE:
				print("{}, {}, {}, {}/{}, ".format(sortType, fileName, numberOfIterations, i+1, numberOfIterations), end="")
				printCurrentTime()
			else:
				print("Started iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
			start = time.time()
			data = mergeSort(data)	
			end = time.time()
			totalCpuTime = totalCpuTime + (end - start)
			if DEBUG_MODE:
				print("Stopped iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
	elif(sortType == "mergebu"):
		for i in range(numberOfIterations):
			copyList()
			if not DEBUG_MODE:
				print("{}, {}, {}, {}/{}, ".format(sortType, fileName, numberOfIterations, i+1, numberOfIterations), end="")
				printCurrentTime()
			else:
				print("Started iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
			start = time.time()
			data = mergebuSort(data)	
			end = time.time()
			totalCpuTime = totalCpuTime + (end - start)
			if DEBUG_MODE:
				print("Stopped iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
	elif(sortType == "pancake"):
		for i in range(numberOfIterations):
			copyList()
			if not DEBUG_MODE:
				print("{}, {}, {}, {}/{}, ".format(sortType, fileName, numberOfIterations, i+1, numberOfIterations), end="")
				printCurrentTime()
			else:
				print("Started iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
			start = time.time()
			data = pancakeSort(data)	
			end = time.time()
			totalCpuTime = totalCpuTime + (end - start)
			if DEBUG_MODE:
				print("Stopped iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
	elif(sortType == "quick"):
		for i in range(numberOfIterations):
			copyList()
			if not DEBUG_MODE:
				print("{}, {}, {}, {}/{}, ".format(sortType, fileName, numberOfIterations, i+1, numberOfIterations), end="")
				printCurrentTime()
			else:
				print("Started iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
			start = time.time()
			data = quickSort(data)	
			end = time.time()
			totalCpuTime = totalCpuTime + (end - start)
			if DEBUG_MODE:
				print("Stopped iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
	elif(sortType == "radix"):
		for i in range(numberOfIterations):
			copyList()
			if not DEBUG_MODE:
				print("{}, {}, {}, {}/{}, ".format(sortType, fileName, numberOfIterations, i+1, numberOfIterations), end="")
				printCurrentTime()
			else:
				print("Started iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
			start = time.time()
			data = radixSort(data)	
			end = time.time()
			totalCpuTime = totalCpuTime + (end - start)
			if DEBUG_MODE:
				print("Stopped iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
	elif(sortType == "selection"):
		for i in range(numberOfIterations):
			copyList()
			if not DEBUG_MODE:
				print("{}, {}, {}, {}/{}, ".format(sortType, fileName, numberOfIterations, i+1, numberOfIterations), end="")
				printCurrentTime()
			else:
				print("Started iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
			start = time.time()
			data = selectionSort(data)	
			end = time.time()
			totalCpuTime = totalCpuTime + (end - start)
			if DEBUG_MODE:
				print("Stopped iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
	elif(sortType == "shell"):
		for i in range(numberOfIterations):
			copyList()
			if not DEBUG_MODE:
				print("{}, {}, {}, {}/{}, ".format(sortType, fileName, numberOfIterations, i+1, numberOfIterations), end="")
				printCurrentTime()
			else:
				print("Started iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
			start = time.time()
			data = shellSort(data)	
			end = time.time()
			totalCpuTime = totalCpuTime + (end - start)
			if DEBUG_MODE:
				print("Stopped iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
	elif(sortType == "tim"):
		for i in range(numberOfIterations):
			copyList()
			if not DEBUG_MODE:
				print("{}, {}, {}, {}/{}, ".format(sortType, fileName, numberOfIterations, i+1, numberOfIterations), end="")
				printCurrentTime()
			else:
				print("Started iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
			start = time.time()
			data = timSort(data)	
			end = time.time()
			totalCpuTime = totalCpuTime + (end - start)
			if DEBUG_MODE:
				print("Stopped iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
	elif(sortType == "tree"):
		for i in range(numberOfIterations):
			copyList()
			if not DEBUG_MODE:
				print("{}, {}, {}, {}/{}, ".format(sortType, fileName, numberOfIterations, i+1, numberOfIterations), end="")
				printCurrentTime()
			else:
				print("Started iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
			start = time.time()
			data = treeSort(data)	
			end = time.time()
			totalCpuTime = totalCpuTime + (end - start)
			if DEBUG_MODE:
				print("Stopped iteration {} of sorting data at ".format(i+1), end="")
				printCurrentTime()
	else:
		print("Unknown sortType entered: {}".format(sortType))
		return
		
	#Check if sorted
	#print(isSorted(data))

	averageCpuTime = totalCpuTime / numberOfIterations
	if not DEBUG_MODE:
		print("{}, {}, {}, #, {}, {}, ".format(sortType, fileName, numberOfIterations, averageCpuTime, round(totalCopyingTime, 10)), end="")
		printCurrentTime()
	else:
		print("Total time taken for {} iterations is {} seconds".format(numberOfIterations, totalCpuTime))
		print("Average time taken for {} iterations is {} seconds".format(numberOfIterations, averageCpuTime))
		if(isSorted(data)):
			print("Validation: Array has been sorted")
		else:
			print("validation: Array not sorted")
		print("Ended program at: ", end="")
		printCurrentTime()

if __name__ == "__main__":
    main()
