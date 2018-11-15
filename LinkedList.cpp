// Example program
#include <iostream>
#include <string>

using namespace std;

struct Node
{
    int data;
    struct Node *next = nullptr;
};

class LinkedList
{
    Node* head = nullptr;

public:

    ~LinkedList()
    {
        while(head)
        {
            cout << "Deleting " << head->data << endl;
            Node *temp = head->next;
            delete head;
            head = temp;
        }
    }

    int getLength() const
    {
        int count = 0;
        Node* temp = head;
        while(temp)
        {
            ++count;
            temp = temp->next;
        }
        return count;
    }

    void print() const
    {
        Node* temp = head;
        while(temp)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    Node* createNode(int d) const
    {
        Node* temp = new Node;
        temp->next = nullptr;
        temp->data = d;

        return temp;
    }

    bool isEmpty() const
    {
        return head == nullptr;
    }

    void insertAt(int d, int position)
    {
        if(((position >= 1) && (position <= getLength() + 1))) // check for valid position given
        {
            Node* temp = createNode(d);

            if(position == 1)
            {
                temp->next = head;
                head = temp;
            }
            else if(position == getLength() + 1)
            {
                Node* t = head;
                while(t->next)
                {
                    t = t->next;
                }
                t->next = temp;
            }
            else if(position < getLength() + 1 && position > 1)
            {
                int count = 1;
                Node* t = head;
                while(t->next)
                {
                    Node* prev = t;
                    t = t->next;
                    if(++count == position)
                    {
                        prev->next = temp;
                        temp->next = t;
                        break;
                    }
                }
            }
        }
    }

    void insertEnd(int d)
    {
        insertAt(d, getLength() +1);
    }

    void insertBegin(int d)
    {
        insertAt(d, 1);
    }

    void deleteEnd()
    {
        deleteAt(getLength());
    }

    void deleteBegin()
    {
        deleteAt(1);
    }

    void deleteAt(int position)
    {
        if(((position >= 1) && (position <= getLength()))) // check for valid position given
        {
            if(position == 1)
            {
                Node* temp = head->next;
                delete head;
                head = temp;
            }
            else if(position == getLength())
            {
                Node* t = head;
                Node* prev = nullptr;
                while(t->next)
                {
                    prev = t;
                    t = t->next;
                }
                prev->next = nullptr;
                delete t;
                t = nullptr;
            }
            else if(position < getLength() && position > 1)
            {
                int count = 1;
                Node* t = head;
                while(t->next)
                {
                    Node* prev = t;
                    t = t->next;
                    if(++count == position)
                    {
                        Node* nxt = t->next;

                        prev->next = nxt;
                        t->next = nullptr;

                        delete t;
                        t = nullptr;

                        break;
                    }
                }
            }
        }
    }

    void reverse()
    {
        Node *prev = nullptr, *nxt = nullptr, *current = head;
        while(current)
        {
            nxt = current->next;
            current->next = prev;
            prev = current;
            current = nxt;
        }
        head = prev;
    }

    bool hasCycle()
    {
        bool hasCycle = false;
        Node *fast =  head, *slow =  head;
        while(slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
            {
                hasCycle = true;
                break;
            }
        }
        return hasCycle;
    }

};

int main()
{
    LinkedList *linkedListObj = new LinkedList;

    linkedListObj->insertEnd(1);
    linkedListObj->insertEnd(2);
    linkedListObj->insertEnd(3);
    linkedListObj->insertEnd(4);
    linkedListObj->insertEnd(5);
    linkedListObj->print();

    cout << endl;


    linkedListObj->insertBegin(0);
    linkedListObj->insertEnd(6);
    linkedListObj->print();

    cout << endl;

    linkedListObj->reverse();
    linkedListObj->print();

    cout << endl;


    linkedListObj->insertAt(100, 4); //insert at 4th position
    linkedListObj->print();

    cout << endl;


    linkedListObj->deleteBegin();
    linkedListObj->deleteEnd();
    linkedListObj->deleteAt(3); // delete at 3rf position
    linkedListObj->print();

    cout << endl;

    delete linkedListObj;
    linkedListObj = nullptr;

    return 0;
}
