#include "vector.h"

vector createVector(size_t n) {
    vector vec;
    vec.size = n;
    vec.capacity = n;

    // Выделение памяти под массив значений вектора
    vec.data = (int*)malloc(n * sizeof(int));

    // Проверка на успешное выделение памяти
    if (vec.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return vec;
}