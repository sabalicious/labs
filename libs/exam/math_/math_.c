#include "math_.h"

// ���������� ������� ��������
int add(int a, int b) {
    return a + b;
}

// ���������� ������� ���������
int subtract(int a, int b) {
    return a - b;
}

// ���������� ������� ���������
int multiply(int a, int b) {
    return a * b;
}

// ���������� ������� �������
int divide(int a, int b) {
    if (b == 0) {
        // ���������� 0, ���� ������� �� ����
        return 0;
    }
    return a / b;
}

// ���������� ������� ���������� ������� �� �������
int modulo(int a, int b) {
    if (b == 0) {
        // ���������� 0, ���� ������� �� ����
        return 0;
    }
    return a % b;
}
