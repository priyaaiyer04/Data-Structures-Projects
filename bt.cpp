#include<iostream>
using namespace std;
class Node
{
 public:
  char data;
  Node *next;
  Node *left,*right;
  Node(char d)
  {
   this->data=d;
   this->next=nullptr;
   this->left=nullptr;
   this->right=nullptr;
  }};
  class BT
  {public:
 BT()
 {
 }
  void printpostorder(Node *current)
 {
  if(!current)
  return ;
  else
  {
   printpostorder(current->left);
   printpostorder(current->right);
   cout<<current->data<<"\t";
  }
 }
 void inorder(Node *current)
 {
  if(!current)
  return ;
  else
  {
   printpostorder(current->left);
   cout<<current->data<<"\t";
   printpostorder(current->right);
  }
 }
};
int main()
{BT t;
 Node *a=new Node('2');
  Node *b=new Node('3');
   Node *c=new Node('+');
   Node *d=new Node('*');
   Node *e=new Node('7');
   
   c->left=a;
   c->right=b;
   d->left=c;
   d->right=e;
   t.printpostorder(d);
}
