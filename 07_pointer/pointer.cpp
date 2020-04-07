//
// Created by Huiping Guo on 2020/04/06.
//


void add(int a,int b, int *c) {
    *c = a + b;
}


int main() {

    int x = 5;
    int *ptr = &x;

    *ptr = 10;

    int y = 6;

    ptr = &y;

    auto a = *ptr;


    int c;
//    int *c = nullptr;  // wrong
    add(1,2,&c);

    return 1;
}

