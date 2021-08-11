// question has many variation like 1. sort an array of 0,1,2 2. Partitioning in a range 3. Three way partitioning
// Naive method would be to use counting sort
// efficient approach : Dutch National Flag, which is an extension of Hoare's Partition Method

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

void sort012(vi&arr)
{
    int low = 0;
    int mid = 0;
    int high = arr.size()-1;
    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==2)
        {
            swap(arr[mid],arr[high]);
            high--;
        }

        else
            mid++;
        
    } 
    return;
}

void threewayPartitioning(vi &arr,int upper, int lower)
{
    int low = 0;
    int mid = 0;
    int high = arr.size()-1;
    while(mid<=high)
    {
        if(arr[mid]<upper)
        {
            swap(arr[mid],arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid]>lower)
        {
            swap(arr[mid],arr[high]);
            high--;
        }
        else
            mid++;
            
    }
    return;
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
    vi arr;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    sort012(arr);
    for(auto x:arr)
        cout<<x<<" ";
    cout<<"\n";

    arr.clear();
    int m,upper,lower;
    cin>>m>>upper>>lower;
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    threewayPartitioning(arr,upper,lower);
    for(auto x:arr)
        cout<<x<<" ";
    cout<<"\n";
	return 0;
}
