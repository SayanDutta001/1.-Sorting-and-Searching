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

void mergeIntervals(vector<pair<int,int>>&arr)
{
    sort(arr.begin(), arr.end());
    int res = 0;
    for(int i=1;i<arr.size();i++)
    {
        if(arr[res].second>=arr[i].first)
        {
            arr[res].second= max(arr[i].second,arr[res].second);
            arr[res].first=min(arr[i].first,arr[res].first);
        }
        else
        {
            res++;
            arr[res] = arr[i];
        }
    }
    arr.erase(arr.begin()+res+1,arr.end());
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
    vector<pair<int,int>>arr;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        arr.pb(make_pair(x,y));
    }
    
    mergeIntervals(arr);

    for(auto it: arr)
        cout<<it.first<<" "<<it.second<<endl;
	return 0;
}
