#ifndef QUEUE_H
#define QUEUE_H
#pragma
#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node* next;
    Node()
    {
        next = nullptr; 
    }
};

template<typename T>
class queue
{
    Node<T>* front;
    Node<T>* rear;

public:
    queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    bool enqueue(T value)  // queue insertion
    {
        if (front == nullptr)
        {
            Node<T>* newNode = new Node<T>;
            newNode->data = value;
            newNode->next = nullptr;
            front = newNode;
            rear = newNode;
            return true;
        }
        else
        {
            Node<T>* newNode = new Node<T>;
            rear->next = newNode;
            rear->next->data = value;
            rear = rear->next;
            rear->next = nullptr;

            return true;
        }
        return false;
    }

    bool dequeue(T& temp)//queue deletion
    {
        if (front == nullptr)
            return false;
        Node<T>* delNode;
        delNode = front;
        temp = delNode->data;
        front = front->next;
        delete delNode;
        return true;
    }


    bool isEmpty()
    {
        if (front == nullptr)
            return true;

        return false;
    }

    void display()
    {
        queue<T> obj;
        T temp;
        cout << "Data: ";
        do
        {
            dequeue(temp);
            obj.enqueue(temp);
            cout << temp << " ";
        } while (front != nullptr);

        do
        {
            obj.dequeue(temp);
            enqueue(temp);
        } while (obj.front != nullptr);
    }

    ~queue()
    {
        T temp;
        do
        {
            dequeue(temp);
        } while (front != nullptr);
    }
};


#endif 