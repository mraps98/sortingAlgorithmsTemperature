public class Main{
	public static void main(String args[]){
		int number_of_items = 5;
		String sort_type = "bubble";
		String number_of_items_string = "1k";
		int number_of_iterations = 1;
		
		if(args.length >= 1){
			sort_type = args[0];
		}
		if(args.length >= 2){
			number_of_items_string = args[1];
			switch(number_of_items_string){
				case "1k":
					number_of_items = 1000;
					break;
				case "2k":
					number_of_items = 2000;
					break;
				case "3k":
					number_of_items = 3000;
					break;
				case "4k":
					number_of_items = 4000;
					break;
				case "5k":
					number_of_items = 5000;
					break;
				case "6k":
					number_of_items = 6000;
					break;
				case "7k":
					number_of_items = 7000;
					break;
				case "8k":
					number_of_items = 8000;
					break;
				case "9k":
					number_of_items = 9000;
					break;
				default:
					number_of_items = 1000;
			}
		}
		if(args.length >= 3){
			number_of_iterations = Integer.parseInt(args[2]);
		}
		
		System.out.printf("Sorting %s items using %s sort for %d iterations\n", number_of_items_string, sort_type, number_of_iterations);
		
		long data[] = {5, 4, 3, 2, 1};
		
		System.out.println("Before");
		for(int i = 0; i < number_of_items; i++){
			System.out.print(data[i] + ", ");
		}
		System.out.print("\n");
		
		switch(sort_type){
			case "bubble":
				Bubble.bubble_sort(data, 0, number_of_items - 1);
				break;
			case "heap":
				Heap.heap_sort(data, 0, number_of_items - 1);
				break;
			case "insertion":
				Insertion.insertion_sort(data, 0, number_of_items - 1);
				break;
			case "merge":
				Merge.merge_sort(data, 0, number_of_items - 1);
				break;
			case "quick":
				Quick.quick_sort(data, 0, number_of_items - 1);
				break;
			case "selection":
				Selection.selection_sort(data, 0, number_of_items - 1);
				break;
			case "shaker":
				Shaker.shaker_sort(data, number_of_items);
				break;
			case "shell":
				Shell.shell_sort(data, 0, number_of_items - 1);
				break;
			default:
				System.out.printf("Invalid sort_type: %s\n", sort_type);
		}
		
		System.out.println("After");
		for(int i = 0; i < number_of_items; i++){
			System.out.print(data[i] + ", ");
		}
		System.out.print("\n");
	}
}