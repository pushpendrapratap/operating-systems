#include<iostream>
#define n1 5
using namespace std;
int front=0, rear=-1, size=0, capacity=n1;

bool isempty(int* arr){
	if(size==0)
	  return true;
	else
	  return false;  
}
bool isfull(int* arr){
	if(size==capacity)
	  return true;
	else
	  return false;  
}
void enq(int* arr,int x){
	bool ram=isfull(arr);
	if(ram==false){
		rear=(rear+1)%capacity;
		arr[rear]=x;
		size++;
	}
	else
	   cout<<"\nqueue is full\n";
}
void deq(int* arr){
	int temp;
	bool lux=isempty(arr); 
   if(lux==false){
   	 front=(front+1)%capacity;
   	 size--;
   }
   else
     cout<<"\nqueue is empty\n";
}
void show(int* arr){
	if(front<rear){
	for(int i=front;i<=rear;i++)
	  cout<<arr[i]<<"  "; 
   }
   else if(front>rear){
	for(int i=front;i<n1;i++)
	  cout<<arr[i]<<"  ";
	for(int j=0;j<=rear;j++)
	  cout<<arr[j]<<"  ";   
   }
}
int main(){
	int* arr=new int[n1];
	enq(arr,7);
	enq(arr,3);
	enq(arr,13);	enq(arr,17);  enq(arr,21); 	deq(arr);  
	enq(arr,69); //deq(arr); deq(arr); deq(arr); deq(arr); 
	show(arr);
}
