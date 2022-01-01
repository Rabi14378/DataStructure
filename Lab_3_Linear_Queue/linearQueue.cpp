#include<iostream>
using namespace std;

struct queue{
  int maxsize;
  int rear;
  int front;
  int *p;
};
typedef struct queue q;


void createQueue(q *s,int sz){
  s->maxsize=sz;
  s->rear=-1;
  s->front=0;
  s->p=new int[s->maxsize];
}

bool isFull(q s){
  return (s.rear==s.maxsize-1);
}

bool isEmpty(q s){
  return (s.rear < s.front);
}

void enqueue(q *s,int data){
  s->p[++(s->rear)]=data;
  cout<<data<<" has been inserted at "<<s->rear <<endl;
}

int dequeue(q *s){
  return (s->p[s->front++]);
}

void display(q s){
  for(int i=s.front;i<=s.rear;i++){
    cout<<s.p[i]<<"\t";
  }
  cout<<endl;
}

int main(){
  int choice,size;
  q s;
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
  } while (true);
  
  return 0;
}