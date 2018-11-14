#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

class Stack
{
    struct Node* top;

public:

    bool isEmpty()
    {
        return (top == nullptr);
    }

    int peek()
    {
        return top->data; // no exception handling
    }

    void push(int d)
    {
        Node* temp = new Node;
        temp->data = d;
        temp->next = top;
        top = temp;
    }

    void remove()
    {
        if(!isEmpty())
        {

            cout << "Removing " << top->data << " from stack" << endl;

            Node* temp = top->next;
            delete top;
            top = temp;
        }
    }

    void print()
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
    Stack* s = new Stack();

    s->push(1);
    s->push(2);
    s->push(3);
    s->push(4);
    s->push(5);
    s->push(6);

    s->print();

    s->remove();

    s->print();

    cout << "Peeked value is " << s->peek() << endl;

    delete s;
    
    return 0;
}
