//Write a program to implement iterative as well as recursive versions of- Merge sort


#include<iostream>
using namespace std;

void merge(int A[],int low,int mid,int high){
	int i,j,k;
	i=low;
	j=mid+1;
	k=low;
	
	int B[100];
	
	while(i<=mid && j<=high){
		if(A[i]<A[j]){
			B[k++]=A[i++];
		}
		else{
			B[k++]=A[j++];
		}
	}
	
	//remaining elements
	for(;i<=mid;i++){
		B[k++]=A[i];
	}
	for(;j<=high;j++){
		B[k++]=A[j];
	}
	
	//copy back
	for(i=low;i<=high;i++){
		A[i]=B[i];
	}
}

//iterative
void iMergeSort(int A[],int n)
{
	int pass;
	int low,mid,high;
	for(pass=2;pass<=n;pass=pass*2){
		for(int i=0;i+pass-1<n;i=i+pass){
			low=i;
			high=i+pass-1;
			mid=(low+high)/2;
			merge(A,low,mid,high);
		}
	}
	if(pass/2<n){
		merge(A,0,pass/2,n-1);
	}
}

//recursive-- easy
void rMergeSort(int A[],int low,int high){
	if(low<high){
		int mid=(low+high)/2;
		rMergeSort(A,low,mid);
		rMergeSort(A,mid+1,high);
		merge(A,low,mid,high);
	}
}


int main()
{
	int A[]={8,3,7,4,9,2,6,5};
	int n=8;
	
	for(int i=0;i<n;i++){
		cout<<A[i]<<" ";
	}
//	iMergeSort(A,n);
	rMergeSort(A,0,n-1);
	
	cout<<"after merging \n";
	for(int i=0;i<n;i++){
		cout<<A[i]<<" ";
	}
	
	return 0;
}

