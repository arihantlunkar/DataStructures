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

    void enqueue(int d)
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

    void dequeue()
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
    Queue* queueObj = new Queue();

    queueObj->enqueue(1);
    queueObj->enqueue(2);
    queueObj->enqueue(3);
    queueObj->enqueue(4);
    queueObj->enqueue(5);
    queueObj->enqueue(6);

    queueObj->print();

    queueObj->dequeue();

    queueObj->print();

    cout << "Peeked value is " << queueObj->peek() << endl;

    delete queueObj;

    return 0;
}
