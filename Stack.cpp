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
            cout << "Removing " << top->data << " from stack" << endl;

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
            cout << "Deleting " << top->data << " from stack" << endl;

            Node* temp = top->next;
            delete top;
            top = temp;
        }
    }
};

int main()
{
    Stack* stackObj = new Stack();

    stackObj->push(1);
    stackObj->push(2);
    stackObj->push(3);
    stackObj->push(4);
    stackObj->push(5);
    stackObj->push(6);

    stackObj->print();

    stackObj->pop();

    stackObj->print();

    cout << "Peeked value is " << stackObj->peek() << endl;

    delete stackObj;
    stackObj = nullptr;
    
    return 0;
}
