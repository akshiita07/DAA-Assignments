//Write a program to implement iterative as well as recursive versions of- Binary search
#include<iostream>
using namespace std;

//iterative
void binSearch(int A[],int n,int key){
	int low=0;
	int high=n-1;
	int mid;
	
	while(low<=high){
		mid=(low+high)/2;
		if(key==A[mid]){
			cout<<"Element "<<key<<" found in array \n";
			return;
		}
		else if(key<A[mid]){
			//left
			high=mid-1;
		}
		else{
			//right
			low=mid+1;
		}
	}
	
	cout<<"Element "<<key<<" NOT found in array \n";
}

//recursive
int rbinSearch(int A[],int n,int low,int high,int key){
	int mid;
	
	if(low<=high){
		mid=(low+high)/2;
		if(key==A[mid]){
			return 1;
			
		}
		else if(key<A[mid]){
			//left
			return rbinSearch(A,n,low,mid-1,key);
		}
		else{
			return rbinSearch(A,n,mid+1,high,key);			
		}
	}
}

int main()
{
	int A[]={2,4,6,8,10};
	int n=5;
	
	int key;
	cout<<"Enter key element to find: \n";
	cin>>key;
	
//	binSearch(A,n,key);
	
	
	int res=rbinSearch(A,n,0,n-1,key);
	if(res==1){
		cout<<"Element "<<key<<" found in array \n";
	}
	else{
		cout<<"Element "<<key<<" NOT found in array \n";
	}

	return 0;
}

