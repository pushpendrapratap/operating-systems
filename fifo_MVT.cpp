#include<iostream>
#include<vector>
using namespace std;

int main(){
        int MAX_SIZE;

        vector<int>int_frag;
        int  int_frag_count=0,sum=0;
        vector<int>v;
        vector<int>fchunk;

        cout<<"\nEnter the total mem_size for allocation: ";
        cin>>MAX_SIZE;

        int* arr=new int[MAX_SIZE];
        for(int i=0;i<MAX_SIZE;i++)
                arr[i]=0;

        int size,z,ext_frag=0,v_loc;
        int p_num=1,fchunk_count=0;;
        char ch='y',ch2='n';

        while(ch!='n'){
                int count=0;
                bool status=false;
                bool mem_status=false;
                cout<<"\nenter the process "<<p_num<<" size: ";

                v.push_back(p_num);
                cin>>size;

                for(int i=0 ; i<MAX_SIZE ; i++){
                        if(arr[i]==0){
                                int temp=i;
                                count++;
                                if(count==size && mem_status!=true){
                                        for(int i=temp+1-size ; i<(temp+1-size+count) ; i++){
                                                arr[i]=p_num;
                                                mem_status=true;
                                        }
                                }
                        }
               else{
                                count=0;
                        }
                }
                if(mem_status!=true){
                        cout<<"\nNo memory availble...Need to terminate some process...";
                        cout<<"\nDo you want to terminate any process('y'/'n'): ";
                        cin>>ch2;
                        bool v_status=false;

                        if(ch2=='y'){
                                cout<<"\nwhich process do you want to terminate:(int) ";
                                cin>>z;

                                for(int x=0 ; x<v.size() && v_status==false ; x++){
                                        if(v[x]==z){
                                                v_status=true;
                                                v_loc=x;
                                        }
                                }

                                if(v_status==true){
                                        cout<<"\nTerminate process"<<v[v_loc];
                                        for(int i=0 ; i<MAX_SIZE && status!=true ; i++){
                                                if(arr[i]==v[v_loc])
                                                        status=true;
                                                else
                                                        status=false;
                                        }
                                        if(status==true){
                                                for(int i=0;i<MAX_SIZE;i++){
                                                        if(arr[i]==v[v_loc])
                                                                arr[i]=0;
                                                }
                                        }
                                }
                                else
                                        cout<<"\nprocess"<<z<<" doesn't exist in memory";
                        }
                }
              else{
                        p_num++;
                }

                cout<<"\n";

                for(int i=0;i<MAX_SIZE;i++)
                        cout<<arr[i]<<" ";

                cout<<"\nDo you want to continue('y'/'n'): ";
                cin>>ch;
        }
        for(int i=0;i<MAX_SIZE;i++){
                if(arr[i]==0){
                        int_frag_count++;
                        if(int_frag_count==2 || int_frag_count==1){
                                if(i<(MAX_SIZE-1) && arr[i+1]!=0)
                                        int_frag.push_back(int_frag_count);
                                else if(i==(MAX_SIZE-1) && arr[i]==0)
                                        int_frag.push_back(int_frag_count);
                        }
                }
                else
                        int_frag_count=0;
        }

        cout<<"\nFree chunk list: ";
        for(int i=0;i<MAX_SIZE;i++){
                if(arr[i]==0){
                        fchunk_count++;
                        if(i<(MAX_SIZE-1) && arr[i+1]!=0)
                                fchunk.push_back(fchunk_count);
                        else if(i==MAX_SIZE-1)
                                fchunk.push_back(fchunk_count);
                }
                else
                        fchunk_count=0;
        }
        for(int i=0;i<fchunk.size();i++)
                cout<<fchunk[i]<<"  ";

     cout<<"\n";

        cout<<"\nTotal internal fragmentation is: ";
        for(int i=0;i<int_frag.size();i++)
                sum=sum+int_frag[i];
        cout<<sum;

        cout<<"\nexternal fragmentation is: ";
        for(int i=0;i<MAX_SIZE;i++){
                if(arr[i]==0)
                        ext_frag=ext_frag+1;
        }
        cout<<(ext_frag-sum)<<"\n\n";

        return 0;
}

