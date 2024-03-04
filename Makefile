GCC=gcc
CFLAGS=-Wall -Ilibs/algorithms -Ilibs/algorithms/array -Ilibs/data_structures -Ilibs/data_structures/bitset
LDFLAGS=-LC:\Users\Vlad\CLionProjects\untitled/algorithms -LC:\Users\Vlad\CLionProjects\untitled/data_structures
LIBS=-lalgorithms -ldata_structures

myprogram: main.c libs/algorithms/algorithms.c libs/algorithms/array/array.c libs/data_structures/bitset/bitset.c
	$(GCC) $(CFLAGS) $(LDFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f myprogram


