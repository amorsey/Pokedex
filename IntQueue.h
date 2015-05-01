//Specification file for the IntQueue Class
#ifndef INTQUEUE_H
#define INTQUEUE_H

class IntQueue
{
    private:
        int *queueArray;        //Points to the queue array
        int queueSize;          //The Queue size
        int front;              //Subscript of the queue front
        int rear;               //Subscript to the queue rear
        int numItems;           //Number of items in the queue
    public:
        //Constructor
        IntQueue(int);
    
        //Copy Constructor
        IntQueue(const IntQueue &);
    
        //Queue Operations
        void enqueue(int);      //To add to the queue
        void dequeue(int &);    //To take first in the queue
        bool isEmpty() const;   //To check if queue is empty
        bool isFull() const;    //To check if queue is full
        void clear();           //To clear the queue
};
#endif