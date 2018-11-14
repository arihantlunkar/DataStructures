#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

class Queue
{
    struct Node *head, *tail;

public:

    bool isEmpty()
    {
        return head == nullptr;
    }

    int peek()
    {
        return head->data; // no exception handling
    }

    void push(int d)
    {
        Node* temp = new Node;
        temp->data = d;
        temp->next = nullptr;

        if(isEmpty())
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    void remove()
    {
        if(!isEmpty())
        {
            cout << "Removing " << head->data << " from queue" << endl;

            Node* temp = head->next;
            delete head;
            head = temp;
        }
    }

    void print()
    {
        Node* temp = head;
        while(temp != nullptr)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    ~Queue()
    {
        while(head != nullptr)
        {
            cout << "Deleting " << head->data << " from queue" << endl;

            Node* temp = head->next;
            delete head;
            head = temp;
        }
    }
};

int main()
{
    Queue* q = new Queue();

    q->push(1);
    q->push(2);
    q->push(3);
    q->push(4);
    q->push(5);
    q->push(6);

    q->print();

    q->remove();

    q->print();

    cout << "Peeked value is " << q->peek() << endl;

    delete q;

    return 0;
}
