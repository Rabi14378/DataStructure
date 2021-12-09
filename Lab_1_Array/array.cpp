#include<iostream>
using namespace std;

struct array{
  int length;
  int maxsize;
  int *p;
};
typedef struct array arr;

void DisplayMenu(){
  cout<<"1) inset into array.\n2) delete from array.\n3) traverse.\n4) merge two array\n5) update data of array.\n6) exit."<<endl;
} 

void createArray(arr *a,int sz){
  a->length=0;
  a->maxsize=sz;
  a->p=new int[a->maxsize];
}

bool isFull(arr *a){
  if(a->length==a->maxsize){
    return true;
  }
  return false;
}

bool isEmpty(arr *a){
  if(a->length==0)
    return true;
  return false;
}

void inputData(arr *a){
  int number;
  cout<<"How many data do you want to enter."<<endl;
  cin>>number;
  cout<<"Enter the initial data for the array."<<endl;
  for(int i=0;i<number;i++){
    cin>>a->p[i];
  }
  a->length=number;
}

void insert(arr *a,int index,int item){
  if(!isFull(a)){
    if(a->length<index){
      cout<<"The index "<<index-1<<" is empty.Please fill previous index to add to this index."<<endl;
      return;
    }
    for(int i=a->length;i>index;i--){
      a->p[i]=a->p[i-1];
    }
    a->p[index]=item;
    a->length++;
    cout<<"Item has been inserted into the array at index "<<index<<" ."<<endl;
  }
  else
    cout<<"Array is full. You cannot enter data."<<endl;
}

int deleteData(arr *a,int index1){
  if((!isEmpty(a))&&index1<a->length){
    // cout<<index1<<a->p[index1]<<endl;
    int temp=a->p[index1];
    for(int i=index1;i<a->length;i++){
      a->p[i]=a->p[i+1];
    }
    a->length--;
    return temp;
  }
  else
    return -1;
}

void merge(arr *a,arr *a1, arr *a2){
  int i,j;
  for(i=0;i<a->length;i++){
    a2->p[i]=a->p[i];
  }
  cout<<i<<endl;
  for ( j = 0; j < a1->length; j++)
  {
    a2->p[i++]=a1->p[j];
  }
  a2->length=a->length+a1->length;
}

void update(arr *a,int index,int item){
  if(a->length<=index){
      cout<<"The index "<<index<<" is empty. You can't update at this index."<<endl;
      return;
    }
  a->p[index]=item;
  cout<<"The item at index "<<index<<" has been updated to "<<item<<endl;
}

void display(arr a){
  cout<<"Data of array is:"<<endl;
  for(int i=0;i<a.length;i++){
    cout<<a.p[i]<<"\t";
  }
  cout<<endl;
  
}

int main(){
  arr a;
  int choice,yn;

  createArray(&a,10);
  system("cls");
  cout<<"Array has been created. Do you want to enter initial data?\nEnter 1 for yes and 0 for no!"<<endl;
  cin>>yn;

  if(yn)
    inputData(&a);
  
  while(true){
    DisplayMenu();

    cout<<"Enter your choice:"<<endl;
    cin>>choice;

    system("CLS");

    switch(choice){

      case 1:
        int index,item;
        cout<<"enter the index where you want to insert."<<endl;
        cin>>index;
        cout<<"enter the item you want to insert at "<<index<<" index."<<endl;
        cin>>item;
        insert(&a,index,item);
        break;

      case 2:
        int index1,res;
        cout<<"Enter the index of data you want to delete."<<endl;
        cin>>index1;
        res=deleteData(&a,index1);
        if(res==-1)
          cout<<"Could not delete data. Please check the index properly."<<endl;
        else
          cout<<"The deleted item is "<<res<<endl;
        break;

      case 3:
        display(a);
        break;
        
      case 4:
        arr a1,a2;
        createArray(&a1,10);
        createArray(&a2,20);
        cout<<"A new Array has been created. Please enter data."<<endl;
        inputData(&a1);
        merge(&a,&a1,&a2);
        display(a2);
        break;

      case 5:
        int index2,item1;
        cout<<"enter the index of which you want to update."<<endl;
        cin>>index2;
        cout<<"enter the new item."<<endl;
        cin>>item1;
        update(&a,index2,item1);
        break;

      case 6:
        exit(0);
    }

  }
  return 0;
} 