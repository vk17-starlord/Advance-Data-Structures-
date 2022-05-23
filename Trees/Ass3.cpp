#include<iostream>
#include<string>

using namespace std;

class node{

public: string label;
        int count;
        node* subchapter[10];
};

class Tree{
    node* root = NULL;
    public:

    void Insert(){
        root = new node();
        cout<<"Enter the Title - ";
        getline(cin , root->label);
        cout<<"Enter no. of chapters - ";
        cin>>root->count;

        int ch_count = root->count;
        for(int i=0 ; i<ch_count;i++){
            // initialize new node
            
            root->subchapter[i]=new node();
            
            cout<<"Enter name of chapter "<<i+1<<"- ";
            cin>>root->subchapter[i]->label;
            cout<<"Enter number of sub sections - ";
            cin>>root->subchapter[i]->count;
            
            int s_count = root->subchapter[i]->count;
            
            for(int j=0 ; j<s_count;j++){
            // initialize new node
             root->subchapter[i]->subchapter[j]=new node();

             cout<<"Enter name of subsection "<<j+1<<"- ";
             cin>>root->subchapter[i]->subchapter[j]->label;
            }
        }
    }

    void Display(){
        cout<<"Title - "<<root->label<<endl;
        for(int i=0 ; i<root->count;i++){
            cout<<"---"<<i+1<<"-"<<root->subchapter[i]->label<<endl;
        for(int j=0 ; j<root->subchapter[i]->count;j++){
            cout<<"------"<<i+1<<"."<<j+1<<" - "<<root->subchapter[i]->subchapter[j]->label<<endl;
        }
        }
    }
};

int main(){
    Tree tr;
    tr.Insert();
    tr.Display();
}