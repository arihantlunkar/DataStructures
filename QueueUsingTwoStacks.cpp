#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node* next = nullptr;
};

class Stack
{
    struct Node* top = nullptr;

public:

    bool isEmpty() const
    {
        return (top == nullptr);
    }

    int peek() const
    {
        return top->data; // no exception handling done here (top could be nullptr)
    }

    void push(int d)
    {
        Node* temp = new Node;
        temp->data = d;
        temp->next = top;
        top = temp;
    }

    void pop()
    {
        if(!isEmpty())
        {
            Node* temp = top->next;
            delete top;
            top = temp;
        }
    }

    void print() const
    {
        Node* temp = top;
        while(temp != nullptr)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    ~Stack()
    {
        while(top != nullptr)
        {
            Node* temp = top->next;
            delete top;
            top = temp;
        }
    }
};

class QueueUsingTwoStacks
{
    Stack *stack1 = nullptr, *stack2 = nullptr;
    
    public:
    
    QueueUsingTwoStacks()
    {
        stack1 = new Stack;
        stack2 = new Stack;
    }
    
    ~QueueUsingTwoStacks()
    {
        delete stack1;
        stack1 = nullptr;
        
        delete stack2;
        stack2 = nullptr;
    }
    
    void enqueue(int d)
    {
        stack1->push(d);
    }
    
    void print()
    {
        stack1->print();
    }
    
    void dequeue()
    {
        while(!stack1->isEmpty())
        {
            stack2->push(stack1->peek());
            stack1->pop();
        }
        
        stack2->pop();
        
         while(!stack2->isEmpty())
        {
            stack1->push(stack2->peek());
            stack2->pop();
        }
    }
};

int main()
{
    QueueUsingTwoStacks* queueObj = new QueueUsingTwoStacks();

    queueObj->enqueue(1);
    queueObj->enqueue(2);
    queueObj->enqueue(3);
    queueObj->enqueue(4);
    queueObj->enqueue(5);
    queueObj->enqueue(6);

    queueObj->print();

    queueObj->dequeue();
    queueObj->enqueue(7);


    queueObj->print();

    delete queueObj;
    queueObj = nullptr;

    return 0;
}
