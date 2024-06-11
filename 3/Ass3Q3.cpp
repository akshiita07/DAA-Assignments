/*
3. 0/1 Knapsack Problem

*/

#include<iostream>
#include<vector> 
using namespace std;

int max(int a,int b)
{
	if(a>b) return a; else
	return b;
}

int knapsack(int wt[],int profit[],int n,int W)
{
	vector<vector<int> > ks (n+1,vector<int>(W+1));
	for(int i=0;i<=n;i++)
	{
		for(int w=0;w<=W;w++)
		{
			if(i==0||w==0)
			{
				//if either the row or the column is 0,i.e,the first row and column of the matrix,then we initialise it to0
				ks[i][w]=0;
			}
			else if(wt[i-1]<=w)
			{
				//we can insert
				ks[i][w]=max(profit[i-1]+ks[i-1][w-wt[i-1]],ks[i-1][w]);
			}
			else
			{ 
				ks[i][w]=ks[i-1][w];
			}
		}
	}
	//start checking from last val return
	ks[n][W];
}

int main()
{
	int profit[]={60,100,120}; 
	int wt[]={10,20,30}; 
	int size=sizeof(profit)/sizeof(profit[0]);
	int W=50;
	cout<<knapsack(wt,profit,size,W);
	return 0;
}
//time complexity=O(n*w) OUTPUT:


//GIVES WORNG INCLUDED OP CHECK!!!!!!!!!!!!!!!!!!!

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	//array of profits
//	int p[5]={0,2,4,7,10};
//	//0 index just added
//	
//	//array of weights of objects
//	int wt[5]={0,1,3,5,7};
//	
//	//knapsack capacity M
//	int M=8;
//	
//	//no of objects
//	int n=4;
//	
//	//2d array table where row-objects(n+1) and clm-capacity(M+1)
//	int v[5][9];
//	
//	//i row
//	for(int i=0;i<=n;i++){
//		//w clm
//		for(int w=0;w<=M;w++){
//			//for all 0 indices- profit is 0
//			if(i==0 || w==0){
//				v[i][w]=0;
//			}
//			//if weight of object is less than capacity
//			else if(wt[i]<=w){
//				v[i][w]=max(v[i-1][w],v[i-1][w-wt[i]]+p[i]);
//			}
//			else{
//				v[i][w]=v[i-1][w];
//				//take upper value
//			}
//		}
//	}
//	cout<<"Total profit= "<<v[n][M]<<endl;
//	
//	//to know which obj is included or not-
//	int i=n;
//	int j=M;
//	while(i>0 && j>0){
//		//if that value is present in above row also then dont include it
//		if(v[i][j]==v[i-1][j]){
//			cout<<i<<"=0 ie not included  \n";
//			i--;
//		}
//		else{
//			cout<<i<<"=1 ie included \n";
//			i--;
//			j=j-wt[i];	//check weight after subtracting
//			p[i]=v[n][M]-p[i];
//		}
//	}
//
////op- 12 and included- 1001
//	return 0;
//}

