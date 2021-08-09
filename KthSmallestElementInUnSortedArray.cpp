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

// Naive Approach -> Sort the array and return k-1th index O(nlogn)
// we are making a modification in the array, not so suitable approach
// int kthSmallest(int arr[],int n,int k)
// {
//     sort(arr,arr+n);
//     return arr(k-1);
// }

// Approach 1: Using Quick Select Algorithm O(n^2) but average time complexity is O(n)
// int lomutoPartition(int arr[],int lo,int hi)
// {
//     int pivot = arr[hi];
//     int i = lo - 1;
//     for(int j=lo;j<hi;j++)
//     {
//         if(arr[j]<pivot)
//             swap(arr[++i],arr[j]);       
//     }
//     swap(arr[++i],arr[hi]);
//     return i;
// }
// int kthSmallest(int arr[],int n,int k)
// {
//     int lo=0;
//     int hi=n-1;
//     while(lo<=hi)
//     {
//         int p = lomutoPartition(arr,lo,hi);
//         if(p==k-1) // works like binary search
//             return arr[p];
//         else if(p>k-1)
//             hi = p - 1;
//         else
//             lo = p + 1;
//     }
//     return -1;
// }

// Approach 2 : Using Sets // O(k+nlogn)
// int kthSmallest(int arr[],int n,int k)
// {    
//     if(k<0 || k-1>n) // if given position is out of bound
//         return -1;

//     set<int>s(arr,arr+n); // copy array elements to the set -> nlogn time complexity
//     auto it = s.begin(); // iterator to the set
//     advance(it,k-1);
//     if(it != s.end())
//         return (*it);
//     return -1;
// }

// Approach 3: To handle duplicates O(nlogn)
int kthSmallest(int arr[],int n,int k)
{
    map<int,int>mp;
    for(int i=0;i<n;i++)
        mp[arr[i]]++;
    int count = 0;
    auto it = mp.begin();
    for(int i=0;i<n;i++)
    {   
        if(count == k-1)
            return it->first;
        if(count > k-1)
            break;
        advance(it,1);
        count++;
    }
    return -1;
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
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<kthSmallest(arr,n,k);
	return 0;
}
