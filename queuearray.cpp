#include<iostream>
using namespace std;
class queue
{
 public:
   int front,rear,size,s,*arr;
 queue(int s)
 {
   arr=new int [s];
   front=0;
   rear=0;
   size=0;
 }
 void stream(int k)
 {
  int i=0,c=0;int sum=0;
  while(c<k)
  {
   while(i<=c)
   {
    sum+=arr[i];
    i++;
   }
  cout<<sum<<endl;
  sum=0;
  i=0;
  c+=1;
  }
  i=1;
  sum=0;
  int bound=size-k;
  while(i<=bound)
  {
   int c=i+k;
   int j=i;
   while(j<c)
   {
    sum+=arr[j];
    j++;
   }
   cout<<sum<<endl;
   sum=0;
   i++;
  }
 }
 void enqueue_rear(int a)
 {
  arr[rear]=a;
  size++;
  rear++;
 }
  void enqueue_front(int a)
 {
  size++;
  front--;
  arr[front]=a;
 }
  int dequeue()
 {
  int a=arr[front];
  front++;
  size--;
  return a;
 }
 void print()
 {
  for(int i=front;i<rear;i++)
  cout<<arr[i]<<"\t";
 }
int moveind(int pos)
 {
  return pos%s;
 }
 bool empty()
 {
  if (rear==front==0)
  return 1;
  else
  return 0;
 }
 void dequeue_rear()
 {
  size--;
  rear--;
 }
};
class stack
{public:
queue q;int size=0;
stack(int s):q(s)
{
 
}
void push(int a)
 {
  size++;
  q.enqueue_front(a);
 }
 void print()
 {
 q.print();
 }
int  pop()
 {
 int c= q.dequeue();
 return c;
 }
};
class queuestack
{
 public:
  int size=0;
  stack s1,s2;
  queuestack(int s):s1(s),s2(s)
{
 
}
void enq(int a)
{
 size++;
 s1.push(a);
}
void move()
{
 for(int i=size-1;i>=0;i--)
 {
  int d=s1.pop();
  s2.push(d);
 }
}
int deq()
{
if(s2.size==0)
{
 move();
}
size--;
int d=s2.pop();
size--;
}
void print()
{ 
  if(s2.size==0)
{
 move();
}
s2.print();
}
};
class prqueue
{
 public:
 int front,rear,size,s,*arr;
 queue q1,q2,q3;
 prqueue(int s):q1(s),q2(s),q3(s)
 {
 }
 void enqueue_rear(int a,int pr)
 {
  if (pr==1)
  {
   q1.enqueue_rear(a);
  }
 if (pr==2)
 {
   q2.enqueue_rear(a);
 }
 if (pr==3)
 {
   q3.enqueue_rear(a);
 }
 }
 bool empty(queue q)
 {
  return q.empty();
 }
  int dequeue()
 {
 if(q3.size!=0)
 {
 q3.dequeue();
 return 0;
 }
 if(q3.size==0 and q2.size!=0)
 {              
 q2.dequeue();
 return 0;
 }
 if(q2.size==0)
 {
 q1.dequeue();
 return 0;
 }
 }
 void print()
 {
  q3.print();
  q2.print();
  q1.print();
 }

};
class circqueue
{public:
 int front,rear,s,*arr;
 circqueue(int s)
 {
  arr=new int [s];
  front=0;
  rear=0;
 }
int next(int pos)
 {
  if(pos==s)
  return 0;
  else return pos+1;
 }
 void enqueue_rear(int a)
 {
  arr[rear]=a;
  rear=next(rear);
 }
 int dequeue()
 {
  int a=arr[front];
  front=next(front);
  return a;
 }
 void print()
 {
  for(int i=front;i<rear;i++)
  cout<<arr[i]<<"\t";
 }
 bool empty()
 {
  return front==rear;
 }
};
int main()
{
 circqueue s(4);
 s.enqueue_rear(12);
 s.enqueue_rear(21);
 s.enqueue_rear(253);
 s.dequeue();
 s.print();
}
