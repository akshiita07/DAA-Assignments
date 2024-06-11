/*
1. Activity Selection problem
*/
#include<iostream>
using namespace std;

void activity_selector(int s[],int f[],int n){

	int k=0;
	cout<<"Activities selection order: \n "<<k<<" ";
	
	//traverse from second activity to nth one (index from 0 so start from 1)
	for(int m=1;m<n;m++){
		//check if start time of new job>=finish time of already added job
		if(s[m]>=f[k]){
			//add it to soln
			cout<<m<<" ";
			//set k to new inserted
			k=m;
		}
	}
	
}

int main()
{
	int s[]={0,1,3,4,5};
	int f[]={2,3,4,6,7};
	int n=sizeof(s)/sizeof(s[0]);		//store number of activities in n
	activity_selector(s,f,n);
	return 0;
}

