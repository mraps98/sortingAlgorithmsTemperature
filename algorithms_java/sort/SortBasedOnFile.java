import java.io.File;
import java.util.Scanner;
import java.io.FileNotFoundException;

public class SortBasedOnFile{
		
	/* Declare Variables */
	private static int numberOfItems;
	private static long dataOriginal[];
	private static long data[];
	private static String sortType;
	private static String fileName;
	private static int numberOfIterations;
	private static final boolean DEBUG_MODE = false;

	private static int  getNumberOfItemsInFile(){
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
			data = new long[numberOfItems];
			dataOriginal = new long[numberOfItems];
			File file = new File(fileName);
			Scanner in = new Scanner(file);
			int i = 0;
			while(in.hasNextLine()){
				data[i] = in.nextLong();
				i++;
			}
		}catch(Exception e){
			e.printStackTrace();
		}
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
	}
}
