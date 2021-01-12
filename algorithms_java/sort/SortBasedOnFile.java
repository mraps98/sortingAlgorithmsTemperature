import java.io.FileReader;
import java.io.BufferedReader;
import java.util.Scanner;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Arrays;

public class SortBasedOnFile{
		
	/* Declare Variables */
	private static int numberOfItems;
	private static Long dataOriginal[];
	private static Long data[];
	private static String sortType;
	private static String fileName;
	private static int numberOfIterations;
	private static final boolean DEBUG_MODE = false;
	private static double start, end, totalCpuTime, averageCpuTime, totalCopyingTime;
	
	private static boolean less(Comparable v, Comparable w){
		return (v.compareTo(w) < 0);
	}
	
	private static void exch(Comparable[] a, int i, int j){
		Comparable swap = a[i];
		a[i] = a[j];
		a[j] = swap;
		swap = null;
	}

	private static int getNumberOfItemsInFile(){
		int itemCount = 0;
		try{
			BufferedReader reader = new BufferedReader(new FileReader(fileName));
			while(reader.readLine() != null){
				itemCount++;
			}
		}catch(FileNotFoundException e){
			System.out.println("File not found");
			e.printStackTrace();
			System.exit(-1);
		}catch(IOException e){
			e.printStackTrace();
		}
		return itemCount;
	}

	private static void loadDataFromFile(){
		try{
			dataOriginal = new Long[numberOfItems];
			data = new Long[numberOfItems];
			BufferedReader reader = new BufferedReader(new FileReader(fileName));

			String line = reader.readLine();
			int itemCount = 0;
			while(line != null){
				dataOriginal[itemCount] = Long.parseLong(line);
				itemCount++;
				line = reader.readLine();
			}
		}catch(FileNotFoundException e){
			System.out.println("File not found");
			e.printStackTrace();
			System.exit(-1);
		}catch(IOException e){
			e.printStackTrace();
		}
	}

	private static void copyDataFromOriginal(){
		start = System.nanoTime();
		for(int i = 0; i < numberOfItems; i++){
			data[i] = dataOriginal[i];	
		}
		end = System.nanoTime();
		totalCopyingTime += (end - start) / 100000000;
		if(DEBUG_MODE){
			System.out.printf("Time taken to copy dataOriginal to data: %f\n", (end - start) / 1000000);
		}
	}
	
	private static boolean isSorted(Comparable[] a) {
        return isSorted(a, 0, a.length - 1);
    }
        
    // is the array sorted from a[lo] to a[hi]
    private static boolean isSorted(Comparable[] a, int lo, int hi) {
        for (int i = lo + 1; i <= hi; i++)
            if (less(a[i], a[i-1])) return false;
        return true;
    }

	private static void printCurrentTime(){
		System.out.println(java.time.LocalTime.now());
	}

	public static void main(String[] args){
		if(DEBUG_MODE){
			System.out.print("Started program at: ");
			printCurrentTime();
		}
		/* If haven't specified required commandline arguments */
		if(args.length < 2){
			System.out.println("Usage SortbasedOnFile <sort_type> <file_name> <iterations?>");
			System.exit(-1);	
		}

		/* Get command line arguments */
		sortType = args[0];
		fileName = args[1];
		if(args.length == 3){
			numberOfIterations = Integer.parseInt(args[2]);
		}else{
			numberOfIterations = 1;
		}
		
		if(DEBUG_MODE){
			System.out.printf("Sort type = %s and number of items is %d and number of iterations is %d\n", sortType, numberOfItems, numberOfIterations);
		}else{
			System.out.printf("java, %s, %s, %d, *, ", sortType, fileName, numberOfIterations);
			printCurrentTime();
		}

		/* Get number of items in file */
		numberOfItems = getNumberOfItemsInFile();

		if(DEBUG_MODE){
			System.out.print("Started loading data at: ");
			printCurrentTime();
		}
		/* Load data from file to long array */
		loadDataFromFile();

		if(DEBUG_MODE){
			System.out.print("Ended loading data at: ");
			printCurrentTime();
		}

		/* Sort based on type */
		switch(sortType){
			case "bogo":
				for(int i = 0; i < numberOfIterations; i++){
					copyDataFromOriginal();	
					start = System.nanoTime();
					if(DEBUG_MODE){
						System.out.printf("Started iteration %d of sorting data at ", i+1);
						printCurrentTime();
					}
					Bogo.bogoSort(data);
					end = System.nanoTime();
					if(!DEBUG_MODE){
							System.out.printf("java, %s, %s, %d, %d/%d, %f\n", sortType, fileName, numberOfIterations, i+1, numberOfIterations, ((end - start) / 1000000000));
					}else{
						System.out.printf("Stopped iteration %d of sorting data at ", i+1);
						printCurrentTime();
						System.out.printf("Time taken for %dth iteration: %f\n", i+1, ((end -  start) / 1000000000));
					}
					totalCpuTime += ((end - start) / 1000000000);
				}
			break;
			case "bubble":
				for(int i = 0; i < numberOfIterations; i++){
					copyDataFromOriginal();	
					start = System.nanoTime();
					if(DEBUG_MODE){
						System.out.printf("Started iteration %d of sorting data at ", i+1);
						printCurrentTime();
					}
					Bubble.bubbleSort(data);
					end = System.nanoTime();
					if(!DEBUG_MODE){
							System.out.printf("java, %s, %s, %d, %d/%d, %f\n", sortType, fileName, numberOfIterations, i+1, numberOfIterations, ((end - start) / 1000000000));
					}else{
						System.out.printf("Stopped iteration %d of sorting data at ", i+1);
						printCurrentTime();
						System.out.printf("Time taken for %dth iteration: %f\n", i+1, ((end -  start) / 1000000000));
					}
					totalCpuTime += ((end - start) / 1000000000);
				}
			break;
			case "bubble_rec":
				for(int i = 0; i < numberOfIterations; i++){
					copyDataFromOriginal();	
					start = System.nanoTime();
					if(DEBUG_MODE){
						System.out.printf("Started iteration %d of sorting data at ", i+1);
						printCurrentTime();
					}
					BubbleRec.bubbleSort(data);
					end = System.nanoTime();
					if(!DEBUG_MODE){
							System.out.printf("java, %s, %s, %d, %d/%d, %f\n", sortType, fileName, numberOfIterations, i+1, numberOfIterations, ((end - start) / 1000000000));
					}else{
						System.out.printf("Stopped iteration %d of sorting data at ", i+1);
						printCurrentTime();
						System.out.printf("Time taken for %dth iteration: %f\n", i+1, ((end -  start) / 1000000000));
					}
					totalCpuTime += ((end - start) / 1000000000);
				}
			break;
			case "binsertion":
				for(int i = 0; i < numberOfIterations; i++){
					copyDataFromOriginal();	
					start = System.nanoTime();
					if(DEBUG_MODE){
						System.out.printf("Started iteration %d of sorting data at ", i+1);
						printCurrentTime();
					}
					BinaryInsertion.binsertionSort(data);
					end = System.nanoTime();
					if(!DEBUG_MODE){
							System.out.printf("java, %s, %s, %d, %d/%d, %f\n", sortType, fileName, numberOfIterations, i+1, numberOfIterations, ((end - start) / 1000000000));
					}else{
						System.out.printf("Stopped iteration %d of sorting data at ", i+1);
						printCurrentTime();
						System.out.printf("Time taken for %dth iteration: %f\n", i+1, ((end -  start) / 1000000000));
					}
					totalCpuTime += ((end - start) / 1000000000);
				}
			break;
			case "cocktail":
				for(int i = 0; i < numberOfIterations; i++){
					copyDataFromOriginal();	
					start = System.nanoTime();
					if(DEBUG_MODE){
						System.out.printf("Started iteration %d of sorting data at ", i+1);
						printCurrentTime();
					}
					Cocktail.cocktailSort(data);
					end = System.nanoTime();
					if(!DEBUG_MODE){
							System.out.printf("java, %s, %s, %d, %d/%d, %f\n", sortType, fileName, numberOfIterations, i+1, numberOfIterations, ((end - start) / 1000000000));
					}else{
						System.out.printf("Stopped iteration %d of sorting data at ", i+1);
						printCurrentTime();
						System.out.printf("Time taken for %dth iteration: %f\n", i+1, ((end -  start) / 1000000000));
					}
					totalCpuTime += ((end - start) / 1000000000);
				}
			break;
			case "comb":
				for(int i = 0; i < numberOfIterations; i++){
					copyDataFromOriginal();	
					start = System.nanoTime();
					if(DEBUG_MODE){
						System.out.printf("Started iteration %d of sorting data at ", i+1);
						printCurrentTime();
					}
					Comb.combSort(data);
					end = System.nanoTime();
					if(!DEBUG_MODE){
							System.out.printf("java, %s, %s, %d, %d/%d, %f\n", sortType, fileName, numberOfIterations, i+1, numberOfIterations, ((end - start) / 1000000000));
					}else{
						System.out.printf("Stopped iteration %d of sorting data at ", i+1);
						printCurrentTime();
						System.out.printf("Time taken for %dth iteration: %f\n", i+1, ((end -  start) / 1000000000));
					}
					totalCpuTime += ((end - start) / 1000000000);
				}
			break;
			case "cycle":
				for(int i = 0; i < numberOfIterations; i++){
					copyDataFromOriginal();	
					start = System.nanoTime();
					if(DEBUG_MODE){
						System.out.printf("Started iteration %d of sorting data at ", i+1);
						printCurrentTime();
					}
					Cycle.cycleSort(data);
					end = System.nanoTime();
					if(!DEBUG_MODE){
							System.out.printf("java, %s, %s, %d, %d/%d, %f\n", sortType, fileName, numberOfIterations, i+1, numberOfIterations, ((end - start) / 1000000000));
					}else{
						System.out.printf("Stopped iteration %d of sorting data at ", i+1);
						printCurrentTime();
						System.out.printf("Time taken for %dth iteration: %f\n", i+1, ((end -  start) / 1000000000));
					}
					totalCpuTime += ((end - start) / 1000000000);
				}
			break;
			case "gnome":
				for(int i = 0; i < numberOfIterations; i++){
					copyDataFromOriginal();	
					start = System.nanoTime();
					if(DEBUG_MODE){
						System.out.printf("Started iteration %d of sorting data at ", i+1);
						printCurrentTime();
					}
					Gnome.gnomeSort(data);
					end = System.nanoTime();
					if(!DEBUG_MODE){
							System.out.printf("java, %s, %s, %d, %d/%d, %f\n", sortType, fileName, numberOfIterations, i+1, numberOfIterations, ((end - start) / 1000000000));
					}else{
						System.out.printf("Stopped iteration %d of sorting data at ", i+1);
						printCurrentTime();
						System.out.printf("Time taken for %dth iteration: %f\n", i+1, ((end -  start) / 1000000000));
					}
					totalCpuTime += ((end - start) / 1000000000);
				}
			break;
			case "heap":
				for(int i = 0; i < numberOfIterations; i++){
					copyDataFromOriginal();	
					start = System.nanoTime();
					if(DEBUG_MODE){
						System.out.printf("Started iteration %d of sorting data at ", i+1);
						printCurrentTime();
					}
					Heap.heapSort(data);
					end = System.nanoTime();
					if(!DEBUG_MODE){
							System.out.printf("java, %s, %s, %d, %d/%d, %f\n", sortType, fileName, numberOfIterations, i+1, numberOfIterations, ((end - start) / 1000000000));
					}else{
						System.out.printf("Stopped iteration %d of sorting data at ", i+1);
						printCurrentTime();
						System.out.printf("Time taken for %dth iteration: %f\n", i+1, ((end -  start) / 1000000000));
					}
					totalCpuTime += ((end - start) / 1000000000);
				}
			break;
			case "insertion":
				for(int i = 0; i < numberOfIterations; i++){
					copyDataFromOriginal();	
					start = System.nanoTime();
					if(DEBUG_MODE){
						System.out.printf("Started iteration %d of sorting data at ", i+1);
						printCurrentTime();
					}
					Insertion.insertionSort(data);
					end = System.nanoTime();
					if(!DEBUG_MODE){
							System.out.printf("java, %s, %s, %d, %d/%d, %f\n", sortType, fileName, numberOfIterations, i+1, numberOfIterations, ((end - start) / 1000000000));
					}else{
						System.out.printf("Stopped iteration %d of sorting data at ", i+1);
						printCurrentTime();
						System.out.printf("Time taken for %dth iteration: %f\n", i+1, ((end -  start) / 1000000000));
					}
					totalCpuTime += ((end - start) / 1000000000);
				}
			break;
			case "insertion_rec":
				for(int i = 0; i < numberOfIterations; i++){
					copyDataFromOriginal();	
					start = System.nanoTime();
					if(DEBUG_MODE){
						System.out.printf("Started iteration %d of sorting data at ", i+1);
						printCurrentTime();
					}
					InsertionRec.insertionRecSort(data, numberOfItems);
					end = System.nanoTime();
					if(!DEBUG_MODE){
							System.out.printf("java, %s, %s, %d, %d/%d, %f\n", sortType, fileName, numberOfIterations, i+1, numberOfIterations, ((end - start) / 1000000000));
					}else{
						System.out.printf("Stopped iteration %d of sorting data at ", i+1);
						printCurrentTime();
						System.out.printf("Time taken for %dth iteration: %f\n", i+1, ((end -  start) / 1000000000));
					}
					totalCpuTime += ((end - start) / 1000000000);
				}
			break;
			case "merge":
				for(int i = 0; i < numberOfIterations; i++){
					copyDataFromOriginal();	
					start = System.nanoTime();
					if(DEBUG_MODE){
						System.out.printf("Started iteration %d of sorting data at ", i+1);
						printCurrentTime();
					}
					Merge.mergeSort(data);
					end = System.nanoTime();
					if(!DEBUG_MODE){
							System.out.printf("java, %s, %s, %d, %d/%d, %f\n", sortType, fileName, numberOfIterations, i+1, numberOfIterations, ((end - start) / 1000000000));
					}else{
						System.out.printf("Stopped iteration %d of sorting data at ", i+1);
						printCurrentTime();
						System.out.printf("Time taken for %dth iteration: %f\n", i+1, ((end -  start) / 1000000000));
					}
					totalCpuTime += ((end - start) / 1000000000);
				}
			break;
			case "mergebu":
				for(int i = 0; i < numberOfIterations; i++){
					copyDataFromOriginal();	
					start = System.nanoTime();
					if(DEBUG_MODE){
						System.out.printf("Started iteration %d of sorting data at ", i+1);
						printCurrentTime();
					}
					MergeBu.mergeSort(data);
					end = System.nanoTime();
					if(!DEBUG_MODE){
							System.out.printf("java, %s, %s, %d, %d/%d, %f\n", sortType, fileName, numberOfIterations, i+1, numberOfIterations, ((end - start) / 1000000000));
					}else{
						System.out.printf("Stopped iteration %d of sorting data at ", i+1);
						printCurrentTime();
						System.out.printf("Time taken for %dth iteration: %f\n", i+1, ((end -  start) / 1000000000));
					}
					totalCpuTime += ((end - start) / 1000000000);
				}
			break;
			case "pancake":
				for(int i = 0; i < numberOfIterations; i++){
					copyDataFromOriginal();	
					start = System.nanoTime();
					if(DEBUG_MODE){
						System.out.printf("Started iteration %d of sorting data at ", i+1);
						printCurrentTime();
					}
					Pancake.pancakeSort(data, numberOfItems);
					end = System.nanoTime();
					if(!DEBUG_MODE){
							System.out.printf("java, %s, %s, %d, %d/%d, %f\n", sortType, fileName, numberOfIterations, i+1, numberOfIterations, ((end - start) / 1000000000));
					}else{
						System.out.printf("Stopped iteration %d of sorting data at ", i+1);
						printCurrentTime();
						System.out.printf("Time taken for %dth iteration: %f\n", i+1, ((end -  start) / 1000000000));
					}
					totalCpuTime += ((end - start) / 1000000000);
				}
			break;
			case "quick":
				for(int i = 0; i < numberOfIterations; i++){
					copyDataFromOriginal();	
					start = System.nanoTime();
					if(DEBUG_MODE){
						System.out.printf("Started iteration %d of sorting data at ", i+1);
						printCurrentTime();
					}
					Quick.quickSort(data);
					end = System.nanoTime();
					if(!DEBUG_MODE){
							System.out.printf("java, %s, %s, %d, %d/%d, %f\n", sortType, fileName, numberOfIterations, i+1, numberOfIterations, ((end - start) / 1000000000));
					}else{
						System.out.printf("Stopped iteration %d of sorting data at ", i+1);
						printCurrentTime();
						System.out.printf("Time taken for %dth iteration: %f\n", i+1, ((end -  start) / 1000000000));
					}
					totalCpuTime += ((end - start) / 1000000000);
				}
			break;
			case "radix":
				for(int i = 0; i < numberOfIterations; i++){
					copyDataFromOriginal();	
					start = System.nanoTime();
					if(DEBUG_MODE){
						System.out.printf("Started iteration %d of sorting data at ", i+1);
						printCurrentTime();
					}
					Radix.radixSort(data, numberOfItems);
					end = System.nanoTime();
					if(!DEBUG_MODE){
							System.out.printf("java, %s, %s, %d, %d/%d, %f\n", sortType, fileName, numberOfIterations, i+1, numberOfIterations, ((end - start) / 1000000000));
					}else{
						System.out.printf("Stopped iteration %d of sorting data at ", i+1);
						printCurrentTime();
						System.out.printf("Time taken for %dth iteration: %f\n", i+1, ((end -  start) / 1000000000));
					}
					totalCpuTime += ((end - start) / 1000000000);
				}
			break;
			case "selection":
				for(int i = 0; i < numberOfIterations; i++){
					copyDataFromOriginal();	
					start = System.nanoTime();
					if(DEBUG_MODE){
						System.out.printf("Started iteration %d of sorting data at ", i+1);
						printCurrentTime();
					}
					Selection.selectionSort(data);
					end = System.nanoTime();
					if(!DEBUG_MODE){
							System.out.printf("java, %s, %s, %d, %d/%d, %f\n", sortType, fileName, numberOfIterations, i+1, numberOfIterations, ((end - start) / 1000000000));
					}else{
						System.out.printf("Stopped iteration %d of sorting data at ", i+1);
						printCurrentTime();
						System.out.printf("Time taken for %dth iteration: %f\n", i+1, ((end -  start) / 1000000000));
					}
					totalCpuTime += ((end - start) / 1000000000);
				}
			break;
			case "shell":
				for(int i = 0; i < numberOfIterations; i++){
					copyDataFromOriginal();	
					start = System.nanoTime();
					if(DEBUG_MODE){
						System.out.printf("Started iteration %d of sorting data at ", i+1);
						printCurrentTime();
					}
					Shell.shellSort(data);
					end = System.nanoTime();
					if(!DEBUG_MODE){
							System.out.printf("java, %s, %s, %d, %d/%d, %f\n", sortType, fileName, numberOfIterations, i+1, numberOfIterations, ((end - start) / 1000000000));
					}else{
						System.out.printf("Stopped iteration %d of sorting data at ", i+1);
						printCurrentTime();
						System.out.printf("Time taken for %dth iteration: %f\n", i+1, ((end -  start) / 1000000000));
					}
					totalCpuTime += ((end - start) / 1000000000);
				}
			break;
			case "tim":
				for(int i = 0; i < numberOfIterations; i++){
					copyDataFromOriginal();	
					start = System.nanoTime();
					if(DEBUG_MODE){
						System.out.printf("Started iteration %d of sorting data at ", i+1);
						printCurrentTime();
					}
					Arrays.sort(data);
					end = System.nanoTime();
					if(!DEBUG_MODE){
							System.out.printf("java, %s, %s, %d, %d/%d, %f\n", sortType, fileName, numberOfIterations, i+1, numberOfIterations, ((end - start) / 1000000000));
					}else{
						System.out.printf("Stopped iteration %d of sorting data at ", i+1);
						printCurrentTime();
						System.out.printf("Time taken for %dth iteration: %f\n", i+1, ((end -  start) / 1000000000));
					}
					totalCpuTime += ((end - start) / 1000000000);
				}
			break;
			default:
				System.out.println("Incorrect sortType entered");
				System.exit(-1);
		}
			
		averageCpuTime = totalCpuTime / numberOfIterations;
		

		if(DEBUG_MODE){
			System.out.printf("total time taken for %d iterations is %f seconds\n", numberOfIterations, totalCpuTime);
			System.out.printf("Average time taken for %d iterations is %f seconds\n", numberOfIterations, averageCpuTime);
			if(isSorted(data)){
				System.out.println("Validation: Array has been sorted"); 
			}else{
				System.out.println("Validation: Array has not been sorted");
			}
			System.out.printf("Ended program at: ");
			printCurrentTime();
		}else{
			System.out.printf("java, %s, %s, %d, #, %f, %f, ", sortType, fileName, numberOfIterations, averageCpuTime, totalCopyingTime);
			printCurrentTime();
		}	
		
		data = null;
		dataOriginal = null;
	}
}
