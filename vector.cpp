#include<iostream>
using namespace std;
class Vector
{
	private:
		int *arr=nullptr;
		int size=0;
		int capacity=0;
	public:
		Vector(int size) :
			size(size) 
  {
		capacity=size+10;
		if (size < 0)
			size = 1;
		arr = new int[size] { };
	 }
	void expand_capacity()
	{
		capacity*=2;
		int *arr2=new int[capacity];
		for(int i=0;i<size;i++)
		{
			arr2[i]=arr[i];
		}
		swap (arr,arr2);
		delete [] arr2;
	}
		void push_back(int a)
		{
			if(size==capacity)
			expand_capacity();
			arr[size++]=a;
		}
	void insert(int a,int i1)
	{
	 size+=1;
		arr[size]=0;
		for(int i=size;i>i1;i--)
		{
			arr[i]=arr[i-1];
		}
		arr[i1]=a;
	}
 void set(int a,int b)
		{
			arr[a]=b;
		}
	void print() 
 {
		for (int i = 0; i < size; ++i)
			cout << arr[i] << " ";
		cout << "\n";
 }
 void rotate_right()
 {
  int a=arr[size-1];
  for(int i=size-1;i>0;i--)
  {
   arr[i]=arr[i-1];
  }
  arr[0]=a;
 }
 void left_right()
 {
  int a=arr[0];
  for(int i=0;i<size;i++)
  {
   arr[i]=arr[i+1];
  }
  arr[size-1]=a;
 }
 void pop(int a)
 {
  size--;
  for (int i=a;i<size;i++)
  {
   arr[i]=arr[i+1];
  }
 }
 void rotate_righttimes(int a)
 {
  int i=0;
  while(i<a)
  {
   rotate_right();
   i++;
  }
 }
 void find(int a)
 {
  int x;
  for (int i=0;i<size;i++)
  {
   if(arr[i]==a)
   {
    cout<<"found";
    arr[i]=arr[i-1];
    arr[i-1]=a;
   }
  }
 }
};
int main()
{
	Vector v(5);
	for(int i=0;i<5;i++)
			{
			v.set(i,i);
			}          
	  
   v.print();
}