#include <iostream>

struct Stack{

    int top;
    static const int size = 10;
    int body[size];
    Stack(){
        top = -1;
    }

    bool isEmpty(){
        return (top < 0);
    }
    
    void Push(int e){
        if (top == size)
        {
            std::cout << "Stack overflow" << std::endl;
        }
        else{
            top++;
            body[top] = e;
        }
    }
    int Pop(){

        if (!isEmpty())
        {
            return body[top--]; 
        }else{
            std::cout << "Stack is empty" << std::endl;
            return 0;
        }
    }


};



int main(){

    Stack stack;
    stack.Push(1);
    stack.Push(1);
    stack.Push(1);
    stack.Push(1);
    stack.Push(1);
    stack.Push(1);
    stack.Push(1);
    stack.Push(1);
    stack.Push(1);
    stack.Push(1);
    stack.Push(1);
    stack.Push(1);
    std::cout << stack.Pop() << std::endl;
    stack.Push(2);
    stack.Push(3);
    std::cout << stack.Pop() << std::endl;
    stack.Push(4);

    std::cout << stack.Pop() << std::endl;
    std::cout << stack.Pop() << std::endl;
    std::cout << stack.Pop() << std::endl;

    return 0;
}