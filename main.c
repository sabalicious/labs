#include "libs/data_structures/vector/vector.h"
#include <stdio.h>

int main() {
    size_t n = 10;
    vector myVector = createVector(n);

    // Пример использования вектораа
    for (size_t i = 0; i < n; i++) {
        myVector.data[i] = i * 2;
        printf("%d ", myVector.data[i]);
    }

    // Освобождение памяти после использования вектора
    free(myVector.data);

    return 0;
}



























