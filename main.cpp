#include <iostream>
#include <cassert>
template <class T>
class QueueNode {
public:
    T data;
    QueueNode<T> *next;
    QueueNode(const T & data = 0, QueueNode<T>* next = NULL):data(data), next(next){};
};
template<class T>
class Queue{
    QueueNode<T> * tail;
    QueueNode<T> * root;
    T length;
    void makeEmpty(){
        while(is_empty())
        Dequeue();
    }
public:

    Queue():root(nullptr), tail(nullptr), length(0){};
    ~Queue() { makeEmpty();}
    bool is_empty() const { return root == NULL; }

    void enqueue(const T & data)
    {
        if(is_empty()) {
            root = new QueueNode(data);
            tail = root;
        }
        else {
            tail->next = new QueueNode(data);
            tail = tail->next;

        }
        length++;
    }

    void Dequeue() {
        if(is_empty())
            throw std::logic_error("Queue is empty !!!");
        QueueNode<T> * temp = root;
        if(root == tail)
            tail = temp->next;
        root = root->next;
        delete temp;
        length--;
    }

    T back() const {
        if(is_empty())
            throw std::logic_error("You can not get back elements !!!");
        return tail->data;
    }

    T front() const {
        if(is_empty())
            throw std::logic_error("You can not get front elements !!!");
        return root->data;
    }

    size_t size(){
        return length;
    }

    void print(){
        QueueNode<T> * temp = root;
        while(temp != NULL)
        {
            std::cout<<temp->data<<" "; 
            temp = temp->next;
        }
    }
};

int main()
{
    Queue<int> myQueue;

    // Test case 1: Empty Queue Test
    assert(myQueue.is_empty());

    // Test case 2: Enqueue Test
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    // Test case 3: Dequeue Test
    myQueue.Dequeue();
    myQueue.Dequeue();
    myQueue.Dequeue();
    assert(myQueue.is_empty());

    // Test case 4: Front and Back Test
    myQueue.enqueue(100);
    myQueue.enqueue(200);
    assert(myQueue.front() == 100);
    assert(myQueue.back() == 200);

    // Test case 5: Size Test
    assert(myQueue.size() == 2);

    // Test case 6: Print Test
    myQueue.enqueue(300);
    myQueue.print();
    return 0;
}