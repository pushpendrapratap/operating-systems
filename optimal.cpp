#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<limits.h>
using namespace std;

typedef vector<pair<int,int> >::iterator vit;

bool foo_neg(const pair<int,int> &a)
{
	return ((a.second < 0)==true);
}

bool foo2(const pair<int,int> &a,const pair<int,int> &b)
{
	return ((a.second < b.second)==true);
}

bool v_search(vector<pair<int,int> > v3,int item)
{
	for(vit it=v3.begin() ; it!=v3.end() ; it++)
	{
		if(it->first==item)
		   return true;
		else
		  continue;   
	}
	return false;
}

vit v_search2(vector<pair<int,int> > &v5,int item)
{
	for(vit it=v5.begin() ; it!=v5.end() ; it++)
	{
		if(it->first==item)
		   return it;	   
	}
}

int main(){
	int page_fault=0;
	
	vector<pair<int,int> > v(3);  
	for(int i=0;i<v.size();i++)
           v[i]=make_pair(-1,-1);
	
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
		   if(i<tars.size()-1 && find(tars.begin()+i+1,tars.end(),tars[i])!=tars.end()) 
		   {
		   	   int index=find(tars.begin()+i+1,tars.end(),tars[i])-tars.begin();
		   	   vit it = v_search2(v,tars[i]);         //here we use v_search2();
		   	   it->second=index;
		   	   cout<<".\n";
		   	   continue;
		   }
		   else
		   {
		       vit it = v_search2(v,tars[i]);         //here we use v_search2();
		   	   it->second=INT_MAX; 
		   	   cout<<".\n";
		   	   continue;	
		   } 
		}
		else
		{
		   if(i<tars.size()-1 && find(tars.begin()+i+1,tars.end(),tars[i])!=tars.end())    
			{
			   int index=find(tars.begin()+i+1,tars.end(),tars[i])-tars.begin();
			   
			   if(find_if(v.begin(),v.end(),foo_neg)!=v.end())     //this condition is only for initial three vector v fill-up
		       {
		         vit it = find_if (v.begin(), v.end(), foo_neg);
			     *it=make_pair(tars[i],index);
			      page_fault++;
		          
				  for(int j=0;j<v.size() && v[j].first!=-1;j++)
				    cout<<v[j].first<<"  ";	
		       }		        
		       else{  
			        vit it = max_element (v.begin(), v.end(), foo2);
			        *it=make_pair(tars[i],index);
			         page_fault++;
			      
		          for(int j=0;j<v.size() && v[j].first!=-1;j++)
				     cout<<v[j].first<<"  ";	
			   }                                     
			}
			else
			{
			    if(find_if(v.begin(),v.end(),foo_neg)!=v.end())    //this condition is only for initial three vector v fill-up
		       {
		          vit it = find_if (v.begin(), v.end(), foo_neg);
			      *it=make_pair(tars[i],INT_MAX);
			       page_fault++;
		          
			      for(int j=0;j<v.size() && v[j].first!=-1;j++)
				    cout<<v[j].first<<"  ";	
		       }		        
		       else
			   {  
		              vit it = max_element (v.begin(), v.end(), foo2);
			          *it=make_pair(tars[i],INT_MAX);
			           page_fault++;
			        
		                for(int j=0;j<v.size() && v[j].first!=-1;j++)
				          cout<<v[j].first<<"  ";	
			   }    	
		    }  			
		}
		cout<<"\n";    
	}
	cout<<"\nTotal page fault is: "<<page_fault<<"\n\n";
}

