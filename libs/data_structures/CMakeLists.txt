add_library(data_structures
        bitset/bitset.c
        unordered_set/unordered_set.c
        ordered_set/ordered_set.c
        vector/vector.c
        vector/vectorVoid.c
        matrix/matrix.c
        )

target_link_libraries(data_structures algorithms)