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

int meetMaxGuests(vector<int>&entry,vector<int>&exit)
{
    // sort the entry and exit arrays
    sort(entry.begin(), entry.end()); 
    sort(exit.begin(), exit.end());

    // two pointers to keep track of the entry exit elements
    int i=0,j=0;

    // to count guests at a particular interval
    int guests = 0;
    int max_guests = INT_MIN;

    // the intuition is to increment count of guests when entry[] element < exit[] element
    while(i<entry.size() and j<exit.size())
    {
        if(entry[i]<=exit[j])
        {
            guests++,i++;
        }
        else
        {
            guests--,j++;
        }
        max_guests=max(max_guests,guests);
    }
    return max_guests;
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
    vector<int> entry;
    vector<int> exit;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        entry.pb(x);
    }
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        exit.pb(x);
    }
    cout<<meetMaxGuests(entry,exit);
	return 0;
}
