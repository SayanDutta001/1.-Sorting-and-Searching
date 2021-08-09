// link to the problem: https://practice.geeksforgeeks.org/problems/count-possible-triangles-1587115620/1#

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

int countTriangles(vi&arr)
{   
    sort(arr.begin(),arr.end());
    int count = 0;
    int n = arr.size();
    int i = n-1;
    int l,r;
    while(i!=1)
    {
        int target = arr[i];
        l = 0;
        r = i-1;
        while(r - l != 0)
        {
            if(arr[l] + arr[r] > target)
            {
                count+=(r-l);
                r--;
            }
            else
                l++;
        }
        i--;
    }
    return count;
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
    vector<int>arr;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.pb(x);
    }
    cout<<countTriangles(arr);
	  return 0;
}
