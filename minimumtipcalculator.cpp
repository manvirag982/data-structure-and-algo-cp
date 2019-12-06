/*Rahul and Ankit are the only two waiters in Royal Restaurant. Today, the restaurant received N orders. The amount of tips may differ when handled by different waiters, if Rahul takes the ith order, he would be tipped Ai rupees and if Ankit takes this order, the tip would be Bi rupees.
In order to maximize the total tip value they decided to distribute the order among themselves. One order will be handled by one person only. Also, due to time constraints Rahul cannot take more than X orders and Ankit cannot take more than Y orders. It is guaranteed that X + Y is greater than or equal to N, which means that all the orders can be handled by either Rahul or Ankit. Find out the maximum possible amount of total tip money after processing all the orders.


Input:

•    The first line contains one integer, number of test cases.
•    The second line contains three integers N, X, Y.
•    The third line contains N integers. The ith integer represents Ai.
•    The fourth line contains N integers. The ith integer represents Bi.

 

Output:
Print a single integer representing the maximum tip money they would receive.
 

Constraints:
1 ≤ N ≤ 105
1 ≤ X, Y ≤ N; X + Y ≥ N
1 ≤ Ai, Bi ≤ 104

 

Example:

Input:

2
5 3 3
1 2 3 4 5
5 4 3 2 1
8 4 4
1 4 3 2 7 5 9 6 
1 2 3 6 5 4 9 8

 

Output:

21
43*/







// by recursion O(2^n)

#include<bits/stdc++.h>
using namespace std;

int fun(int ai[],int bi[], int sum,int i,int x,int y,int n){
	//static int count=0;
	//count++;
	//cout<<"sum"<<sum<<" "<<"i"<<i<<" "<<"x"<<" "<<x<<"y"<<" "<<y<<"      "<<count<<endl;
	if(i>=n||x<=0&&y<=0)
	return sum;
    else if(x==0){
		
    	return fun(ai,bi,sum+bi[i],i+1,x,y-1,n);
	}
	else if(y==0){
		
		return fun(ai,bi,sum+ai[i],i+1,x-1,y,n);
	}
	else
	{
		return max(fun(ai,bi,sum+ai[i],i+1,x-1,y,n),fun(ai,bi,sum+bi[i],i+1,x,y-1,n));
		
	}
	
}
int main(){
	
	int t=1; 
	//cin>>t;
	 while(t--){
	int n=7; 
	//cin>>n;
//	int n;  
	int x=3; int y=4;
	//cin>>x>>y;
	int ai[n]={8 ,7 ,5 ,9 ,6 ,6 ,8};
	int bi[n]={1 ,7, 5, 1, 2, 3, 9};
	//for(int i=0;i<n;i++)
	//cin>>ai[i];
	//for(int i=0;i<n;i++)
	//cin>>bi[i];
	
	int sum=0;
	
	cout<<fun(ai,bi,sum,0,x,y,n)<<endl; }
	return 0;
}

//soon come with dp solution
