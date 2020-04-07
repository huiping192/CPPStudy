//
// Created by Huiping Guo on 2020/04/06.
//
#include <iostream>


void add(int a,int b, int *c) {
    *c = a + b;
}

void samplePoint() {
    int x = 5;
    int *ptr = &x;

    *ptr = 10;

    int y = 6;
    ptr = &y;

    auto a = *ptr;

    int c;
//    int *c = nullptr;  // wrong
    add(1,2,&c);
}

void voidSample() {
    int a = 1;

    void* b  = &a;

    int* c = static_cast<int*>(b);

    std::cout << *c;
}


int main() {

    voidSample();

    return 1;
}

