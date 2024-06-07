#ifndef INC_STRING__H
#define INC_STRING__H

#include <stdio.h>

#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)
#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

char _stringBuffer[MAX_STRING_SIZE + 1];

typedef struct WordDescriptor {
    char* begin; // ������� ������ �����
    char* end; // ������� ������� �������, ����� ���������� ������� �����
} WordDescriptor;

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

// ���������� ���������� �������� � ������ 
size_t strlen1(char* s);

// ���������� ���������� �������� � ������ 
size_t strlen2(char* s);

// ���������� ���������� �������� � ������ 
size_t strlen_(const char* begin);

// ���������� ��������� �� ������ ������� � ����� ch, 
// ������������� �� ����� ������ ����� �������� begin � end �� ������� end.
// ���� ������ �� ������, ������������ �������� end.
char* find(char* begin, char* end, int ch);

// ���������� ��������� �� ������ ������, �������� �� ����������, 
// ������������� �� ����� ������, ������� � begin � ���������� ����-��������.
// ���� ������ �� ������, ������������ ����� ������� ����-�������.
char* findNonSpace(char* begin);

// ���������� ��������� �� ������ ���������� ������, 
// ������������� �� ����� ������ ������� � ������ begin ��� �� ������ ����-������
char* findSpace(char* begin);

// ���������� ��������� �� ������ ������ ������, �������� �� ����������,
// ������������� �� ����� ������, ������� � rbegin (��������� ������
// ������, �� ������� ������� ����-������) � ���������� rend (����� ������� ����� ������� ������). 
// ���� ������ �� ������, ������������ ����� rend.
char* findNonSpaceReverse(char* rbegin, const char* rend);

// ���������� ��������� �� ������ ���������� ������ ������, 
// ������������� �� ����� ������, ������� � rbegin � ���������� rend. 
// ���� ������ �� ������, ������������ ����� rend.
char* findSpaceReverse(char* rbegin, const char* rend);

// ��������� ������ �� ���������
int strcmp_(const char* lhs, const char* rhs);

// ���������� �� ������ beginDestination �������� ������, 
// ������� � ������ beginSource �� endSource.
// ���������� ��������� �� ��������� ��������� �������� ������ � destination
char* copy(const char* beginSource, const char* endSource, char* beginDestination);

// ���������� �� ������ beginDestination �������� ������, 
// ������� � ������ beginSource �� endSource.
// ���������� ��������� �� ��������� �������� ������ � destination, �� '/0'.
char* copy2(const char* beginSource, const char* endSource, char* beginDestination);

// ���������� �� ������ beginDestination �������� �� ��������� ������ 
// ������� � beginSource ���������� endSource, ��������������� �������-��������� f. 
// ������� ���������� ��������� �� ��������� ��������� ��� ������ �������� � ������.
char* copyIf(char* beginSource, const char* endSource, char* beginDestination, int (*f)(int));

// ���������� �� ������ beginDestination �������� �� ��������� ������ 
// ������� � rbeginSource ���������� rendSource, ��������������� �������-��������� f. 
// ������� ���������� �������� beginDestination �� ��������� ������.
char* copyIfReverse(char* rbeginSource, const char* rendSource, char* beginDestination, int (*f)(int));

#endif