/*Beginning with an empty binary search tree, Construct binary search tree by inserting the
values in the order given. After constructing a binary tree -i. Insert new node, ii. Find number of
nodes in longest path from root, iii. Minimum data value found in the tree, iv. Change a tree so
that the roles of the left and right pointers are swapped at every node, v. Search a val*/

#include<iostream>
#include<algorithm>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val){
        data = val;
        right=NULL;
        left=NULL;
    }
};

class BST{

    public:

   node* InsertElement(int val , node* root){
    
    if(root==NULL){
        node* child = new node(val);
        root = child;
        return root;
    }

    if(val <= root->data){
        root->left = InsertElement(val , root->left);
    }
    if(val > root->data){
        root->right = InsertElement(val , root->right);
    }
    
    return root;
    
    }

   int Height(node* root){
       if(root==NULL){
           return -1;
       }

       int lheight = Height(root->left);
       int rheight = Height(root->right);

       return max(lheight , rheight) + 1 ;
   }
    
    void MinValueNode(node* root){
           while(root->left!=NULL){
               root = root->left;
           }
           cout<<"Min Value node is - "<<root->data<<endl;
    }
     
    void Inorder(node* root){
        if(root==NULL){
            return;
        }
        Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);
    }
    
    void Search(int val , node* root){
        if(root == NULL){
            cout<<"No element found"<<endl;
            return;
        }
        if(root->data == val){
            cout<<"Element found "<<endl;
            return;
        }
        if( val < root->data ){
            Search(val , root->left);
        }
        if(val > root->data ){
            Search(val , root->right);
        }
        return;
    }

    void Mirror(node* root){
        if(root==NULL){
            return ;
        }
        
        Mirror(root->left);
        Mirror(root->right);
        node* temp = root->left;
        root->left = root->right;
         root->right = temp;
        return; 
    }
    

};

int main(){
    int ch;
    int key;
    BST btree;

    // initially root is null
    node* root = NULL;

    do{
        cout<<"1 Insert Element in BST"<<endl;
        cout<<"2 Find Height Of Tree"<<endl;
        cout<<"3 Minimum Data Node In Tree"<<endl;
        cout<<"4 Mirror Binary Tree"<<endl;
        cout<<"5 Search In Binary Tree"<<endl;
        cout<<"6 Inorder Traversal "<<endl;
        cout<<"0 Exit"<<endl;
        cout<<"Enter your choice - ";
        cin>>ch;
        switch(ch){
            case 1:
            cout<<"Enter the value you want to insert - ";
            cin>>key;
            root = btree.InsertElement(key , root);
            break;
            case 2:
            key = btree.Height(root);
            cout<<"Height of the Tree is - "<<key<<endl;
            break;
            case 3:
            btree.MinValueNode(root);
            break;
            case 4:
            cout<<"Enter the key to search "<<endl;
            cin>>key;
            btree.Search(key,root);
            break;
            case 5:
            btree.Mirror(root);
            case 6:
            btree.Inorder(root);
            cout<<endl; 
            break;
            default:
            cout<<"Enter valid option"<<endl;
            break;

        }
    }while(ch!=0);

}