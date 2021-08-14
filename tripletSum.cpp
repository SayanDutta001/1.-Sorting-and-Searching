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

vector<vector<int>>tripletWithZeroSum(vector<int>&nums,int X)
{
    sort(nums.begin(), nums.end());
    
    vector<vector<int>>triplets;
    int lo,hi,sum;

    // move for every a
    for (int i = 0; i < (int)(nums.size())-2; i++) 
    {
        if (i == 0 || (i > 0 && nums[i] != nums[i-1])) 
        {
            int lo = i+1, hi = (int)(nums.size())-1, sum =X-(nums[i]);
                
                while (lo < hi) 
                {
                    if (nums[lo] + nums[hi]== sum) 
                    {   
                        vector<int> temp; // temp vector to store the unique triplets temporarily
                        temp.push_back(nums[i]); 
                        temp.push_back(nums[lo]); 
                        temp.push_back(nums[hi]); 
                        triplets.push_back(temp); // insert the temp vector and clear the temp vector to store new triplets
                        temp.clear();
                        while (lo < hi && nums[lo] == nums[lo+1]) lo++; // skip duplicates
                        while (lo < hi && nums[hi] == nums[hi-1]) hi--; // skip duplicates
                        lo++; hi--; // if no dupulicates 
                    } 
                    else if (nums[lo] + nums[hi] < sum) lo++;
                    else hi--;
               }
            }
        }
    return triplets;
}   

int32_t main()
{
	FIO;
	
	#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
    #endif
	
	int n,x;
    cin>>n>>x;
    vector<int>nums;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        nums.push_back(x);
    }

    vector<vector<int>>triplets = tripletWithZeroSum(nums,x);
    if(!triplets.empty())
    {
        for(auto it: triplets)
            cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
    }

	return 0;
}
