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
#define pqs             priority_queue<int,vi,greater<int> >
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

vector<int>arrayUnion(vector<int>&a1,vector<int>&a2)
{
	int n = a1.size();
	int m = a2.size();

	int i,j,index=-1; // index pointer to keep track of duplicate values and denote the currently filled index of the ans vector
	i=j=0; // two pointers to traverse the sorted vectors from index 0

	vector<int>ans;
	while(i<n and j<m)
	{
		if(a1[i]<=a2[j])
		{
			ans.pb(a1[i++]); // push an element
			++index; // and increment index
		}
		else
		{
			ans.pb(a2[j++]);
			++index;
		}
		while(ans[index] == a1[i])	i++; // if there are duplicate values, it will be seived via this operation. 
		while(ans[index] == a2[j])	j++; // The operation is we increment i and j until i  points to some unique value in a1 and j points to some unique value in a2
	}
  
  // one of the arrays may get exhaustd first hence this method is performed to fill up the rest of the elements in the ans vector from non - exhausted array
	while(i<n)
  {
		ans.pb(a1[i++]);
		++index;
		while(ans[index] == a1[i])	i++;
	}
	while(j<m)
  {
		ans.pb(a2[j++]);
		++index;
		while(ans[index] == a2[j])	j++;
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
	
	vector<int>a1,a2; // two sorted vector -> a1 and a2 
	int n,m; 

	cin>>n; // size of the sorted vector 1
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a1.pb(x); // sorted vector 1 input
	}

	cin>>m; // size of the sorted vector 2
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x; 
		a2.pb(x); // sorted vector 2 input
	}
	vector<int>ans;
	ans = arrayUnion(a1,a2); // copy returned vector to the ans vector
  
	for(auto x: ans) // print ans vector
		cout<<x<<" ";
	return 0;
}
