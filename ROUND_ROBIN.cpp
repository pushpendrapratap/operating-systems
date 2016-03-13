#include<iostream>
#include<limits.h>
#define n_process 4
#define q_size 3           //its size will be always (n_process-1)
#define arr_size 15 
#define TQ 2       
using namespace std;

struct table{
  char process;
  int BT;
  int AT;
  int count;
  bool flag,live,alone;
 };
struct qu{
	struct table tt;
};
struct queue{
	int front, rear, size, capacity,pull;
	struct qu* qq;
};
struct queue* create(int cap){
	struct queue* q1=new queue;
	q1->capacity=cap;
    q1->qq=new qu[q1->capacity];
	q1->front=0;
	q1->rear=-1;
	q1->pull=q1->size=0;
	return q1;
}
/////////////////////////////////////////////////// ready queue functions
bool isempty(struct queue* q1){
	if(q1->size==0)
	  return true;
	else
	  return false;  
}
bool isfull(struct queue* q1){
	if(q1->size==q1->capacity)
	  return true;
	else
	  return false;  
}
void enq(struct queue* q2,struct table x){
	bool ram=isfull(q2);
	if(ram==false){
		q2->rear=((q2->rear)+1)%q2->capacity;
		q2->qq[q2->rear].tt=x;
		(q2->size)++;
	}
	else
	   cout<<"\nqueue is full\n";
}
void deq(struct queue* q2){
	bool lux=isempty(q2); 
   if(lux==false){
   	 q2->front=((q2->front)+1)%q2->capacity;
   	 (q2->size)--;
   }
   else
     cout<<"\nqueue is empty\n";
}
void show(struct queue* q1){
	struct queue* q2=q1;
	bool lux=isempty(q2); 
	if(lux==false){
	
	if(q2->front<q2->rear){
	for(int i=q2->front;i<=q2->rear;i++)
	  cout<<q2->qq[i].tt.process<<"  "; 
   }
   else if(q2->front>q2->rear){
	for(int i=q2->front;i<n_process;i++)
	  cout<<q2->qq[i].tt.process<<"  ";
	for(int j=0;j<=q2->rear;j++)
	  cout<<q2->qq[j].tt.process<<"  ";   
   }
  }
}
///////////////////////////////////////////////////////////// test() will be used in minbt() function
void test(struct queue* q,struct table* t){
	int i,j,k,counter1,counter2;
	char ch;
	 i=j=k=counter1=counter2=0;
	for(i=0;i<n_process;i++){
		if(t[i].BT>TQ){
			k=i;
			counter1++;
		}
	}
	 for(j=0;j<q_size;j++){
	 	if(q->qq[j].tt.BT>TQ){
	 	  counter2++;
	 	  ch=q->qq[j].tt.process;
	 	  for(int s=j+1;s<q_size;s++){
	 	  	if((ch==q->qq[s].tt.process) && (q->qq[j].tt.BT>TQ))
	 	  	   counter2--;
	 	  }
	   }
	 }
	if(counter1==counter2==1)
	   t[k].alone=true;
	else
	    t[k].alone=false;	      
}
///////////////////////////////////////////////////////////////
char* minbt(struct table t[],char arr[]){
  struct table node;
   struct table* temp=new table[n_process];
  struct queue* q3=create(q_size);
   
   for(int i=0;i<n_process;i++){
   	temp[i]=t[i];
   }
    int j=0,i=0,k=0,p=0;
	    
  for(p=0;p<q_size;p++){
  	
  	node.process='\0';
    node.BT=INT_MAX;
    node.AT=INT_MAX;
    node.count=0;
    node.flag=false;
    node.live=false;
    node.alone=false;
  
  for(j=0;j<n_process;j++){	
     if(temp[j].AT<=node.AT  &&  temp[j].BT>0  &&  temp[j].flag!=true){  
          node=temp[j]; 
          k=j;
       }
    }
      enq(q3,node);
      (q3->pull)++;
      temp[k].flag=true;
      temp[k].live=true;
   }
   	
     cout<<"\nI am ready queue at different instant: \n";
     
    while(i<arr_size){     
   	  while(q3->qq[q3->front].tt.count<TQ && q3->qq[q3->front].tt.BT>0 && i<arr_size){   
   	 	arr[i]=q3->qq[q3->front].tt.process;
   	 	i++;
   	 	for(int s=0;s<n_process;s++){
   	 		if(temp[s].process==q3->qq[q3->front].tt.process){
   	 		  temp[s].flag=false; 
   	 		  temp[s].BT--;
   	 	   }
   	 	}   	 	
   	 	q3->qq[q3->front].tt.BT--;
   	 	q3->qq[q3->front].tt.count++;
   	 }
   cout<<"\n";
   	 show(q3);
   	 deq(q3);
   	 test(q3,temp);

   	node.process='\0';
    node.BT=INT_MAX;
    node.AT=INT_MAX;
    node.count=0;
    node.flag=false;
    node.live=false;
    node.alone=false;
    
     for(j=0;j<n_process;j++){	
     if(temp[j].BT>0  &&  (temp[j].flag!=true || temp[j].alone==true)  &&  q3->pull>temp[j].AT  &&  (temp[j].live!=true || temp[j].AT<=node.AT) ){    
          node=temp[j]; 
          k=j;
       }
    }    
//    cout<<"\nerror check for last D: value of node: "<<node.process<<" "<<node.BT<<" "<<node.AT<<" "<<node.count<<" "<<node.flag<<"\n";    	
      enq(q3,node);
      (q3->pull)++;
      temp[k].flag=true;
      temp[k].live=true;  
   }
   return arr;
}
/////////////////////////////////////////////////////////////////  find() will be used in finding TT & WT later on
int find(char ch,char arr[]){
 	int i=arr_size;
 	while(i>=0){
 		if(arr[i]==ch)
 		  return (i+1);
 		i--;  
 	}  
 } 
//////////////////////////////////////////////////////////
int main(){
	 struct table t1[4]={  //process,BT,AT,count,flag,alone
	    'A',4,0,0,false,false,false,  
        'B',3,1,0,false,false,false,
        'C',3,2,0,false,false,false,
        'D',5,3,0,false,false,false
       };
         
int sum=0,TT=0,WT=0;
float avg_tt=0,avg_wt=0; 

for(int i=0;i<n_process;i++){
  sum=sum+t1[i].BT;
 }
 
int n=sum; 

int finish=0;
char* arr1=new char[n];
char* arr=new char[n];

arr=minbt(t1,arr1);
cout<<"\n\n\n";
cout<<"process"<<"  "<<"BT"<<" "<<"AT"<<" "<<"TT"<<" "<<"WT"<<"\n";

for(int i=0;i<n_process;i++){
	finish=find(t1[i].process,arr);
	TT=finish-t1[i].AT;
	avg_tt=avg_tt+TT;
	 WT=TT-t1[i].BT;
	 avg_wt=avg_wt+WT; 
	 cout<<"\n"<<t1[i].process<<"        "<<t1[i].BT<<"  "<<t1[i].AT<<"  "<<TT<<"  "<<WT;
} 
 cout<<"\n\n";
for(int i=0;i<n;i++)
 cout<<arr[i]<<"  "; 
cout<<"\navg. TT is "<<(avg_tt/n_process);
cout<<"\navg. WT is "<<(avg_wt/n_process)<<"\n";  
 
return 0;
}
