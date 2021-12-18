#include<iostream>
#include <cstring>
using namespace std;

struct stack{
  int maxsize;
  int top;
  char *p;
};
typedef struct stack st;

struct array{
  int length;
  int maxsize;
  char *p;
};
typedef struct array arr;


void createStack(st *s,int sz){
  s->maxsize=sz;
  s->top=-1;
  s->p=new char[s->maxsize];
}

void createArray(arr *a,int sz){
  a->length=0;
  a->maxsize=sz;
  a->p=new char[a->maxsize];
}


void push(st *s,char data){
  s->p[++(s->top)]=data;
}

void insert(arr *a,char item){
  a->p[a->length]=item;
  a->length++;
}


char pop(st *s){
  return (s->p[s->top--]);
}

void display(arr a){
  for(int i=0;i<a.length;i++){
    cout<<a.p[i];
  }
  cout<<endl;
  
}

bool isOperand(char c){
  if(c>=97&&c<=122||c>=65&&c<=96)
    return true;
  return false;
}

int pre(char c){
  if(c==')')
    return 1;
  else if(c=='+'||c=='-')
    return 2;
  else if(c=='*'||c=='/')
    return 3;
  else if(c=='$')
    return 4;
  else
    return 0;
}

int main(){
  int len;
  string exp;
  st s;
  arr a;
  cout<<"Enter the expression:"<<endl;
  cin>>exp;
  exp=exp.append(")"); //Adding ) at the end of array.
  len=exp.length();
  createStack(&s,len);
  push(&s,'(');        //Adding ( at the start of the stack.
  createArray(&a,len);
  
  for(int i=0;i<len;i++){
    if(exp[i]=='(')
      push(&s,exp[i]);

    else if(exp[i]==')'){
      while(s.p[s.top]!='(')
        insert(&a,pop(&s));
      pop(&s);
    }

    else if(isOperand(exp[i])){
      insert(&a,exp[i]);
    }

    else if(pre(s.p[s.top])>=pre(exp[i])){
      while(pre(s.p[s.top])>=pre(exp[i]))
        insert(&a,pop(&s));
      push(&s,exp[i]);
    }

    else{
      push(&s,exp[i]);
    }

  }

  exp.pop_back();
  cout<<"The postfix expression of "<<exp<<" is :\n\t\t";
  display(a);
  
  return 0;
}