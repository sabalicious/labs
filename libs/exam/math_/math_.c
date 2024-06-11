#include "math_.h"

// Реализация функции сложения
int add(int a, int b) {
    return a + b;
}

// Реализация функции вычитания
int subtract(int a, int b) {
    return a - b;
}

// Реализация функции умножения
int multiply(int a, int b) {
    return a * b;
}

// Реализация функции деления
int divide(int a, int b) {
    if (b == 0) {
        // Возвращаем 0, если деление на ноль
        return 0;
    }
    return a / b;
}

// Реализация функции нахождения остатка от деления
int modulo(int a, int b) {
    if (b == 0) {
        // Возвращаем 0, если деление на ноль
        return 0;
    }
    return a % b;
}
