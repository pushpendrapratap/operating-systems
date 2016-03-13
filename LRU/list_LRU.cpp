#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<utility>
#include<limits.h>
using namespace std;

typedef list<int>::iterator lit;

bool v_search(list<int> &v3,int item)
{
	for(lit it=v3.begin() ; it!=v3.end() ; it++)
	{
		if(*it==item)
		   return true;
		else
		  continue;   
	}
	return false;
}

lit v_search2(list<int> &v5,int item)
{
	for(lit it=v5.begin() ; it!=v5.end() ; it++)
	{
		if(*it==item)
		   return it;	   
	}
}

int main(){
	int page_fault=0;
	
	list<int> v(3);  
	for(lit it=v.begin() ; it!=v.end() ; it++)
           *it=-1;
	
	int str[]={7,0,1,2,0,3,0,4,2,3,0,3,0,3,2,1,2,0,1,7,0,1};
	int x=sizeof(str)/sizeof(str[0]);
	vector<int> tars(str,str+x);
	
	cout<<"\nReference String is: ";
	for(int i=0;i<tars.size();i++)
	   cout<<tars[i]<<" ";
	cout<<"\n\n";   
	
	for(int i=0;i<tars.size();i++)
	{
		if(v_search(v,tars[i]))
		{
		  lit it=v_search2(v,tars[i]);
		  v.erase(it);
		  v.push_back(tars[i]);
		  cout<<".\n";
		  continue;
		}
		else
		{
		   if(find(v.begin(),v.end(),-1)!=v.end())
		   {
		   	 lit it=find(v.begin(),v.end(),-1);
		   	 *it=tars[i];
		   	 page_fault++;
		   	 
		   	 for(lit it=v.begin() ; it!=v.end() && *it!=-1 ; it++)
		   	    cout<<*it<<"  ";
		   }
		   else
		   {
		   	 v.erase(v.begin());
		   	 v.push_back(tars[i]);
		   	 page_fault++;
		   	 
		   	 for(lit it=v.begin() ; it!=v.end() ; it++)
		   	   cout<<*it<<"  ";
		   }
		}
		cout<<"\n";    
	}
	cout<<"\nTotal page fault is: "<<page_fault<<"\n\n";
}

