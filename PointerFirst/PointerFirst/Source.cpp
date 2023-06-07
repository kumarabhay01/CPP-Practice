#include <stdio.h>
#include <iostream>
#include<math.h>

void update(int* a, int* b) {
    // Complete this function  
    std::cout << *a << "   " << *b << std::endl;
    int sum = *a + *b;
    int diff = (*a) - (*b) ;
    a = &sum;
    b = &diff;
}

int main() {
    int a{}, b{};
    int* pa = &a, * pb = &b;

    scanf_s("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}