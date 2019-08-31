#include <iostream>
using namespace std;

class Stack
{
	int* arr;
	int top;
public:
	Stack()
	{
		top = -1;
		arr = new int;
	}
	~Stack()
	{
		delete arr;
		arr = nullptr;
	}
	void push(int d)
	{
		*(arr + ++top) = d;
	}
	void pop()
	{
		--top;
	}
	int peek()
	{
		return top < 0 ? -1 : *(arr + top); 
	}
	bool isEmpty() const
	{
		return (top == -1);
	}
	void print()
	{
		for(int i = 0; i <= top; ++i)
		{
			printf("%d\n",*(arr+i));
		}
	}
};

int main() {
	// your code goes here
	Stack stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);
	stack.print();
	printf("Stack top element %d\n",stack.peek());
	stack.pop();
	stack.pop();
	stack.print();
	printf("Stack top element %d\n",stack.peek());
	return 0;
}
