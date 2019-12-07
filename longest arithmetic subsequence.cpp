/*Given an array of sorted numbers having no duplicates , write a program to find the length of the Longest Arithmetic Progression (LLAP) in it.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines.
The first line of each test case contains an integer N , where  N is the size of array.
The second line of each test case contains N space separated integers denoting array input A[i].

Output:
 Print the length of the Longest Arithmetic Progression ​

Constraints:
1 <=T<= 200
1 <= N <= 1000
1 <= arr[i] <= 10000

Example:

Input:
2
6
1  7 10  13  14  19
5
2 4  6 8 10

Output:
4
5*/





#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        
        int a[n];
        
        for(int i=0;i<n;i++)
        cin>>a[i];
        
    
        unordered_map<int,int> mp;
        vector<unordered_map< int ,int> >  dp(n,mp);
        int res=0;
    
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int diff=a[i]-a[j];
                if(dp[j].find(diff)==dp[j].end())
                dp[i][diff]=1;
                else
                dp[i][diff]=dp[j][diff]+1;
                res=max(res,dp[i][diff]);
            }
        }
        cout<<++res<<endl;
    }
    return 0;
}
