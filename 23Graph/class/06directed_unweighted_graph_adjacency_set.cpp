#include<iostream>
#include<vector>
#include <unordered_set>
using namespace std;

vector<unordered_set<int> >uug;
int v; // no of vertices
void add_edge(int src,int dest){
    uug[src].insert(dest);
}

void display(){
    for(int i=0;i<uug.size();i++){
        cout<<i<<" -> ";
        for(auto el : uug[i]){
            cout<<el <<" , ";
        }
        cout<<endl;
    }
}

int main(){
    cin>>v;
    uug.resize(v,unordered_set<int>());
    int e;
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d);
    }
    display();
}
/*
7
7
0 2 
0 1
1 5
2 5
2 3
3 6
6 4

0 -> 1 , 2 , 
1 -> 5 , 
2 -> 3 , 5 , 
3 -> 6 , 
4 -> 
5 -> 
6 -> 4 , 
*/
