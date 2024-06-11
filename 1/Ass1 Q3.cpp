//Write a program to implement iterative as well as recursive versions of- Quick sort

#include<iostream>
using namespace std;

void swap(int *x,int *y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

int partition(int A[], int l, int h){
	int pivot=A[l];			//first element must be pivot element
	
	int i=l;	//low
	int j=h;	//high
	
	do{
		do{
			i++;		//i stops when element>pivot
		}while(A[i]<=pivot);
		
		do{
			j--;		//j stops when element<pivot
		}while(A[j]>pivot);
		
		if(i<j){		
			swap(&A[i],&A[j]);
		}
		
	}while(i<j);		//agar i>j then stop
	
	//if i>j then swap pivot with j
	swap(&A[l],&A[j]);
	
	return j;		//j gives partioning position
}

void quickSort(int A[], int l, int h){
	if(l<h){
		int j;
		j=partition(A,l,h);
		quickSort(A,l,j);
		quickSort(A,j+1,h);
	}
	
}

int main()
{
	int n=5;
	int A[]={8,5,7,3,2};
	quickSort(A,0,n);

	for(int i=0; i<n; i++){
		cout<<A[i]<<"	";
	}


	return 0;
}

