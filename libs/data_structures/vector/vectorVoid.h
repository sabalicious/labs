#ifndef INC_VECTORVOID_H
#define INC_VECTORVOID_H

#include <limits.h>
#include <stdio.h>

typedef struct vectorVoid {
    void* data; // указатель на нулевой элемент вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
    size_t baseTypeSize; // размер базового типа:
    // например, если вектор хранит int -
    // то поле baseTypeSize = sizeof(int)
    // если вектор хранит float -
    // то поле baseTypeSize = sizeof(float)
} vectorVoid;

//возвращает структуру-дескриптор вектор из n значений
vectorVoid createVectorV(size_t n, size_t baseTypeSize);

//измен€ет количество пам€ти, выделенное под хранение элементов вектора
void reserveV(vectorVoid* v, size_t newCapacity);

//освобождает пам€ть, выделенную под неиспользуемые элементы
void shrinkToFitV(vectorVoid* v);

//удал€ет элементы из контейнера, но не освобождает выделенную пам€ть
void clearV(vectorVoid* v);

//освобождает пам€ть, выделенную вектору
void deleteVectorV(vectorVoid* v);

//проверка, €вл€етс€ ли вектор путсым
bool isEmptyV(vectorVoid* v);

//проверка, €вл€етс€ ли вектор полным
bool isFullV(vectorVoid* v);

//записывает по адресу destination index-ый элемент вектора v.
void getVectorValueV(vectorVoid* v, size_t index, void* destination);

//записывает на index-ый элемент вектора v значение, расположенное по адресу source
void setVectorValueV(vectorVoid* v, size_t index, void* source);

//добавл€ет элемент x в конец вектора v
void pushBackV(vectorVoid* v, void* source);

//удал€ет последний элемент из вектора
void popBackV(vectorVoid* v);

#endif