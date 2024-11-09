/*
code by Subrata Mondal
*/
#include<iostream>
#include<vector>
#include<list>
using namespace std;
#define dwg directed_weighted_graph

vector<list<pair<int ,int > > >dwg;
int v; // no of vertices
void add_edge(int src,int dest,int wt){
    dwg[src].push_back(make_pair(dest,wt));
}

void display(){
    for(int i=0;i<dwg.size();i++){
        cout<<i<<" -> ";
        for(auto el : dwg[i]){
            cout<<"("<<el.first <<" , " <<el.second<<") , ";
        }
        cout<<endl;
    }
}

int main(){
    cin>>v;
    dwg.resize(v,list<pair<int ,int >>());
    int e;
    cin>>e;
    while(e--){
        int s,d,wt;
        cin>>s>>d>>wt;
        add_edge(s,d,wt);
    }
    display();

    /* vector of array method 2 */

    vector<pair<int,int> >va[v];//vector of array
    while(e--){
        int s,d,wt;
        cin>>s>>d>>wt;
        va[s].push_back(make_pair(d,wt));
    }
    for(int i=0;i<v;i++){
        cout<<i<<" -> ";
        for(auto el : va[i]){
            cout<<"("<<el.first <<" , " <<el.second<<") , ";
        }
        cout<<endl;
    }
}
/*
7 7
0 2 2
0 1 1
1 5 3 
2 5 2 
2 3 6
3 6 2
6 4 4
*/
