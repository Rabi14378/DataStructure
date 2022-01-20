#include<iostream>
#include<conio.h>
using namespace std;

struct queue{
  int maxsize;
  int rear;
  int front;
  int *p;
};
typedef struct queue cq;


void createQueue(cq *s,int sz){
  s->maxsize=sz;
  s->rear=sz-1;
  s->front=sz-1;
  s->p=new int[s->maxsize];
}

bool isFull(cq s){
  return (s.front==(s.rear+1)%(s.maxsize));
}

bool isEmpty(cq s){
  return (s.rear == s.front);
}

void enqueue(cq *s,int data){
  s->rear=(s->rear+1)%(s->maxsize);
  s->p[s->rear]=data;
  cout<<data<<" has been inserted at "<<s->rear <<" index"<<endl;
}

int dequeue(cq *s){
  s->front=(s->front+1)%(s->maxsize);
  return (s->p[s->front]);
}

void display(cq s){
  while(s.front!=s.rear){
    s.front=(s.front+1)%(s.maxsize);
    cout<<s.p[s.front]<<"\t";
  }
  cout<<endl;
}

int main(){
  int choice,size;
  cq s;
  cout<<"Enter the size of the queue:"<<endl;
  cin>>size;
  createQueue(&s,size);
  do
  {
    cout<<"1.Enqueue.\n2.Dequeue.\n3.Traverse.\n4.Exit"<<endl;
    cout<<"Enter the operation you want to perform."<<endl;
    cin>>choice;
    switch(choice){
      case 1:
        int item;
        if(isFull(s))
          cout<<"Queue overflow!!"<<endl;
        else{
          cout<<"Enter the item you want to insert on the queue."<<endl;
          cin>>item;
          enqueue(&s,item);
        }
        break;
      case 2:
        int res;
        if(isEmpty(s))
          cout<<"Queue underflow!!"<<endl;
        else{
          res=dequeue(&s);
          cout<<"The popped item is: "<<res<<" ."<<endl;
        }
        break;
      case 3:
        if(isEmpty(s))
          cout<<"Queue is empty!"<<endl;
        else{
          cout<<"The item on the queue are :"<<endl;
          display(s);
        }
        break;
      case 4:
        exit(0);
        break;
      default:
        cout<<"Invalid choice!!"<<endl;
    }
    if(getch()) system("cls");
  } while (true);
  
  return 0;
}