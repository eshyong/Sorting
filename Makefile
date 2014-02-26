CC = g++
EXECS = quicksort mergesort insertionsort bubblesort

all: $(EXECS)

clean:
	rm -rf $(EXECS)

quicksort: quicksort.cc
	g++ quicksort.cc -o quicksort

mergesort: mergesort.cc
	g++ mergesort.cc -o mergesort

bubblesort: bubblesort.cc
	g++ bubblesort.cc -o bubblesort

insertionsort: insertionsort.cc
	g++ insertionsort.cc -o insertionsort
