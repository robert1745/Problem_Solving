#include <bits/stdc++.h>
using namespace std;

// operations: push, pop, top, empty
// stack : LIFO

class Stack
{

public:
    int top;
    int *arr;
    int size;

    Stack()
    {
        top = -1;
        size = 1000;
        arr = new int[size];
    }

    void push(int x)
    {
        top++;
        arr[top] = x;
    }

    int pop()
    {
        int x = arr[top];
        top--;
        return x;
    }
    int top()
    {
        return arr[top];
    }

    int size()
    {
        return top + 1;
    }
};

// push , pop , top , empty
// Queue : FIFO
//[4,14,24,34]
// front , rear
class Queue
{
    int front;
    int rear;
    int size;
    int *arr;
    int cnt;
    // if front ==-1 means we can push at this index 
    // at this index number is poped out
public:
    Queue()
    {
        front = -1, rear = -1;
        size = 10;
        cnt = 0;
        arr = new int[size];
    }

    void push(int x)
    {
        if (cnt == size)
        {
            return;
        }
        if (front == -1)
        {

            arr[rear % size] = x;
            rear++;
            cnt++;
        }
    }
    // [1,2,3,4]
    // front =0, rear =5 

    void pop(){
        if(cnt==0) return;

         arr[front%size]=-1;
         front++;
         cnt--;
    }

    int top(){
        if(cnt==0) return -1;

        return arr[front%size];
    }
};