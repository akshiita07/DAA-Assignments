/*
2. Matrix Chain Multiplication 
*/

#include<iostream>
using namespace std;



int main()
{
	//no of matrices+1
	int n=5;
	
	//array to store dimensions of matrices
	int d[]={5,4,6,2,7};
	
	//take 2d arrays to store result
	int c[5][5]={0};
	int k[5][5]={0};
	
	//take diff of j-1
	for(int diff=1;diff<n-1;diff++){
		//row
		for(int i=1; i<n-diff;i++){
			//clm
			int j=i+diff;
			int min=32767;
			int cost;
			
			//find minm
			for(int K=i;K<j;K++){
				cost=c[i][K]+c[K+1][j]+d[i-1]*d[K]*d[j];
				if(cost<min){
					min=cost;
					k[i][j]=K;
				}
			}
			c[i][j]=min;
		}
	}

	cout<<"output- "<<c[1][n-1];

	return 0;
}

//op- 158
