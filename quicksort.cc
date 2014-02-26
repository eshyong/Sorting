#include <ctime>
#include <iostream>

void quicksort(int *array, int size) {
	if (size <= 1) return;
	// Pick pivot randomly.
	int rand_idx = rand() % size;
	int pivot = array[rand_idx];

	int i = 0;
	int j = size - 1;
	
	while (i != j) {
		while (array[i] < pivot) // Find an element >= pivot on the left.
			i++;
		while (array[j] > pivot) // Find an element <= pivot on the right.
			j--;
		int swap = array[i];
		array[i] = array[j];
		array[j] = swap;
	}
	quicksort(array, i);
	quicksort(array + i, size - i);
}

int main(int argc, char* argv[]) {
	int size;

	// Check for number
	if (argc < 2) {
		std::cout << "Usage: insertionsort N\nwhere N = size of random int array" << std::endl;
		goto ret;
	}

	size = std::atoi(argv[1]);
	if (size > 10000000) {
		std::cout << "integer too large, possible overflow\naborting" << std::endl;
		goto ret;
	}

	if (size <= 0) {
		std::cout << "cannot create an array of that size\naborting" << std::endl;
		goto ret;
	}

	// Seed random generator.
	srand(time(NULL));
	static int* array = new int[size];
	static int* check = new int[size * 10];
	std::fill(check, check + size * 10, 0);
	
	std::cout << "Unsorted array: ";
	for (int i = 0; i < size; i++) {
		int element = rand() % (size * 10);
		if (check[element] != 1) {
			check[element] = 1;
			array[i] = element;
			// std::cout << array[i] << " ";
		} else
			i--;
	}
	std::cout << std::endl;

	quicksort(array, size);
	std::cout << "Sorted array: ";
	/* for (int i = 0; i < size; i++) {
		std::cout << array[i] << " ";
	} */
	std::cout << std::endl;

	delete[] array;
	delete[] check;

	ret:
		return 0;
}
