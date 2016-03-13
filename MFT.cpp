#include<iostream>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100
using namespace std;
struct mem{
        int* p;
        int size;
        bool p_status;
};
int main(){
        int n,occ_space=0,i=0,j=1,p_alloc;
        cout<<"\nenter the no. of processes you want ";
        cin>>n;
        int int_frag[n],ext_frag=0;
        struct mem* arr=new mem[n];

        for(int x=0;x<n;x++)
                int_frag[x]=0;

        for(int x=0;x<n;x++)
                arr[x].p_status=false;

        while(i!=n){
                if(occ_space<=MAX_SIZE && i<(n-1)){
                        cout<<"\nenter initial mem_space of process: ";
                        cin>>p_alloc;
                        arr[i].size=p_alloc;
                        occ_space=occ_space+arr[i].size;
                        cout<<"remaining memory is: "<<(MAX_SIZE-occ_space);
                        i++;
                }
                else if(occ_space<=MAX_SIZE && i==(n-1)){
                        cout<<"\nautomatic remaining mem_space alloacted to last process. ";
                        arr[i].size=(MAX_SIZE-occ_space);
                        occ_space=occ_space+arr[i].size;
                        cout<<"\nremaining memory is: "<<(MAX_SIZE-occ_space);
                        i++;
                }
    else
                        occ_space=occ_space-arr[i].size;
        }
        cout<<"\ninitial mem_space for diff. processes have been allocated,now proceed... \n";

        for(int x=0;x<n;x++)
                arr[x].p=new int[arr[x].size];

        for(int x=0;x<n;x++)
                for(int y=0;y<arr[x].size;y++)
                        arr[x].p[y]=0;

        while(j!=(n+1)){
                bool status=false;
                int p_size;
                cout<<"\nEnter process size: ";
                cin>>p_size;
                for(int x=0 ; x<n && status==false ; x++){
                        if(arr[x].size>=p_size && arr[x].p_status==false){
                                for(int y=0;y<p_size;y++){
                                        arr[x].p[y]=j;
                                }
                                arr[x].p_status=true;
                                j++;
                                status=true;
                        }
                }
                if(status==false){
                        cout<<"\np_size is large,please enter another p_size value: ";
                }
        }
        cout<<"\nmem_allocation list is: \n";
        for(int x=0;x<n;x++){
                for(int y=0;y<arr[x].size;y++){
                        cout<<arr[x].p[y]<<" ";
                }
                cout<<"\n";
        }

         for(int x=0;x<n;x++){
                for(int y=0;y<arr[x].size;y++){
                        if(arr[x].p[y]==0)
                                int_frag[x]=int_frag[x]+1;
                }
        }

        cout<<"\nInternal fragmentation is: ";
        for(int x=0;x<n;x++)
                cout<<int_frag[x]<<"  ";

        cout<<"\nExternal fragmentation is: ";
        for(int x=0;x<n;x++)
                ext_frag=ext_frag+int_frag[x];
        cout<<ext_frag<<"\n\n";

   return 0;
}

