import java.io.File;
import java.util.Scanner;
import java.io.FileNotFoundException;

public class SortBasedOnFile{
		
	/* Declare Variables */
	private static int numberOfItems;
	private static Long dataOriginal[];
	private static Long data[];
	private static String sortType;
	private static String fileName;
	private static int numberOfIterations;
	private static final boolean DEBUG_MODE = false;
	
	private static boolean less(Comparable v, Comparable w){
		return (v.compareTo(w) < 0);
	}
	
	private static void exch(Comparable[] a, int i, int j){
		Comparable swap = a[i];
		a[i] = a[j];
		a[j] = swap;
	}

	private static int getNumberOfItemsInFile(){
		int itemCount = 0;
		try{
			File file = new File(fileName);
			Scanner in = new Scanner(file);
			while(in.hasNextLine()){
				itemCount++;
			}
			in.close();
		}catch(FileNotFoundException e){
			System.out.println("File not found");
			e.printStackTrace();
			System.exit(-1);
		}
		return itemCount;
	}

	private static void loadDataFromFile(){
		try{
			data = new Long[numberOfItems];
			dataOriginal = new Long[numberOfItems];
			File file = new File(fileName);
			Scanner in = new Scanner(file);
			int i = 0;
			while(in.hasNextLine()){
				data[i] = in.nextLong();
				in.nextLine();
				i++;
			}
		}catch(Exception e){
			e.printStackTrace();
		}
	}

	private static void copyDataFromOriginal(){
		for(int i = 0; i < numberOfItems; i++){
			data[i] = dataOriginal[i];	
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
		
	

	public static void main(String[] args){

		/* If haven't specified required commandline arguments */
		if(args.length < 2){
			System.out.println("Usage SortbasedOnFile <sort_type> <file_name> <iterations?>");
			System.exit(-1);	
		}

		/* Get command line arguments */
		sortType = args[0];
		fileName = args[1];
		if(args.length == 4){
			numberOfIterations = Integer.parseInt(args[1]);
		}else{
			numberOfIterations = 1;
		}

		numberOfItems = getNumberOfItemsInFile();
		System.out.println("Number of items = " + numberOfItems);

		for(int i = 0; i < numberOfItems; i++){
			System.out.println(dataOriginal[i]);	
		}

		switch(sortType){
			case "insertion":
				for(int i = 0; i < numberOfIterations; i++){
					//copyDataFromOriginal();	
		//			Insertion.insertionSort(data);
				}
			break;
			default:
				System.out.println("Incorrect sortType entered");
		}

		if(isSorted(data)){
			System.out.println("Array has been sorted"); 
		}else{
			System.out.println("Array has not been sorted");
		}

		data = null;
		dataOriginal = null;
	}
}
