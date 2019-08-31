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
		delete[] arr;
	}
	void push(int d)
	{
		*(arr + ++top) = d;
	}
	void pop()
	{
		if(top < 0)
			throw top;
		--top;
	}
	int peek()
	{
		if(top < 0)
			throw top;
		return *(arr + top); 
	}
	bool isEmpty() const
	{
		return (top == -1);
	}
	void print() const
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
	try
	{
		stack.peek();
	}
	catch(...)
	{
		printf("Stack is empty\n");		
	}
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);
	stack.print();
	try
	{
		printf("Stack top element %d\n",stack.peek());
		stack.pop();
		stack.pop();
	}
	catch(...)
	{
		printf("Stack is empty\n");		
	}
	stack.print();
	return 0;
}
