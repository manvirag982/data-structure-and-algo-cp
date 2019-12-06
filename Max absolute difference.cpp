// great application of kadane algorithm

/*Given an array of integers, find two non-overlapping contiguous sub-arrays such that the absolute difference between the sum of two sub-arrays is maximum.

For example,

Input: [-2, -3, 4, -1, -2, 1, 5, -3]
Output: 12
Two subarrays are [-2, -3] and [4, -1, -2, 1, 5]

Input: [2, -1, -2, 1, -4, 2, 8]
Output: 16
Two subarrays are [-1, -2, 1, -4] and [2, 8] 

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each Test case contains an integer N denoting the size of the array. Then in the next line are N space separated values of the array.

Output:
For each test case in a new line print the required output.

Constraints:
1<=T<=100
1<=N<=100
-1000<=A[]<=1000

Example:
Input:
2
7
2 -1 -2 1 -4 2 8
8
-2 -3 4 -1 -2 1 5 -3
Output:
16
12*/






#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t; cin>>t;  while(t--){
	    int n; cin>>n;  int a[n];  for(int i=0;i<n;i++) cin>>a[i];
	    
	    // using concept of kadane algorithm
	    int minl[n],maxl[n],minr[n],maxr[n];
	    
	    minl[0]=a[0]; maxl[0]=a[0]; minr[n-1]=a[n-1]; maxr[n-1]=a[n-1];
	    for(int i=1;i<n;i++){
	        minl[i]=min(a[i],minl[i-1]+a[i]);
	        maxl[i]=max(a[i],maxl[i-1]+a[i]);}
	     
	    for(int i=n-2;i>=0;i--){
	       minr[i]=min(a[i],minr[i+1]+a[i]);
	       maxr[i]=max(a[i],maxr[i+1]+a[i]);
	    }
	    int temp1=INT_MIN; int temp2=INT_MIN; int res=INT_MIN;
	    for(int i=0;i<n;i++){
	        
	        if(i!=0)
	        temp1=max(temp1,maxr[i]-minl[i-1]);
	        if(i!=n-1)
	        temp2=max(temp2,maxl[i]-minr[i+1]);
	        
	     }
	     res=max(temp1,temp2);
	     cout<<res<<endl;
	    
	}
	return 0;
}



//O(n) time complexity
