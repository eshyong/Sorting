#include <ctime>
#include <iostream>

void insertionsort(int *array, int size) {
	for (int i = 0; i < size; i++) {
		int j = i;
		while (j > 0 && array[j - 1] > array[j]) {
			int temp = array[j - 1];
			array[j - 1] = array[j];
			array[j] = temp;
			j--;
		}
	}
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
			// std::cout << array[i] << " "; // Uncomment this line to print unsorted array.
		} else
			i--;
	}
	std::cout << std::endl;

	insertionsort(array, size);
	std::cout << "Sorted array: ";
	/* for (int i = 0; i < size; i++) {
		std::cout << array[i] << " ";
	} */ // Uncomment these lines to print sorted array.
	std::cout << std::endl;

	delete[] array;
	delete[] check;

	ret:
		return 0;
}
