/*Given two arrays A1[] and A2[] of size N and M respectively. The task is to sort A1 in such a way that the relative order among the elements will be same as those in A2. For the elements not present in A2, append them at last in sorted order. It is also given that the number of elements in A2[] are smaller than or equal to number of elements in A1[] and A2[] has all distinct elements.

Note: Expected time complexity is O(N log(N)).

Input:
First line of input contains number of testcases. For each testcase, first line of input contains length of arrays N and M and next two line contains N and M elements respectively.

Output:
Print the relatively sorted array.

Constraints:
1 = T = 100
1 = N,M = 106
1 = A1[], A2[] <= 106

Example:
Input:
1
11 4
2 1 2 5 7 1 9 3 6 8 8
2 1 8 3

Output:
2 2 1 1 8 8 3 5 6 7 9

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

int t;
cin>>t;

while(t--)
{
    int n,m;    
    cin>>n>>m;
    
    unordered_set<int> ar2;    //for searching element   
    unordered_map<int,int> fre;  //to see count of element of first array 
    int ar1[n] ,ear2[m];     // ear2=extra second array
   
     for(int i=0;i<n;i++)
     {
        cin>>ar1[i];              
        
     }
    
      for(int i=0;i<m;i++)
      {
        int x;
        cin>>x;
        ar2.insert(x);      // using unordered set so that searching in O(1)
        ear2[i]=x;
      }
      
      for(int i=0;i<n;i++)             //counting element of ar1 which are also in second array
     {
        if(ar2.find(ar1[i])!=ar2.end())
        fre[ar1[i]]++;
        
     }
     
      
     for(auto i=0;i<m;i++)
     {
         
         int j=fre[ear2[i]];
         
         for(int k=0;k<j;k++)
         cout<<ear2[i]<<" ";              //printing first those element which are also in second
     }
     sort(ar1,ar1+n);     //sorting becoz we need in sorted of remaining element
     for(int i=0;i<n;i++)
     {
         if(ar2.find(ar1[i])==ar2.end())    //printing remaining element
         cout<<ar1[i]<<" ";
     }
    
     cout<<endl;
    
}
return 0;
}

//time complexity O(nlogn
//space O(m)
//if you found some problem in code reply


