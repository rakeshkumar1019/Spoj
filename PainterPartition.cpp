#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int max_Element_arr(int* arr,int n){
int max=arr[0];
for(int i=1;i<n;i++){
  if(arr[i]>max){
    max=arr[i];
  }
}
return max;
}

int sum_Element_arr(int* arr,int n){
  int sum=0;
  for(int i=0;i<n;i++){
    sum+=arr[i];
  }
  return sum;
}

int countPainter(int* arr,int n,int maxLength){
       int painter=1;
       int total=0;
       for(int i=0;i<n;i++){
         total+=arr[i];
         if(total>maxLength){
           painter++;
           total=arr[i];
         }
       }
       return painter;
}

int Partition(int * arr,int n,int k){
  int low=max_Element_arr(arr,n);
  int high=sum_Element_arr(arr,n);
  while(low<high){
    int mid=(low+high)/2;
    int requiredPainter=countPainter(arr,n,mid);

    if(requiredPainter<=k){
      high=mid;
    }else{
      low=mid+1;
    }

  }
  return low;
}
int main(){
  int n,k;
  cin>>n>>k;
  int* arr=new int[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cout<<Partition(arr,n,k)<<endl;
}
