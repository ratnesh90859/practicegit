//first negtive window of k size

#include <iostream>
#include<queue>

using namespace std;

int main(){
     int arr[]={3,-4,-7,30,7,-9,2,1,6,-1};
     int k=3;
     int n= sizeof(arr)/sizeof(arr[0]);
     //-4 -4 -7 -9 -9 -9 0 -1 should be answer

     vector<int>ans;
     queue<int>q;

     for(int i=0;i<n;i++){
        if(arr[i]<0)q.push(i);  //negative waale index ko push kia queue me
     }
     int i=0;
     while(i<=n-k){
      while(q.size()>0 && q.front()<i)q.pop();
      if(q.size()==0 || q.front()>=i+k)ans.push_back(0);
      else ans.push_back(arr[q.front()]);
      i++;
     }
     for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
     }
     cout<<endl;
     for(int i=0;i<ans.size();i++){
      cout<<ans[i]<<" ";
     }
     cout<<endl;

}
