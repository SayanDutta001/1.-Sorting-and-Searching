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

vector<int>arrayIntersection(vector<int>&v1,vector<int>&v2)
{
	  int i,j,index;
    i = j = 0; // pointer to the two sorted arrays
    index = -1; // pointer to the ans array(intersection array)
    vector<int>ans;
  
    while(i < v1.size() and j < v2.size()) 
    {
        if(v1[i] == v2[j]) // if same then insert in the intersection array
        {
            ans.pb(v1[i]); 
            ++index;
            i++;
            j++;
        }
        // skip the unequal elements 
        if(v1[i]<v2[j]) i++;
        else if(v2[j]<v1[i]) j++;
      
        // to skip duplicates
        if(!ans.empty())
        {
            while(ans[index]==v1[i]) i++;
            while(ans[index]==v2[j]) j++;
        }
    }
    return ans;
}

int32_t main()
{
	FIO;
	
	#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
    #endif
	
	vector<int>a1,a2;
    int n,m;

    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a1.pb(x);
    }

    cin>>m;
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        a2.pb(x);
    }
    vector<int>ans;
    ans = arrayIntersection(a1,a2);
    for(auto x: ans)
        cout<<x<<" ";

	return 0;
}
