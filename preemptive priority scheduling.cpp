#include<iostream>
#include<limits.h>
using namespace std;

struct table{
  char process;
  int BT;
  int AT;
  int p;
 };
 
char* minbt(struct table t[],int n1,int n,char arr[]){
  struct table node;
   struct table* temp=new table[n1];
   
   for(int i=0;i<n1;i++){
   	temp[i]=t[i];
   }
    int j=0,i=0,k=0;
	    
  for(i=0;i<n;i++){	
  	node.process='\0';
  node.BT=INT_MAX;
  node.AT=INT_MAX;
  node.p=INT_MAX;
  
  for(j=0;j<n1;j++){	
     if(temp[j].p<=node.p  &&  temp[j].BT>0  &&  i>=temp[j].AT){  
          node=temp[j]; 
          k=j;
       }
   }
    arr[i]=node.process;
     temp[k].BT--;
  }
   return arr;
 }
 
 int find(char ch,char arr[],int n){
 	int i=n;
 	while(i>=0){
 		if(arr[i]==ch)
 		  return (i+1);
 		i--;  
 	}  
 }
 
int main(){
  struct table t1[4]={'A',3,0,5,
        'B',6,1,2,
        'C',4,4,3,
         'D',2,6,1
       };
         
int sum=0,TT=0,WT=0;
float avg_tt=0,avg_wt=0;
int n1=4;

for(int i=0;i<n1;i++){
  sum=sum+t1[i].BT;
 }
int n=sum;
int finish=0;
char* arr1=new char[n];
char* arr=new char[n];

arr=minbt(t1,n1,n,arr1);
cout<<"\n";
cout<<"process"<<"  "<<"BT"<<" "<<"AT"<<" "<<"P"<<" "<<"TT"<<" "<<"WT"<<"\n";

for(int i=0;i<n1;i++){
	finish=find(t1[i].process,arr,n);
	TT=finish-t1[i].AT;
	avg_tt=avg_tt+TT;
	 WT=TT-t1[i].BT;
	avg_wt=avg_wt+WT; 
	 cout<<"\n"<<t1[i].process<<"        "<<t1[i].BT<<"  "<<t1[i].AT<<"  "<<t1[i].p<<"  "<<TT<<"  "<<WT;
} 
 cout<<"\n\n";
for(int i=0;i<n;i++)
 cout<<arr[i]<<"  "; 
cout<<"\navg. TT is "<<(avg_tt/n1);
cout<<"\navg. WT is "<<(avg_wt/n1);
 
return 0;
}

