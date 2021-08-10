// These question has many variations like 1.segregate even and odd, 2.Segregate Negatives and Positives 3. Sort a Binary Array

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

void segregateEvenOdd(vi&arr) // similar to lomuto partition -> slight modifications
{
    int j = -1;
    int n = arr.size();
    for(int i=0;i<n;i++)
    {
        if((arr[i] & 1) == 0)
        {
            swap(arr[++j],arr[i]);
        }
    } 
    swap(arr[++j],arr[n-1]);
}

void seggatePosNeg(vi&arr1)
{
    int j=-1;
    int pivot = 0;
    for(int i=0;i<arr1.size();i++)
    {
        if(arr1[i]<pivot)
        {
            swap(arr1[++j],arr1[i]);
        }
    }

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
    segregateEvenOdd(arr);
    for(auto x:arr)
        cout<<x<<" ";
    cout<<"\n";

    int n1;
    cin>>n1;
    vi arr1;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr1.push_back(x);
    }
  
    seggatePosNeg(arr1);
    for(auto x:arr1)
        cout<<x<<" ";
    cout<<"\n";
	return 0;
}
