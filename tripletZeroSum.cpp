// Approach 1 O(n^3) is use to consider all the triplets by runnning three for loops and checking if the sum is == 0.
//  for(int i = 0;i < n;i++)
//  {
//    for(int j = i+1;j < n;j++)
//    {
//      for(int k = j+1;k < n;k++)
//      {
//        if(arr[i]+arr[j]+arr[k] == 0)
//          cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl; // Note : if you are required to find the triplets then you can use a 'set' to store the triplet
//      }
//    }
//  }

// Approach 2 O(n^2 + nlogn)
// the triplet sum will be like a+b+c = 0 so, we can manipulate it to b+c = -a (a,b,c = array elements)
// to make the above manipulation come to practice in a simple way, we can sort the array first in an ascending order
// since there can be multiple values of b and c whose sum corresponds to -a, what we can do is use two pointer technqiue
// now we can apply two pointer technique, where one pointer for element b and another pointer for element c 

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

vector<vector<int>>tripletWithZeroSum(vector<int>&nums)
{
    sort(nums.begin(), nums.end());
 
    vector<vector<int>>triplets;
    
    if(nums[0]>0) // if the first element starts with a non integer then return an empty vector because there will be no triplet that corresponds to 0
        return triplets;

    int lo,hi,sum;

    // move for every a
    for (int i = 0; i < (int)(nums.size())-2; i++) 
    {
        if (i == 0 || (i > 0 && nums[i] != nums[i-1])) 
        {
            int lo = i+1, hi = (int)(nums.size())-1, sum = -(nums[i]); // if a triplet sum for a given number is to be found then change sum = X - nums[i]
                
                while (lo < hi) 
                {
                    if (nums[lo] + nums[hi] == sum) 
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
	
	int n;
    cin>>n;
    vector<int>nums;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        nums.push_back(x);
    }

    vector<vector<int>>triplets = tripletWithZeroSum(nums);

    if(!triplets.empty())
    {
        for(auto it: triplets)
            cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
    }
	return 0;
}
