/*
2. Job sequencing with deadlines
*/

#include<iostream>
using namespace std;

int job_seq(int d[],int j[],int n){
	
	//initialise first elements of d,j array
	d[0]=j[0]=0;
	
	//include 1st job of maxm profit
	j[1]=1;
	
	//k represents no of jobs considered
	int k=1;
	
	//loop from second to last job
	for(int i=2;i<=n;i++){
		//search for position r to insert job i
		int r=k;
		
		while(d[j[r]]>d[i] && d[j[r]]!=r){
			r=r-1;
		}
		
		//check if job can be inserted
		if(d[j[r]]<=d[i] && d[i]>r){
			//make space for new job by shifting rest downwards
			for(int q=k;q>=r+1;q--){
				j[q+1]=j[q];
			}
			//insert
			j[r+1]=i;
			//increase count of k ie no of jbs considered
			k=k+1;
		}
	}
	return k;		//ie no of jobs considered
}

int main()
{
	int d[]={3,4,4,2,3,1,2};		//deadlines
	int p[]={35,30,25,20,15,12,5};		//profits in dec order sorted
	int n=7;		//no of jobs
	
	int j[n+1];		//array to store job sequence				 ie to store o/p
	
	int ans=job_seq(d,j,n);
	cout<<"job sequence: \n";
	for(int i=1;i<=ans;i++){
		cout<<j[i]<<" ";
	}


	return 0;
}

