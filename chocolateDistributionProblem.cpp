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

int chocolateDistribution(vi&arr,int m)
{
    int n = arr.size();
    if(m>n) // if no. of children greater than the chocolate packets, return -1
        return -1;
    sort(arr.begin(),arr.end());
    int i,j; // make a sliding window using two pointers
    i = 0, j=m-1;
    int mi = INT_MAX;
    while(j<n)
    {
        mi = min(mi,arr[j] - arr[i]); // find the min of the max_element - min_element of the sliding window
        i++,j++; // increment the pointers to move to the next window
    }
    return mi; 
}

int32_t main()
{
	FIO;
	
	#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
    #endif
	
	int n,k;
    cin>>n>>k;
    vi arr;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<chocolateDistribution(arr,k);
	return 0;
}
