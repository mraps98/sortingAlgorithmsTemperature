1. NOTE: For java and c, make sure to run the make command first
2. NOTE: Some algorithms mich not work with big data or long numbers and might cause issues like stackOverFlow error, recursion limit or segmentation faults
# This project contains the following algorithms:
1. generate a file with desired number of random numbers
	* usage: generate_random_numbers_file.out <number_of_elements>
2. check number of duplicates in file of numbers
	* checkDuplicates.out <file_name>
3. remove duplicates from file of numbers
	* usage: remove_duplicates.out <file_name>
4. sorting (see image)
	* c-usage: sort_based_on_file.out <sort_type> <file_name> <number_of_iterations(default:1)>
	* java-usage: java SortBasedOnFile <sort_type> <file_name> <number_of_iterations(default:1)>
	* python-usage: python3 main.py <sort_type> <file_name> <number_of_iterations(default:1)>

* for the sort_type use the following command line arguments
	* binsertion
	* bubble
	* bubble_rec
	* cocktail
	* comb
	* comb
	* cycle
	* gnome
	* heap
	* insertion
	* insertion_rec
	* merge
	* mergebu
	* pancakge
	* quick
	* radix
	* selection
	* shell
	* tim

* format of output from sorting
	1. language, sort_type, file_name, number_of_iterations, *, current_timestamp
	2. language, sort_type, file_name, number_of_iterations, current_iteration_number/number_of_iterations, timestamp_after_iteration
	3. language, sort_type, file_name, number_of_iterations, #, average_sorting_time_per_iteration, total_data_copying_time, total_program_execution_time, timestamp_at_end
