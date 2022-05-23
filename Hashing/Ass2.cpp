/* Implement all the functions of a dictionary (ADT) using hashing and handle collisions
 using chaining with / without replacement. Data: Set of (key, value) pairs, Keys are mapped
 to values, Keys must be comparable, Keys must be unique. Standard Operations: Insert(key,
 value), Find(key), Delete(key)*/

 #include<iostream>
 using namespace std;
class node{
public:
string key;
string value;   
int chain;
node(){
    key="-1";
    value="-1";
    chain=-1;
}

};

class Dictionary
{
private:
string def = "-1";
int size = 10;
node* HashTable[10];

public:

Dictionary(){
    for(int i=0 ; i<size ; i++){
        HashTable[i] = new node();
    }
}

int HashFunc(string key){
    int sum=0;
    for(int i=0 ; i<key.length();i++){
        sum +=(int)key[i];
    }
    return sum%10;
}

void InsertElement(){
string key;
string value;
if(IsFull()){
    cout<<"HashTable Is Full !!"<<endl;
    return;
}
cout<<"Enter value of key - ";
cin>>key;
cout<<"Enter value of value - ";
cin>>value;

int index = HashFunc(key);

if(HashTable[index]->key==def){
    HashTable[index]->key = key;
    HashTable[index]->value = value;
    cout<<"Value Inserted Succussfully !!"<<endl;
}else if(HashTable[index]->key==key){
cout<<"Key Already Exists"<<endl;
return;
}else{
    cout<<"Collision occurred at - ";
    cout<<index<<endl;
    int Newindex = LinearProbing(index , key , value);
    HashTable[Newindex]->key = key;
    HashTable[Newindex]->value = value;
    cout<<"Value Inserted Successfully !"<<endl;
    // find its parent 
    
    // check the key before updating parent
    while(HashTable[index]->chain!=-1){
        index = HashTable[index]->chain;
    }

        cout<<"updating the chain ... "<<endl;
        HashTable[index]->chain = Newindex;


}

}

bool IsFull(){
bool res = true;
for(int i=0 ; i<size ; i++){
    if(HashTable[i]->key == def){
        res = false;
        break;
    }
}

return res;
}

int LinearProbing(int index , string key , string value){
    int i=0;
    while(i<size-1){
        index = ((index%10)+1)%10;

        if(HashTable[index]->key == def){
            break;
        }
        i++;
    }
    if(i==size-1){
        return -1;
    }
    return index;
}



void DeleteElement(){
string key ;
cout<<"Enter the key you want to delete - ";
cin>>key;
int cindex = SearchHelper(key);

if(cindex!=-1){
// if found
int pindex = HashFunc(key);

while(HashTable[pindex]->chain!=-1){
        pindex = HashTable[pindex]->chain;
}

HashTable[pindex]->chain=-1;
HashTable[cindex]->key=def;
HashTable[cindex]->value=def;
HashTable[cindex]->chain=-1;

cout<<"Element Deleted Succussfully!!"<<endl;
}else{
    cout<<"No Element Found !!"<<endl;
}

}

void SearchElement(){
string key ;
cout<<"Enter the key - ";
cin>>key;
int index = SearchHelper(key);
if(index!=-1){
    cout<<"Key - "<<HashTable[index]->key<<" Value- "<<HashTable[index]->value<<endl;
}else{
    cout<<"No Element Found !!";
}
}

int SearchHelper(string key){
    
int index = HashFunc(key);

if(HashTable[index]->key == key){
return index;
}

//  finding the element by chain
int count = 1;

while(HashTable[index]->chain!=-1 || count<=size-1){
    index = HashTable[index]->chain;
    if(HashTable[index]->key==key){
        break;
    }
}

if(index==-1 || count==size-1){
    cout<<"No Element Found "<<endl;
    return -1;
}
return index;
}

void DisplayTable(){
    cout<<"Hash Table"<<endl;

    for(int i=0 ; i<size ; i++){
        cout<<i<<" "<<HashTable[i]->key<<" "<<HashTable[i]->value<<" "<<HashTable[i]->chain<<endl;
    }
};



};


 int main(){
     int ch;
Dictionary hmap;
do{
 
cout<<"1 Insert Element "<<endl;
cout<<"2 Search Element "<<endl;
cout<<"4 Delete Element "<<endl;
cout<<"4 Display Element "<<endl;
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
hmap.DeleteElement();
break;

case 4:
hmap.DisplayTable();
break;

default:
cout<<"Enter Valid Option"<<endl;
break;

}
}while(ch!=0);
 }


