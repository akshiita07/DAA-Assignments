//Write a program to implement iterative as well as recursive versions of- Maximum sub-array sum 

#include<iostream>
using namespace std;

//find maximum of two integers 
int max(int a, int b) { 
	if(a>b){
		return a;	
	}
	else{
		return b;
	}
}

//find maximum of three integers 
int max(int a, int b, int c) { 
	return max(max(a, b), c); 
} 

//Find the maximum possible sum in arr[] such that arr[m] is part of it 
int maxCrossingSum(int arr[], int l, int m, int h){
	int sum=0; 
	int left_sum=INT_MIN; 
	for (int i=m; i>=l; i--) { 
		sum=sum+arr[i]; 
		if(sum>left_sum) 
			left_sum = sum; 
	} 
	int right_sum=INT_MIN; 
	for (int i=m; i<=h; i++) { 
		sum=sum+arr[i]; 
		if(sum>right_sum) 
			right_sum = sum; 
	} 

	// Return sum of elements on left and right of mid returning only left_sum + right_sum
	return max(left_sum+right_sum-arr[m], left_sum, right_sum); 
} 

// Returns sum of maximum sum subarray
int maxSubArraySum(int arr[], int l, int h) { 
	// Invalid Range: low is greater than high 
	if (l > h) 
		return INT_MIN; 
	// Base Case: Only one element 
	if (l == h) 
		return arr[l]; 

	// Find middle point 
	int m = (l + h) / 2; 

	/* Return maximum of following three possible cases 
			a) Maximum subarray sum in left half 
			b) Maximum subarray sum in right half 
			c) Maximum subarray sum such that the subarray 
	crosses the midpoint */
	return max(maxSubArraySum(arr, l, m - 1), 
			maxSubArraySum(arr, m + 1, h), 
			maxCrossingSum(arr, l, m, h)); 
} 


int main()
{
	int arr[] = { 2, 3, 4, 5, 7 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int max_sum = maxSubArraySum(arr, 0, n - 1); 
	cout << "Maximum contiguous sum is " << max_sum; 

	return 0; 
}

