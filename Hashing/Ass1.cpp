#include<iostream>
using namespace std;
class node{
    public:
int key;
long long tel;
node(){
    key=-1;
    tel=-1;
}

node(int k , long long t){
    key = k;
    tel = t;
}

};

class HashMap{
public:
int size = 10;
node* HashTable[10];

HashMap(){
//    initialize hashtable to 0
for(int i=0 ; i<size ; i++){
    HashTable[i] = new node();
}
}

// hash function to get the key

int HashFunc(int key){
    return key%10;
}

void InsertElement(){
    int key;
    long long tel;
    if(IsFull()){
        cout<<"HashMap Overflow"<<endl;
        return;
    }
    cout<<"Enter the Telephone Number - ";
    cin>>tel;

    cout<<"Enter the Key - ";
    cin>>key;

    int index = HashFunc(key);
    if(HashTable[index]->key==-1){
        HashTable[index]->key = key;
        HashTable[index]->tel = tel;
        cout<<"Value Inserted Succussfully !!"<<endl;
    }else{

        HandleCollison(index , key , tel);

    }
}

void HandleCollison(int index , int key , long long tel){
int ch;
cout<<"1 - Linear Probing "<<endl;
cout<<"2 - Quadratic Probing "<<endl;
cout<<"Select Your Option - ";
cin>>ch;
if(ch==1){
   index = LinearProbing(index); 
}else if(ch==2){
   index = QuadraticProbing(index); 
}else{
    cout<<"Select Correct Option";
}
        if(index==-1){
            cout<<"No Space Found"<<endl;
            return;
        }
        HashTable[index]->key = key;
        HashTable[index]->tel = tel;
        cout<<"Value Inserted Succussfully !!"<<endl;
}

bool IsFull(){
    bool res = true;
    for(int i=0 ;i<size ; i++){
        if(HashTable[i]->key==-1){
            res = false;
            break;
        }
    }
    return res;
}


int QuadraticProbing(int index){
    int probe = 1;
    int i=0;
    while(i<size-1){
        index = ((index)+i*i)%10;
        if(HashTable[index]->key==-1){
            break;
        }
        i++;
        probe++;
    }

    if(i<size-1){
        return index;
    }

    return -1;
}
int  LinearProbing(int index){
    int i=0;
    while(i<size-1){    
        index = ((index % 10) + 1) % 10;
        if(HashTable[index]->key == -1){
            break;
        }
        i++;
    }
    
    if(i<size-1){
        return index;
    }
return -1;
}


void SearchElement(){
int key;
cout<<"Enter the key you want to search - ";
cin>>key;
int index = HashFunc(key);
if(HashTable[index]->key == key){
    cout<<"Element Found Successfully in 1 comparision!! ";
    return;
}
int ch;
cout<<"1 - Linear Probing Search "<<endl; 
cout<<"2 - Quadratic Probing Search "<<endl; 
cin>>ch;
if(ch==1){
     LinearSearch(index , key);
}
else{
     LinearSearch(index , key);
}
return;
}

void LinearSearch(int index, int key){
    int i=0;
    while(i<size-1){
        index = ((index%10)+1)%10;
        if(HashTable[index]->key==key){
            break;
        }
        i++;
    }
    if(i==size-1){
        cout<<"Element Not Found !"<<endl;
        return;
    }
    cout<<"No. of comparisions - "<<i+1<<endl;
    cout<<"Telephone - "<<HashTable[i]->tel<<endl;
    return;
}

void QuadraticSearch(int index , int key){
int i=0;
int probe;
    while(i<size-1){
        index = (index%10)+probe*probe;
        if(HashTable[index]->key==key){
            break;
        }
        i++;
        probe++;
    }
    if(i==size-1){
        cout<<"Element Not Found !"<<endl;
        return;
    }
    cout<<"No. of comparisions - "<<i+1<<endl;
    cout<<"Telephone - "<<HashTable[i]->tel<<endl;
    return;
}

void DisplayTable(){
 cout<<"Hash-Table"<<endl;
 for(int i=0; i<size ; i++){
     cout<<i<<" : "<<HashTable[i]->key<<" "<<HashTable[i]->tel<<endl;
 }
}

};

int main(){
int ch;
HashMap hmap;
do{

cout<<"1 Insert Element "<<endl;
cout<<"2 Search Element "<<endl;
cout<<"3 Display Element "<<endl;
cout<<"Enter Your Choice - ";
cin>>ch;
switch(ch){
case 1:
hmap.InsertElement();
break;

case 2:
hmap.SearchElement();
break;

case 3:
hmap.DisplayTable();
break;

default:
cout<<"Enter Valid Option"<<endl;
break;

}
}while(ch!=0);
}