#include <cstdlib>
#include <ctime>
#include <cstring>
#include <iostream>

void mergesort(int *array, int size) {
	if (size == 1)
		return;
	mergesort(array, size / 2);
	mergesort(array + size / 2, size - (size / 2));
	int* first = new int[size / 2];
	int* second = new int[size - size / 2];
	for (int i = 0; i < size / 2; i++)
		first[i] = array[i];
	for (int i = 0; i < size - (size / 2); i++) 
		second[i] = array[i + size / 2];
	int i = 0, j = 0, k = 0;
	while (i < size / 2 || j < size - (size / 2)) {
		if (i == size / 2) {
			array[k++] = second[j++];
		} else if (j == size - (size / 2)) {
			array[k++] = first[i++];
		} else {
			if (first[i] < second[j])
				array[k++] = first[i++];
			else
				array[k++] = second[j++];
		}
	}
	delete[] first;
	delete[] second;
}

int main(int argc, char* argv[]) {
	int size;

	// Check for number
	if (argc < 2) {
		std::cout << "Usage: mergesort N\nwhere N = size of random int array" << std::endl;
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
	memset(check, 0, size * 10);
	
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

	mergesort(array, size);
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
