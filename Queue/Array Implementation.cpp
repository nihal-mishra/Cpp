#include<iostream>
using namespace std;
#define max 10

class Queue
{
    private: int arr[max],front,rear;
    public:

    Queue()
    {
        front=-1;
        rear=-1;
    }

    bool isEmpty()
    {
        if(rear==-1 && front==-1) return true;
        else return false;
    }
    bool isFull()
    {
        return (rear+1)%max == front?true:false; 
    }
    void enQ(int x)
    {
        if(isFull())
        {
            cout<<"\nQueue is full\n";
        }
        else if(isEmpty())
        {
            front=rear=0;
        }
        else
        {
            rear=(rear+1)%max;
        }
        arr[rear]=x;
    }
    void deQ()
    {
        if(isEmpty())
        {
            cout<<"\nQueue is already empty cannot remove element as it already dont have any.\n";
            return;
        }
        else if(front==rear)
        {
            front = rear = -1;
        }
        else
        {
            front=(front+1)%max;
        }
    }
    int Front()
	{
		if(front == -1)
		{
			cout<<"Error: cannot return front from empty queue\n";
			return -1; 
		}
		return arr[front];
	}
    void Print()
	{
		// Finding number of elements in queue  
		int count = (rear+max-front)%max + 1;
		cout<<"Queue       : ";
		for(int i = 0; i <count; i++)
		{
			int index = (front+i) % max; // Index of element while travesing circularly from front
			cout<<arr[index]<<" ";
		}
		cout<<"\n\n";
	}
};
int main()
{
    Queue Q; // creating an instance of Queue. 
   Q.enQ(2);  Q.Print();  
   Q.enQ(4);  Q.Print();  
   Q.enQ(6);  Q.Print();
   Q.deQ();	  Q.Print();
   Q.enQ(8);  Q.Print();
}