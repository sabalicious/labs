#ifndef INC_VECTORVOID_H
#define INC_VECTORVOID_H

#include <limits.h>
#include <stdio.h>

typedef struct vectorVoid {
    void* data; // ��������� �� ������� ������� �������
    size_t size; // ������ �������
    size_t capacity; // ����������� �������
    size_t baseTypeSize; // ������ �������� ����:
    // ��������, ���� ������ ������ int -
    // �� ���� baseTypeSize = sizeof(int)
    // ���� ������ ������ float -
    // �� ���� baseTypeSize = sizeof(float)
} vectorVoid;

//���������� ���������-���������� ������ �� n ��������
vectorVoid createVectorV(size_t n, size_t baseTypeSize);

//�������� ���������� ������, ���������� ��� �������� ��������� �������
void reserveV(vectorVoid* v, size_t newCapacity);

//����������� ������, ���������� ��� �������������� ��������
void shrinkToFitV(vectorVoid* v);

//������� �������� �� ����������, �� �� ����������� ���������� ������
void clearV(vectorVoid* v);

//����������� ������, ���������� �������
void deleteVectorV(vectorVoid* v);

//��������, �������� �� ������ ������
bool isEmptyV(vectorVoid* v);

//��������, �������� �� ������ ������
bool isFullV(vectorVoid* v);

//���������� �� ������ destination index-�� ������� ������� v.
void getVectorValueV(vectorVoid* v, size_t index, void* destination);

//���������� �� index-�� ������� ������� v ��������, ������������� �� ������ source
void setVectorValueV(vectorVoid* v, size_t index, void* source);

//��������� ������� x � ����� ������� v
void pushBackV(vectorVoid* v, void* source);

//������� ��������� ������� �� �������
void popBackV(vectorVoid* v);

#endif