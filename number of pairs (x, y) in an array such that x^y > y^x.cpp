// link : https://www.geeksforgeeks.org/find-number-pairs-xy-yx/
// Find number of pairs (x, y) in an array such that x^y > y^x
// Given two arrays X[] and Y[] of positive integers, find a number of pairs such that x^y > y^x where x is an element from X[] and y is an element from Y[].
// Examples:
// Input: X[] = {2, 1, 6}, Y = {1, 5} 
// Output: 3 
// Explanation: There are total 3 pairs where pow(x, y) is greater than pow(y, x) Pairs are (2, 1), (2, 5) and (6, 1)

// Input: X[] = {10, 19, 18}, Y[] = {11, 15, 9} 
// Output: 2 
// Explanation: There are total 2 pairs where pow(x, y) is greater than pow(y, x) Pairs are (10, 11) and (10, 15)

// Approach 1 would be to check for every pair present in both the arrays like :
//   for(int i=0;i<n;i++)
//   {
//     for(int j=0;j<m;j++)
//     {
//          if(pow(X[i],Y[j]>pow(Y[j],X[i])
//                  count++;
//     }
//   }


// Approach 2 O(nlogn + mlogm) where we explicitly check for x = 0,1,2,3,4,5,6,7, and so on and find that the pairs form when y > x
// with some exceptions.
// And we sort the array y to easily find how many y > x are present 
// for x = 0, there are no pairs possible. 0^0 > 0^0 , 0^1 > 1^0 , 0^2 > 2^0..... all results in false hence no pairs possible
// for x = 1, 1^0 > 0^1(true) , 1^1 > 1^1 , 1^2 > 2^1 , 1^3 > 3^1...... beyond y=0 every value of y corresponds to false
// for x = 2, 2^0 > 0^2(true) , 2^1 > 1^2(true) , 2^2 > 2^2(false), 2^3 > 3^2(false) , 2^4 > 4^2(false) , 2^5 > 5^2(true), 2^6 > 6^2(true)... 
// beyond y=5 all values are true. The exceptions for x=2 are y=3,4 
// for x = 3, for 0,1 -> true, 3^2>2^3 -> true, 3^3 > 3^3 false , beyond 3 every value of y corresponds to true. 
// For 3 the exception is even for y = 2, the condition holds true

#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> 
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

  
int countPairs(int x,vector<int>&y,vector<int>&countNoOfY)
{
    if(x == 0)
        return 0; // since no pairs possible return 0

    if(x == 1)
        return countNoOfY[0]; // since pairs possible only for y=1 return no of 1's present in array Y

    auto it = upper_bound(y.begin(),y.end(),x); // find the address of the value greater than x

    int ans = y.end() - it; // to find how many elements are greater than x i.e y>x

    // since x > 1, all values of y = 0,1 possible hence we sum up them with the add variable
    ans+=(countNoOfY[0]+countNoOfY[1]);

    // for x = 2, the exception is 3,4  
    if(x==2)
        ans-=(countNoOfY[3]+countNoOfY[4]);

    // for x = 3, even y = 2, satisfies the condition
    if(x==3)
        ans+=(countNoOfY[2]); 

    return ans;
}

int countNoOfPairs(vector<int>&x,vector<int>&y)
{
    sort(y.begin(), y.end());
    
    vector<int>countOfY(5,0); // count of no. of 0,1,2,3,4 present in Y
    for(int i=0;i<y.size();i++)
    {
        if(y[i]<5)
            countOfY[y[i]]++;
        else
            break;
    }

    int totalPairs = 0; // count of pairs

    for(int i=0;i<(int)x.size();i++)
        totalPairs+=(countPairs(x[i],y,countOfY));

    return totalPairs;

}

int32_t main()
{
	FIO;
	
	#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
    #endif
	
	int n,m;
    cin>>n>>m;
    vector<int>a,b;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }

    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        b.push_back(x);
    }

    cout<<countNoOfPairs(a,b);
	return 0;
}
