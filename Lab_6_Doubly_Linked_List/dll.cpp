#include<iostream>
using namespace std;

struct node{
  int data;
  struct node *next,*prev;
};
typedef struct node nd;
nd *head=nullptr;

nd * getNewNode(){
  nd *newNode=new nd;
  return newNode;
}

int totalNode(){
  int count=0;
  if(head==nullptr)
    return count;
  else{
    nd *temp=head;
    while(temp!=nullptr){
      count++;
      temp=temp->next;
    }
    return count;
  }
}

void insert_B(int data){
  nd *newNode=getNewNode();
  newNode->data=data;
  if(head==nullptr){
    head=newNode;
    newNode->next=nullptr;
    newNode->prev=nullptr;
    return;
  }
  newNode->next=head;
  head->prev=newNode;
  newNode->prev=nullptr;
  head=newNode;
}

void insert_E(int data){
  if(head==nullptr){
  insert_B(data);
  return;
  }
  nd *newNode=getNewNode();
  newNode->data=data;
  nd *temp=head;
  while(temp->next!=nullptr)
    temp=temp->next;
  newNode->next=nullptr;
  newNode->prev=temp;
  temp->next=newNode;
}

void insert_P(int data){
  int pos,total_node;
  cout<<"Enter the position you want to insert"<<endl;
  cin>>pos;
  total_node=totalNode();
  if(pos>total_node+1){
    cout<<"invalid insertion"<<endl;
    return;
  }
  if(pos==1){
    insert_B(data);
  }
  else if(pos==total_node+1){
    insert_E(data);
  }
  else{
    nd *newNode=getNewNode();
    newNode->data=data;
    nd *temp=head;
    for(int i=1;i<pos-1;i++){
      temp=temp->next;
    }
    newNode->next=temp->next;
    newNode->prev=temp;
    temp->next->prev=newNode;
    temp->next=newNode;
  }
}

void delete_B(){
  nd *temp=head;
  if(head==nullptr)
    cout<<"List is empty!"<<endl;
  else if(head->next==nullptr){
    cout<<"The deleted item is "<<head->data<<endl;
    head=nullptr;
    delete temp;
  }
  else{
    cout<<"The deleted item is "<<head->data<<endl;
    head=head->next;
    head->prev=nullptr;
    delete temp;
  }
}
void delete_E(){
  if(head==nullptr)
    delete_B();
  else if(head->next==nullptr){
    delete_B();
  }
  else{
    nd *temp=head;
    while (temp->next->next!=nullptr)
    {
      temp=temp->next;
    }
    cout<<"The deleted item is "<<temp->next->data<<endl;
    delete temp->next;
    temp->next=nullptr;
  }
}

void delete_P(){
  int pos;
  cout<<"Enter the position you want to delete"<<endl;
  cin>>pos;
  if(pos>totalNode()){
    cout<<"invalid deletion"<<endl;
    return;
  }
  if(pos==1){
    delete_B();
    return;
  }
  if(pos==totalNode()){
    delete_E();
    return;
  }
  nd *temp=head;
  for(int i=1;i<pos-1;i++){
    temp=temp->next;
  }
  nd * hold;
  hold=temp->next;
  temp->next=temp->next->next;
  hold->next->prev=temp;
  cout<<"Deleted item is :"<<hold->data<<endl;
  delete hold;
}

void display(){
  if(head==nullptr)
    cout<<"The list is empty"<<endl;
  else{
    nd *temp=head;
    cout<<"The items are:"<<endl;
    while(temp!=nullptr){
      cout<<temp->data<<"\t";
      temp=temp->next;
    }
    cout<<endl;
  }
}

int main(){
  int choice;
  do{
    cout<<"1.Insert at beginning\n2.Insert at end\n3.Insert at specific position\n4.delete from beginning\n5.delete from end\n6.delete from specific position\n7.display\n8.Exit"<<endl;
    cin>>choice;
    switch(choice){
      int data;
      case 1:
        cout<<"Enter data"<<endl;
        cin>>data;
        insert_B(data);
        break;
      case 2:
        cout<<"Enter data"<<endl;
        cin>>data;
        insert_E(data);
        break;
      case 3:
        cout<<"Enter data"<<endl;
        cin>>data;
        insert_P(data);
        break;
      case 4:
        delete_B();
        break;
      case 5:
        delete_E();
        break;
      case 6:
        delete_P();
        break;
      case 7:
        display();
        break;
      case 8:
        exit(0);
        break;
      default:
        cout<<"Invalid choice"<<endl;
    }
  }while(true);

}