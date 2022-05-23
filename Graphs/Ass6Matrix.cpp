#include<iostream>
#include<map>
#include<queue>
#include<vector>

using namespace std;
#define size 5
class Graph{
int adjMatrix[size][size];
public:
Graph(){
    // initialize matrix with 0
    for(int i=0 ; i<size ; i++){
        for(int j=0 ; j<size ; j++){
            adjMatrix[i][j]=0;
        }
    }
}
void AddEdge(){
      int v1 ;
      int v2;
      
      cout<<"Enter vertex 1 - ";
      cin>>v1;
      cout<<"Enter vertex 2 - ";
      cin>>v2;

      adjMatrix[v1][v2]=1;
      adjMatrix[v2][v1]=1;
      cout<<"Edge created succussfully !!";
}
void PrintMatrix(){
    cout<<"--- Adjacency Matrix ---"<<endl;
    for(int i=0 ; i<size ; i++){
        cout<<i<<" - ";
        for(int j=0 ; j<size ; j++){
            cout<<adjMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

// BFS
void BFS(){
    int src;
    cout<<"Choose starting vertex ";
    cin>>src;
    map<int , bool>visited;
    queue<int> q;
    // push first node and mark it as visited;
    q.push(src);
    visited[src]=true;
    while(!q.empty()){
        // remove the front node from queue and
        // print the node and add adjacent nodes 
        auto node = q.front();
        q.pop();
        cout<<" "<<node;
        // push all the unvisited adjacent nodes in the queue
        for(int i=0 ; i<size ; i++){
            if(!visited[i] && adjMatrix[node][i]==true){
                // mark its adjacent node as visited
                q.push(i);
                visited[i]=true;
            }
        }
    }
}

// DFS_Helper;
void DFS_Helper(int src , vector<bool> &visited ){
    // print current node and mark it as true
    cout<<src<<" ";
    visited[src]=true;
    // go to its adjacent vertext and go to their adjacent vertex
    // by recursion
    for(int i=0 ; i<size ; i++){
        // if node is adjacent to node
        if(visited[i]==false && adjMatrix[src][i]==1){
    //  call DFS for them 
            DFS_Helper(i,visited);
        }
    }
}
// DFS
void DFS(){
vector<bool> visited(size , false);
int src;
cout<<"Enter the starting vertex - ";
cin>>src;
DFS_Helper(src,visited);

}
};


int main(){

    Graph g;
    int ch;
    do{
        cout<<"1 Add Edge "<<endl;
        cout<<"2 Print Matrix "<<endl;
        cout<<"3 BFS Traversal "<<endl;
        cout<<"4 DFS Traversal "<<endl;
        cout<<"Enter the choice - ";
        cin>>ch;

        switch(ch){
            
            case 1:
            g.AddEdge();
            break;

            case 2:
            g.PrintMatrix();
            break;

            case 3:
            g.BFS();
            cout<<endl;
            break;

            case 4:
            g.DFS();
            cout<<endl;
            break;

            default:
            cout<<"enter valid option"<<endl;
            break;
        }

    }while(ch!=0);

}