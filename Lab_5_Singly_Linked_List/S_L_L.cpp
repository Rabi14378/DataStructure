#include<iostream>
#include<conio.h>
using namespace std;

struct node{
  int data;
  struct node *next;
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
  newNode->next=head;
  head=newNode;
}

void insert_E(int data){
  nd *newNode=getNewNode();
  newNode->data=data;
  nd *temp=head;
  if(head==nullptr){
    head=newNode;
    newNode->next=nullptr;
  }
  else{
    while(temp->next!=nullptr)
      temp=temp->next;
    newNode->next=nullptr;
    temp->next=newNode;
  }
}

void insert_P(int data){
  nd *newNode=getNewNode();
  newNode->data=data;
  int pos;
  cout<<"Enter the position you want to insert"<<endl;
  cin>>pos;
  if(pos>totalNode()+1){
    cout<<"invalid insertion"<<endl;
    return;
  }
  nd *temp=head;
  for(int i=1;i<pos-1;i++){
    temp=temp->next;
  }
  newNode->next=temp->next;
  temp->next=newNode;
}

void delete_B(){
  if(head==nullptr)
    cout<<"List is empty!"<<endl;
  else{
    nd *temp=head;
    cout<<"The deleted item is "<<head->data<<endl;
    head=head->next;
    delete temp;
  }
}
void delete_E(){
  if(head==nullptr)
    cout<<"List is empty!"<<endl;
  else if(head->next==nullptr){
    cout<<"The deleted item is "<<head->data<<endl;
    delete head;
    head=nullptr;
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
  nd *temp=head;
  for(int i=1;i<pos-1;i++){
    temp=temp->next;
  }
  nd * hold;
  hold=temp->next;
  temp->next=temp->next->next;
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