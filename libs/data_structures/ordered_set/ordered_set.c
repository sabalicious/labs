#include "ordered_set.h"
#include <stdlib.h>
#include <stdio.h>

ordered_array_set ordered_array_set_create(size_t capacity) {
    ordered_array_set set;
    set.data = malloc(capacity * sizeof(uint32_t));
    if (set.data == NULL) {
        fprintf(stderr, "Failed to allocate memory for ordered array set\n");
        exit(EXIT_FAILURE);
    }
    set.size = 0;
    set.capacity = capacity;
    return set;
}

ordered_array_set ordered_array_set_create_from_array(const uint32_t *a, size_t size) {
    ordered_array_set set;
    set.data = malloc(size * sizeof(uint32_t));
    if (set.data == NULL) {
        fprintf(stderr, "Failed to allocate memory for ordered array set\n");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < size; ++i) {
        set.data[i] = a[i];
    }
    set.size = size;
    set.capacity = size;
    return set;
}

size_t ordered_array_set_in(ordered_array_set *set, uint32_t value) {
    for (size_t i = 0; i < set->size; ++i) {
        if (set->data[i] == value) {
            return i;
        }
    }
    return set->size;
}

bool ordered_array_set_isEqual(ordered_array_set set1, ordered_array_set set2) {
    if (set1.size != set2.size) {
        return false;
    }
    for (size_t i = 0; i < set1.size; ++i) {
        if (set1.data[i] != set2.data[i]) {
            return false;
        }
    }
    return true;
}

bool ordered_array_set_isSubset(ordered_array_set subset, ordered_array_set set) {
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

void ordered_array_set_isAbleAppend(ordered_array_set *set) {
    if (set->size >= set->capacity) {
        fprintf(stderr, "Cannot append element to set: set is full\n");
        exit(EXIT_FAILURE);
    }
}

void ordered_array_set_insert(ordered_array_set *set, uint32_t value) {
    ordered_array_set_isAbleAppend(set);
    size_t i;
    for (i = 0; i < set->size; ++i) {
        if (set->data[i] >= value) {
            break;
        }
    }
    for (size_t j = set->size; j > i; --j) {
        set->data[j] = set->data[j - 1];
    }
    set->data[i] = value;
    ++set->size;
}

void ordered_array_set_deleteElement(ordered_array_set *set, uint32_t value) {
    size_t index = ordered_array_set_in(set, value);
    if (index < set->size) {
        for (size_t i = index; i < set->size - 1; ++i) {
            set->data[i] = set->data[i + 1];
        }
        --set->size;
    }
}

ordered_array_set ordered_array_set_union(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set result = ordered_array_set_create(set1.size + set2.size);
    size_t i = 0, j = 0, k = 0;
    while (i < set1.size && j < set2.size) {
        if (set1.data[i] < set2.data[j]) {
            result.data[k++] = set1.data[i++];
        } else if (set1.data[i] > set2.data[j]) {
            result.data[k++] = set2.data[j++];
        } else {
            result.data[k++] = set1.data[i++];
            ++j;
        }
    }
    while (i < set1.size) {
        result.data[k++] = set1.data[i++];
    }
    while (j < set2.size) {
        result.data[k++] = set2.data[j++];
    }
    result.size = k;
    return result;
}

ordered_array_set ordered_array_set_intersection(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set result = ordered_array_set_create(set1.size < set2.size ? set1.size : set2.size);
    size_t i = 0, j = 0, k = 0;
    while (i < set1.size && j < set2.size) {
        if (set1.data[i] < set2.data[j]) {
            ++i;
        } else if (set1.data[i] > set2.data[j]) {
            ++j;
        } else {
            result.data[k++] = set1.data[i++];
            ++j;
        }
    }
    result.size = k;
    return result;
}

ordered_array_set ordered_array_set_difference(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set result = ordered_array_set_create(set1.size);
    size_t i = 0, j = 0, k = 0;
    while (i < set1.size && j < set2.size) {
        if (set1.data[i] < set2.data[j]) {
            result.data[k++] = set1.data[i++];
        } else if (set1.data[i] > set2.data[j]) {
            ++j;
        } else {
            ++i;
            ++j;
        }
    }
    while (i < set1.size) {
        result.data[k++] = set1.data[i++];
    }
    result.size = k;
    return result;
}

void ordered_array_set_print(ordered_array_set set) {
    printf("{ ");
    for (size_t i = 0; i < set.size; ++i) {
        printf("%u ", set.data[i]);
    }
    printf("}\n");
}

void ordered_array_set_delete(ordered_array_set *set) {
    free(set->data);
    set->data = NULL;
    set->size = set->capacity = 0;
}
