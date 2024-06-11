/*
3.Graph Coloring
*/

#include<iostream>
using namespace std;

//vertex k
//color c
//no adjacent vertices have same color

//n- no of vertices
const int n=4;

//m-> no of colors
const int m=3;
//adjacency matrix- 
//int G[n][n];

//array for storing color of each vertex
int x[n];

//is it safe to color vertex k with color c
bool isSafe(int k,int c,int G[][n],int x[]){
	for(int i=0;i<n;i++){
		if(G[k][i]==1 && c==x[i]){
			return false;
		}
	}
	return true;
}

void graphcolor(int k,int G[][n],int x[]){
	//thru all colors loop
	for(int c=1;c<=m;c++){
		if(isSafe(k,c,G,x)){
			x[k]=c;
			
			if(k+1<n){
				graphcolor(k+1,G,x);
			}
			else{
				cout<<"vertex colors are: \n";
				for(int i=0;i<n;i++){
					cout<<x[i]<<" ";
				}
				cout<<endl;
			}
			
			x[k]=0;		//for backtracking n try different path
		}
	}
}

int main()
{
	//n-global-no of vertices
	
	//graph G adjacency matrix
	int G[n][n]={
        {0,1,1,1},
        {1,0,1,0},
        {1,1,0,1},
        {1,0,1,0}
    };

    // Initialize all vertices as uncolored
    for(int i=0; i<n; i++) {
        x[i]=0;
    }

    // Start coloring from vertex 0
    graphcolor(0,G,x);


	return 0;
}

