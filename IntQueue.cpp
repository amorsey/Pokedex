//Implementation file for the IntQueue class
#include <iostream>
#include "IntQueue.h"
using namespace std;

IntQueue::IntQueue(int s)
{
    queueArray = new int[s];
    queueSize = s;
    front = -1;
    rear = -1;
    numItems = 0;
}

IntQueue::IntQueue(const IntQueue &obj)
{
    //Allocate the queue array
    queueArray = new int[obj.queueSize];
    
    //Copy the other objects attributes
    queueSize = obj.queueSize;
    front = obj.front;
    rear = obj.rear;
    numItems = obj.numItems;
    
    //Copy the other objects queue array
    for (int count = 0; count < obj.queueSize; count++)
        queueArray[count] = obj.queueArray[count];
}

void IntQueue::enqueue(int num)
{
    if(isFull())
        cout << "The queue is full.\n";
    else
    {
        //Calculate the new rear position
        rear = (rear + 1) % queueSize;
        //Insert new item
        queueArray[rear] = num;
        //Update item count
        numItems++;
    }
}

void IntQueue::dequeue(int &num)
{
    if(isEmpty())
        cout << "The queue is empty.\n";
    else
    {
        //Move front
        front = (front + 1) % queueSize;
        //Retrieve the front item
        num = queueArray[front];
        //Update item count
        numItems--;
    }
}

bool IntQueue::isEmpty() const
{
    bool status;
    
    if (numItems)
        status = false;
    else
        status = true;
    
    return status;
}

bool IntQueue::isFull() const
{
    bool status;
    
    if (numItems < queueSize)
        status = false;
    else
        status = true;
    
    return status;
}

void IntQueue::clear()
{
    front = queueSize - 1;
    rear = queueSize - 1;
    numItems = 0;
}