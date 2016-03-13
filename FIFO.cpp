#include<iostream>
#include<limits.h>
using namespace std;
struct queue
{
	int front,rear,size,capacity;
	int* array;
};
struct queue* create(int cap)
{
	struct queue* q=new queue;
	q->capacity=cap;
	q->front=q->size=0;
	q->rear=-1;
	q->array=new int[q->capacity];
	
	for(int i=0;i<q->capacity;i++)
	   q->array[i]=-1;
	   
	return q;
}
bool isfull(struct queue* q)
{
	if(q->size==q->capacity)
	  return true;
	else
	   return false;  
}
bool isempty(struct queue* q)
{
	if(q->size==0)
	   return true;
	else
	  return false;   
}
void enq(struct queue* q,int item)
{
	if(isfull(q))
	    return;
	q->rear=(q->rear+1)%q->capacity;
	q->array[q->rear]=item;
	q->size=q->size+1;    
}
int deq(struct queue* q)
{
	if(isempty(q))
	    return INT_MIN;
	int item=q->array[q->front];
	q->front=(q->front+1)%q->capacity;
	q->size=q->size-1;
	return item;	 
}
bool find(int* arr,int n,int x)
{
	for(int i=0;i<n;i++)
	{
		if(arr[i]==x)
		   return true;
		else
		   continue;  
	}
	return false;
}

int main()
{
	int page_fault=0;
	struct queue* q=create(3);
	int str[]={7,0,1,2,0,3,0,4,2,3,0,3,0,3,2,1,2,0,1,7,0,1};
	int x=sizeof(str)/sizeof(str[0]);
	
	for(int i=0;i<x;i++)
	{
		bool state=find(q->array,q->capacity,str[i]);
        if(state==true){
	      cout<<".\n\n";
		   continue;
		}
		else
		{
			if(isfull(q))
			{
			   deq(q);	 
			   enq(q,str[i]);
			   for(int j=0;j<q->size;j++)
			      cout<<q->array[j]<<"  ";
			   page_fault++;   
			}
			else
			{
			   enq(q,str[i]);
			   for(int j=0;j<q->size;j++)
			       cout<<q->array[j]<<"  ";	
			   page_fault++;    
			}   
	    }
	    cout<<"\n";
	}
	cout<<"\nTotal no. of page fault is: "<<page_fault<<"\n";
}
