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

vector<vector<int>>mergeIntervals(vector<vector<int>>&intervals)
{
    vector<vector<int>>merged; // merged array to store the non over lapping intervals
    
    if(intervals.size() == 0) // corner case : if the array to be merged is empty
        return merged; // return empty array in that case
    
    sort(intervals.begin(), intervals.end()); // sort the array if it is not sorted

    vector<int>tempInterval=intervals[0]; // tempInterval is created for comparison of end value to the start value of intervals
    for(auto it : intervals)
    {
        if(it[0] <= tempInterval[1]) // if current starting element of interal's array is smaller than the 
            tempInterval[1] = max(it[1],tempInterval[1]); // if the starting element lies within the interval then the end point is updated
        else
        {
            merged.push_back(tempInterval); // if not in range then the current non lapping merged interval is pushed
            tempInterval = it; // and we move to the next interval
        }
    }
    merged.push_back(tempInterval); // to store the final non over lapping interval
    return merged;
}

int32_t main()
{
	FIO;
	
	#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
    #endif
	
	int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(2,0));
    vector<vector<int>> ans(n,vector<int>(2,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2;j++)
        {
            int x;
            cin>>x;
            arr[i][j]=x;
        }
    }
    
    ans = mergeIntervals(arr);

    for(auto it: ans)
        cout<<"{"<<it[0]<<","<<it[1]<<"}"<<endl;
	return 0;
}
