#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "C:\Users\Vlad\labs\libs\string_\string_.c"

void test_strlen() {
    char* s1 = "Hi";
    char s2[10] = "\tHello\t";

    assert(strlen1(s1) == 2);
    assert(strlen1(s2) == 7);

    assert(strlen2(s1) == 2);
    assert(strlen2(s2) == 7);

    assert(strlen_(s1) == 2);
    assert(strlen_(s2) == 7);
}

void test_find() {
    char str[] = "Hello, world!";
    char* begin = str;
    char* end = str + sizeof(str) - 1;

    char ch1 = 'o';
    char* result1 = find(begin, end, ch1);
    printf("%s\n", result1);

    char ch2 = 'y';
    char* result2 = find(begin, end, ch2);
    assert(result2 == end);
}

void test_findNonSpace() {
    char text[] = "   \t  Hello, World!";

    char* nonSpacePtr = findNonSpace(text);

    printf("%s\n", nonSpacePtr);
}

void test_findSpace() {
    char text1[] = "Hello, World!";
    char text2[] = "ThisHasNoSpace";
    char text3[] = "\t   ";

    char* result1 = findSpace(text1);
    char* result2 = findSpace(text2);
    char* result3 = findSpace(text3);

    assert(*result1 == ' ');
    assert(*result2 == '\0');
    assert(*result3 == '\t');
}

void test_findNonSpaceReverse() {
    const char text1[] = "   \t  Hello, World!";
    char* rbegin1 = (char*)(text1 + sizeof(text1) - 2);
    const char* rend1 = text1 - 1;

    char* result1 = findNonSpaceReverse(rbegin1, rend1);
    assert(*result1 == '!');

    const char text2[] = "   \t  ";
    char* rbegin2 = (char*)(text2 + sizeof(text2) - 2);
    const char* rend2 = text2 - 1;

    char* result2 = findNonSpaceReverse(rbegin2, rend2);
    assert(result2 == rend2);
}

void test_findSpaceReverse() {
    const char text1[] = "   \t  Hello, World!";
    char* rbegin1 = (char*)(text1 + sizeof(text1) - 2);
    const char* rend1 = text1 - 1;

    char* result1 = findSpaceReverse(rbegin1, rend1);
    printf("%s\n", result1);
    assert(*result1 == ' ');

    const char text2[] = "ThisHasNoSpace";
    char* rbegin2 = (char*)(text2 + sizeof(text2) - 2);
    const char* rend2 = text2 - 1;

    char* result2 = findSpaceReverse(rbegin2, rend2);
    assert(result2 == rend2);
}

void test_strcmp() {
    assert(strcmp("hello", "hello") == 0);
    assert(strcmp("hello", "world") < 0);
    assert(strcmp("apple", "app") > 0);
    assert(strcmp("", "hello") < 0);
    assert(strcmp("world", "") > 0);
}

void test_copy() {
    const char source[] = "Hello";
    char destination[10];
    copy(source, source + 5, destination);

    destination[5] = '\0';
    printf("%s", destination);

    assert(strcmp(destination, "Hello") == 0);
}

int isEven(int num) {
    return num % 2 == 0;
}

void test_copyIf() {
    char source1[] = { 1, 2, 3, 4, 5 };
    char destination1[5];
    char* result1 = copyIf(source1, source1 + 5, destination1, isEven);

    assert(result1 - destination1 == 2);
    assert(destination1[0] == 2);
    assert(destination1[1] == 4);
}

void test_copyIfReverse() {
    char source1[] = { 1, 2, 3, 4, 5 };
    char destination1[5];
    copyIfReverse(source1 + 4, source1 - 1, destination1, isEven);

    assert(destination1[0] == 4);
    assert(destination1[1] == 2);
}

void test() {
    // test_strlen() ;
    // test_find() ;
    // test_findNonSpace() ;
    // test_findSpace() ;
    // test_findNonSpaceReverse() ;
    // test_findSpaceReverse() ; 
    // test_strcmp() ;
    // test_copy() ;
    test_copyIf();
    // test_copyIfReverse() ;
}

int main() {
    test();

    return 0;
}