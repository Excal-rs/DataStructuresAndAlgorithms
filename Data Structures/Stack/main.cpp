#include <iostream>
#include "Stack.h"

int main(){
    Stack myStack(100);
    myStack.push(1);
    myStack.push(5);
    std::cout << myStack.peak() << '\n';
    std::cout << myStack.pop() << '\n';
    std::cout << myStack.pop() << '\n';

    return 0;
}