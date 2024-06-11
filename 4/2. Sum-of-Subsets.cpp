/*
2. Sum-of-Subsets
FIND A SUBSET OF WEIGHTS SUCH THAT THEIR SUM EQUALS SOME M
*/

#include<iostream>
using namespace std;

//s:current sum of weights (w*x)
//k:index of object under consideration
//r: remaining weight(not yet included objects - w)


//w: array to store weights of elements


//x:array whetehr element is included in subset


void sumofsubsets(int w[],int x[],int s,int k,int r,int M){
	
	//if sum of current elements in subset=M then print it
	if(s==M){
		for(int i=0;i<=k;i++){
			
			//include first element in subset
			if(x[i]==1){
				//this will print if element is included:1 or not:0
				cout<<w[i]<<" ";	
			}
		}
		cout<<"are elements to be included in subset. \n";
		cout<<endl;
	}
	
	//check if left child can be included n does not exceed M:
	else if(s+w[k]<=M && s+r>=M){
		x[k]=1;
		//sumofsubsets(int w[],int x[],int s,int k,int r,int M)
		sumofsubsets(w,x,s+w[k],k+1,r-w[k],M);
	}
		
	//exclude this element from subset list-
	x[k]=0;
	//check if RIGHT child can be included:
	if(s+r-w[k]>=M && s+w[k+1]<=M){
		//sumofsubsets(int w[],int x[],int s,int k,int r,int M)
		sumofsubsets(w,x,s,k+1,r-w[k],M);
	}
}

int main()
{
	//M- target sum to be reached
	int n;
	int M;
	cout<<"Enter no of elements: \n";
	cin>>n;
	
	cout<<"Enter target sum to be reached: \n";
	cin>>M;
	
	int sum=0;
	int w[n];
	int x[n];
	
	//initially intitialise x array with zeroes
	for(int i=0;i<n;i++){
		x[i]=0; //ie all elements are NOT currently included
	}
	
	for(int i=0;i<n;i++){
		cout<<"Enter weight of element "<<i+1<<" = ";
		cin>>w[i];	
		sum+=w[i];
	}

	sumofsubsets(w,x,0,0,sum,M);

	return 0;
}

