#include<iostream>
using namespace std;

struct stack{
  int maxsize;
  int top;
  int *p;
};
typedef struct stack st;


void createStack(st *s,int sz){
  s->maxsize=sz;
  s->top=-1;
  s->p=new int[s->maxsize];
}

bool isFull(st s){
  if(s.top==s.maxsize-1)
    return true;
  return false;
}

bool isEmpty(st s){
  if(s.top==-1)
    return true;
  return false;
}

void push(st *s,int data){
  s->p[++(s->top)]=data;
  cout<<data<<" has been inserted at "<<s->top <<endl;
}

int pop(st *s){
  return (s->p[s->top--]);
}

void display(st s){
  for(int i=0;i<=s.top;i++){
    cout<<s.p[i]<<"\t";
  }
  cout<<endl;
}

int main(){
  int choice,size;
  st s;
  cout<<"Enter the size of the stack:"<<endl;
  cin>>size;
  createStack(&s,size);
  do
  {
    cout<<"1.Insert.\n2.Pop.\n3.Traverse.\n4.Exit"<<endl;
    cout<<"Enter the operation you want to perform."<<endl;
    cin>>choice;
    switch(choice){
      case 1:
        int item;
        if(isFull(s))
          cout<<"Stack overflow!!"<<endl;
        else{
          cout<<"Enter the item you want to insert on the stack."<<endl;
          cin>>item;
          push(&s,item);
        }
        break;
      case 2:
        int res;
        if(isEmpty(s))
          cout<<"Stack underflow!!"<<endl;
        else{
          res=pop(&s);
          cout<<"The popped item is: "<<res<<" ."<<endl;
        }
        break;
      case 3:
        if(isEmpty(s))
          cout<<"Stack is empty!"<<endl;
        else{
          cout<<"The item on the stack are :"<<endl;
          display(s);
        }
        break;
      case 4:
        exit(0);
        break;
      default:
        cout<<"Invalid choice!!"<<endl;
    }
  } while (true);
  
  return 0;
}