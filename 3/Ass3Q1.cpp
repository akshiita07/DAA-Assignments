/*
1. Longest Common Subsequence 
*/

#include<iostream>
using namespace std;


int main()
{
	string A="stone";
	string B="longest";
	
	int m=A.length();
	int n=B.length();
	
	int lcs[m+1][n+1];		//as 0 indices also has to be included
	
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0 || j==0	){		//for index 0 fill all 0 values
				lcs[i][j]=0;
			}
			else if(A[i-1]==B[j-1]){
				lcs[i][j]=1+lcs[i-1][j-1];
				cout<<A[i]<<" ";
			}
			else{
				lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
			}
		}
	}
	
	cout<<endl<<"Length of longest common subsequennce is: "<<lcs[m][n]<<endl;
	
	

//op- 3 -- one

	return 0;
}

