#include "vector.h"

vector createVector(size_t n) {
    vector vec;
    vec.size = n;
    vec.capacity = n;

    // ��������� ������ ��� ������ �������� �������
    vec.data = (int*)malloc(n * sizeof(int));

    // �������� �� �������� ��������� ������
    if (vec.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return vec;
}