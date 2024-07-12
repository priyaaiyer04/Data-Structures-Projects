#include<iostream>
#include <cassert>
#include <math.h>
#include<vector>
using namespace std;
class BT
{
 public:
  int data{};
  BT *left{},*right{};
  BT(int data) :
			data(data) {
	}
  void printinorder()
  {
   if(left)
   left->printinorder();
   cout<<data<<"\t";
   if(right)
   right->printinorder();
  }
  void add(vector<int> arr1,vector <char> arr2)
  {BT*current=this;
   for(int i=0;i<(int)arr1.size();i++)
   {
    
    if(arr2[i]=='L')
    {if(!current->left)
    current->left=new BT(arr1[i]);
    else
   current->left->data == arr1[i];
     current=current->left;
    }
   else
    {if(!current->right)
    current->right=new BT(arr1[i]);
    else
    	current->right->data == arr1[i];
     current=current->right;
    }
   }
  }
  int tmax()
  {
   int x=data;
   if(left)
   x=max(x,left->tmax());
   if(right)
   x=max(x,right->tmax());
   
   return x;
  }
  int  height()
  {
   int h=0,h1=0;
   if(left)
   {
    h=1+left->height();
   }
   if (right)
  {
   h=max(h,1+right->height());
  }
  
   return h;
  }
  int totalnodes()
  {int h=1;
   if(left)
   {
    h+=left->totalnodes();
   }
   if (right)
  { h+=right->totalnodes();
 }
  return h;
 }
 int totalleafnodes()
 {int h=!left and !right;
 if (left)
 h+=left->totalleafnodes();
 if (right)
 h+=right->totalleafnodes();
 return h;
}
bool search(int a)
{
 bool h=a==data;
 if(!h and left)
 h+=left->search(a);
 if(!h and right)
 h+=right->search(a);
 return h;
}
void isperfect()
{
 int h=height();
 int n=totalnodes();
 if(pow(h,h-1)==n)
 cout<<"perfect";
 else
 cout<<"not perfect";
}
bool isperfect2(int h=-1)
{if(h==-1)
h=height();
if(!left && !right)
return h==0;
if(!left and right||!right and left)
return false;
return left->isperfect2(h-1) && right->isperfect2(h-1);
}
};
int main()
{BT tree(1);
	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	tree.add( { 3, 6, 10 }, { 'R', 'R', 'L' });
cout<<tree.isperfect2();
	// 7 4 8 2 5 9 1 3 10 6
return 0;
 
}