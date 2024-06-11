/*
1. n queen problem:
*/

#include<iostream>
using namespace std;
//x- colm where queen is placed
//i->row
//j->colm

const int n=4; 		//ie 4 queens and 4x4 chessboard
//x[i] is a global array that stores column nos
int x[n];

//returns true/false:
bool place(int i,int j){
	for(int k=1;k<i;k++){
		
		//if not safe ie conflict occurs-> ie no same clm/diag
		if(x[k]==j || abs(x[k]-j)==abs(k-i)){
			return false;
		}
	}
	//safe to place queen
	return true;
}

void nqueen(int i,int n){
	
	//where n is dimension of board ie no of queens
	//i is row
	
	//first we pass i=1 ie first row 
	
	for(int j=1;j<=n;j++){
		
		if(place(i,j)){
			//if it is safe to place queen
			x[i]=j;
			
			if(i==n){
				//on reaching last row print all positions of queen on board
				//print x[1..n];
				for(int m=1;m<=n;m++){
					cout<<x[m]<<" ";
				}
				cout<<endl;
			}
			else{
				nqueen(i+1,n);		//recursion for next row
			}
		}
		
	}
}

int main()
{
	//n: dimension of chess board ie no of queens	
	nqueen(1,n);

	return 0;
}

