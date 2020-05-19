#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,cow;
    cin>>n>>cow;
    int* arr=new int[n];
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    int low=0;
    int high=arr[n-1];
    int best=0;
    sort(arr,arr+n);
    while(low<=high){
      int count=1;
      int left=0;
      int mid=(low+high)/2;
      for(int i=1;i<n && count<cow; i++){
        if(arr[i]-arr[left]>=mid){
          count++;
          left=i;
        }
      }

      if(count>=cow){
            best=mid;
            low=mid+1;
      }else{
        high=mid-1;
      }

    }
    cout<<best<<endl;
  }
}
