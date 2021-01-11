import sys

# Declaring variables
fileName = ""
sortType = ""
numberOfIterations = 1
dataOriginal = []
data = []

def readDataFromFile():
    global fileName, dataOriginal
    with open(fileName, "r") as f:
        temp = f.readline()
        while temp:
            dataOriginal.append(int(temp))
            temp = f.readline()

def printAllData():
    global dataOriginal
    for n in dataOriginal:
        print(n)


def main():
    # Global variables
    global fileName, sortType, numberOfIterations, data, dataOriginal

    #Get Commandline arguments
    if len(sys.argv) < 3:
        print("Usage python(3) {}, <sortType> <fileName> <numberOfIterations>".format(sys.argv[0]))
        return
    else:
        fileName = sys.argv[2] 
        sortType = sys.argv[1]
        if len(sys.argv) == 4:
            numberOfIterations = int(argv[3])
    
    # Load data form file
    readDataFromFile()

    #print data
    printAllData()


    


if __name__ == "__main__":
    main()
