#include "unordered_set.h"

unordered_array_set unordered_array_set_create(size_t capacity) {
    unordered_array_set set;
    set.data = malloc(capacity * sizeof(uint32_t));
    if (set.data == NULL) {
        fprintf(stderr, "Failed to allocate memory for unordered array set\n");
        exit(EXIT_FAILURE);
    }
    set.size = 0;
    set.capacity = capacity;
    return set;
}

unordered_array_set unordered_array_set_create_from_array(const uint32_t *a, size_t size) {
    unordered_array_set set;
    set.data = malloc(size * sizeof(uint32_t));
    if (set.data == NULL) {
        fprintf(stderr, "Failed to allocate memory for unordered array set\n");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < size; ++i) {
        set.data[i] = a[i];
    }
    set.size = size;
    set.capacity = size;
    return set;
}

size_t unordered_array_set_in(unordered_array_set set, uint32_t value) {
    for (size_t i = 0; i < set.size; ++i) {
        if (set.data[i] == value) {
            return i;
        }
    }
    return set.size;
}

size_t unordered_array_set_isSubset(unordered_array_set subset, unordered_array_set set) {
    size_t count = 0;
    for (size_t i = 0; i < subset.size; ++i) {
        for (size_t j = 0; j < set.size; ++j) {
            if (subset.data[i] == set.data[j]) {
                ++count;
                break;
            }
        }
    }
    return (count == subset.size);
}

bool unordered_array_set_isEqual(unordered_array_set set1, unordered_array_set set2) {
    if (set1.size != set2.size) {
        return false;
    }
    for (size_t i = 0; i < set1.size; ++i) {
        if (!unordered_array_set_in(set2, set1.data[i])) {
            return false;
        }
    }
    return true;
}

void unordered_array_set_isAbleAppend(unordered_array_set *set) {
    if (set->size >= set->capacity) {
        fprintf(stderr, "Cannot append element to set: set is full\n");
        exit(EXIT_FAILURE);
    }
}

void unordered_array_set_insert(unordered_array_set *set, uint32_t value) {
    unordered_array_set_isAbleAppend(set);
    set->data[set->size++] = value;
}

void unordered_array_set_deleteElement(unordered_array_set *set, uint32_t value) {
    size_t index = unordered_array_set_in(*set, value);
    if (index < set->size) {
        for (size_t i = index; i < set->size - 1; ++i) {
            set->data[i] = set->data[i + 1];
        }
        --set->size;
    }
}

unordered_array_set unordered_array_set_union(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set result = unordered_array_set_create(set1.size + set2.size);
    for (size_t i = 0; i < set1.size; ++i) {
        unordered_array_set_insert(&result, set1.data[i]);
    }
    for (size_t i = 0; i < set2.size; ++i) {
        unordered_array_set_insert(&result, set2.data[i]);
    }
    return result;
}

unordered_array_set unordered_array_set_intersection(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set result = unordered_array_set_create(set1.size < set2.size ? set1.size : set2.size);
    for (size_t i = 0; i < set1.size; ++i) {
        if (unordered_array_set_in(set2, set1.data[i]) != set2.size) {
            unordered_array_set_insert(&result, set1.data[i]);
        }
    }
    return result;
}

unordered_array_set unordered_array_set_difference(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set result = unordered_array_set_create(set1.size);
    for (size_t i = 0; i < set1.size; ++i) {
        if (unordered_array_set_in(set2, set1.data[i]) == set2.size) {
            unordered_array_set_insert(&result, set1.data[i]);
        }
    }
    return result;
}

void unordered_array_set_print(unordered_array_set set) {
    printf("{ ");
    for (size_t i = 0; i < set.size; ++i) {
        printf("%u ", set.data[i]);
    }
    printf("}\n");
}

void unordered_array_set_delete(unordered_array_set set) {
    free(set.data);
    set.data = NULL;
    set.size = set.capacity = 0;
}

