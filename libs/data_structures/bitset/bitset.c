#include "bitset.h"
#include <stdio.h>


bitset bitset_create(unsigned maxValue) {
    bitset set;
    set.values = 0;
    set.maxValue = maxValue;
    return set;
}

bool bitset_in(bitset set, unsigned int value) {
    if (value > set.maxValue) {
        return false;
    }
    return (set.values & (1u << value)) != 0;
}

bool bitset_isEqual(bitset set1, bitset set2) {
    return set1.values == set2.values && set1.maxValue == set2.maxValue;
}

bool bitset_isSubset(bitset subset, bitset set) {
    return (subset.values & set.values) == subset.values;
}

void bitset_insert(bitset *set, unsigned int value) {
    if (value > set->maxValue) {
        return;
    }
    set->values |= (1u << value);
}

void bitset_deleteElement(bitset *set, unsigned int value) {
    if (value > set->maxValue) {
        return;
    }
    set->values &= ~(1u << value);
}

bitset bitset_union(bitset set1, bitset set2) {
    bitset result;
    result.values = set1.values | set2.values;
    result.maxValue = (set1.maxValue > set2.maxValue) ? set1.maxValue : set2.maxValue;
    return result;
}

bitset bitset_intersection(bitset set1, bitset set2) {
    bitset result;
    result.values = set1.values & set2.values;
    result.maxValue = (set1.maxValue > set2.maxValue) ? set1.maxValue : set2.maxValue;
    return result;
}

bitset bitset_difference(bitset set1, bitset set2) {
    bitset result;
    result.values = set1.values & ~(set2.values);
    result.maxValue = (set1.maxValue > set2.maxValue) ? set1.maxValue : set2.maxValue;
    return result;
}

bitset bitset_symmetricDifference(bitset set1, bitset set2) {
    bitset result;
    result.values = set1.values ^ set2.values;
    result.maxValue = (set1.maxValue > set2.maxValue) ? set1.maxValue : set2.maxValue;
    return result;
}

bitset bitset_complement(bitset set) {
    bitset result;
    result.values = ~(set.values);
    result.maxValue = set.maxValue;
    return result;
}

void bitset_print(bitset set) {
    printf("{ ");
    for (unsigned int i = 0; i <= set.maxValue; ++i) {
        if (bitset_in(set, i)) {
            printf("%u ", i);
        }
    }
    printf("}\n");
}
