#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter the array : ";
    cin>>n;
    int arr[n];
    for(int i=0;i<=n-1;i++){
      cin>>arr[i];
}
int min =INT_MAX;
for(int i=0;i<=n-1;i++){
    if(min>arr[i])  min=arr[i];
}
cout<<min<<endl;

}