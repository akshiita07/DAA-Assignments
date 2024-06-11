/*
5. Coin Exchange Problem
*/

#include<iostream>
#include<algorithm>
using namespace std;

int min(int a,int b){
	return a<b? a:b;
}

void no_of_coins(int coins[],int w,int n){
	int i;		//coins array
	int j;		//amount into subproblems
	
	int a[n+1][w+1];
	
	for(i=0;i<=n;i++){
		for(j=0;j<=w;j++){
			a[i][j]=INT_MAX;		//initialise array to 0
		}
	}
	
	for(i=0;i<=n;i++){
		a[i][0]=0;		//for 0 amount we require no coins so op=0
	}
	
	for(j=1;j<=w;j++){
		a[0][j]=INT_MAX;		//if no coins available then no amount can be formed
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=w;j++){
			//for case1 when coin>w
			if(coins[i-1]>j){
				//copy value from above row
				a[i][j]=a[i-1][j];
			}
			else{
				a[i][j]=min(a[i-1][j],1+a[i][j-coins[i-1]]);
			}
		}
	}
	
	cout<<endl<<"Printing array "<<endl;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=w;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	} 
	
	cout<<endl<<"The minimum no of coins reqd to make sum of "<<w<<" is: "<<a[n][w]<<endl; 
	
	//to find denomination::
	cout<<"The denomination of coins reqd to make sum "<<w<<" is: "<<endl;
	
	i=n;
	j=w;
	while(i>0 && j>0){
		if(a[i][j]!=a[i-1][j]){
			cout<<"included coin no: "<<i<<" with denomination: "<<coins[i-1]<<endl;
			j=j-coins[i-1];	
		}
		else{
			i--;
		}
	}
}

int main()
{
	int n;
	cout<<"Enter total no of coins u have: \n";
	cin>>n;
	
//	int n=4;
	
	int coins[n];
	for(int i=0;i<n;i++){
		cout<<"Enter the coin no "<<i<<" : ";
		cin>>coins[i];
	}

//	int coins[]={1,5,6,9};
	
	
	int w;
	cout<<"Enter total amount u want to make: \n";
	cin>>w;

//	int w=10;
	
	no_of_coins(coins,w,n);
	
	
	
	return 0;
}

