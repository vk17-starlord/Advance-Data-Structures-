#include<iostream>
#include<queue>
#include<map>
#include<list>
#include<unordered_map>

using namespace std;

class Graph{

unordered_map<string , list<string>> locations ;

public:
void AddEdge(){
    string s1 , s2;
    cout<<"enter the vertex 1 - ";
    cin>>s1;
    cout<<"enter the vertex 2 - ";
    cin>>s2;

    locations[s1].push_back(s2);
    locations[s2].push_back(s1);

    cout<<" Added Edge Succussfully !! ";
}

     void PrintList(){
    cout<<"----- Adjacency List  ------ "<<endl;
     for(auto it : locations)
     {
         auto loc = it.first;
         cout<<loc<<" - ";
         for(auto nbr : locations[loc]){
             cout<<"->"<<nbr;
         }
         cout<<endl;
     }
    }

     void BFS(){
     string src;
     cout<<"Enter the starting location - ";
     cin>>src;

     map<string , bool> visited;
     queue<string> que; 

    //  push the src in queue and mark it as visited
    que.push(src);
    visited[src]=true;

    while(!que.empty()){
        // remove the top node and print it
        string node = que.front();
        que.pop();
        cout<<node<<" ";
        // find all unvisited adjacent nodes and push them in stack and mark visited
        
        for(auto nbr:locations[node]){
            if(!visited[nbr]){
                que.push(nbr);
                visited[nbr]=true;
            }
        }

    }


    }

     void DFS_Helper(string src , map<string , bool > &visited){
        //  print the current node
        cout<<src;
        visited[src]=true;
        //  go to its adjacent nodes if not visited and visit their adjacent nodes
        for(auto nbr : locations[src]){
            if(!visited[nbr]){
                DFS_Helper(nbr , visited);
            }    
        }
     }

     void DFS(){
         string src;
         cout<<"Enter the starting location - ";
         cin>>src;
         map<string , bool> visited ;
        //  mark all nodes as not visited i.e false 
         for(auto it : locations){
              string index = it.first;
              visited[index]=false;
         }
        //  call DFS Helper 
        DFS_Helper(src , visited);
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
            g.PrintList();
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
