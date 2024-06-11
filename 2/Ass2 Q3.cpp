/*
3. Fractional knapsack 
*/

#include<iostream>
#include <algorithm>		//to use sort fnc
using namespace std;

struct item{
    int profit;
    int weight;
};


int compareItems(item a,item b){
	if(a.profit/a.weight>b.profit/b.weight){
		return 1;
	}
	else{
		return 0;
	}
}

double knapsack(item objects[],int n,int M) {
    //to sort items in descending order of profit/weight (per-unit profit)
    sort(objects,objects+n,compareItems);
    
    double totalval = 0.0;
    
    //traverse thru all objects
    for(int i=0; i<n; i++) {
    	//curr item weight> knapsack remain capacity then take fractional
        if(objects[i].weight>M){
        	//take fraction
            totalval=totalval+M*(objects[i].profit/objects[i].weight);		//maxm profit
            M=M-objects[i].weight;
            break;
        }
		else{
            //take full item
            totalval=totalval+objects[i].profit;
            M=M-objects[i].weight;
        }
    }
    return totalval;
}

int main()
{
	//no of items
	int n=4;
	//capacity of knapsack
    int M=60;
    
    //add profit,weight
    item objects[n]={{280,40},{100,10},{120,20},{120,24}};
    
    cout<<"Maximum profit that can be obtained: "<<knapsack(objects,n,M)<<endl;
	
	return 0;
}


