#include <iostream>

class Queue
{
    int* arr;
    int head, tail;
    
    public:
    Queue()
    {
        head = tail = -1;
        arr = new int;
    }
    
    ~Queue()
    {
        delete[] arr;
    }
    
    void enqueue(int data)
    {
        if(head == -1)
            ++head;
            
        *(arr + ++tail) = data;
    }
    
    int peek() const
    {
        if(head == -1)
            throw head;
        
        return *(arr + head);
    }
    
    void dequeue()
    {
        if(head == -1)
            throw head;
            
        head = head == tail ? -1 : head + 1;
    }
    
    void print() const
    {
        for(int i=head;i<=tail;++i)
            printf("%d ",*(arr+i));
    }
};

int main()
{
    Queue q;
    
    try
    {
        printf("%d", q.peek());
    }
    catch(...)
    {
        printf("Queue is Empty !!!\n");
    }
    
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);   
    
    q.print(); 
    
    printf("%d ", q.peek());
    
    
    q.dequeue();
    q.dequeue();
    q.dequeue();
    
    q.print(); 
    
    printf("%d ", q.peek());
}
