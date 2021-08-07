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

bool sortbysec(tuple<int,int,int>&a,tuple<int,int,int>&b)
{
	if(get<0>(a)==get<0>(b) and get<1>(a) > get<1>(b))
		return true;
	if(get<0>(a) < get<0>(b))
		return true;
	return false;
}

bool sortbythird(tuple<int,int,int>&a,tuple<int,int,int>&b)
{ 
	if((get<0>(a) == get<0>(b)) and (get<1>(a)==get<1>(b)) and get<2>(a)<get<2>(b))
		return true;
	if(get<0>(a)<get<0>(b) )
		return true;
	return false;
}

int32_t main()
{
	FIO;
	
	#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
    #endif
	
	vector<int>p,c,m; // to store physics, chemistry, maths marks individually
	int n; // input no. of students
	cin>>n;

	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		p.pb(x);
	}
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		c.pb(x);
	}
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		m.pb(x);
	}

	vector<tuple<int,int,int>>marks;
	
	for(int i=0;i<n;i++)
		marks.pb(mt(p[i],c[i],m[i])); // pcm marks as a single unit stored in vectors

	sort(marks.begin(),marks.end()); // sort marks of physics

	sort(marks.begin(),marks.end(),sortbysec); // sort marks of chemistry using comparators

	sort(marks.begin(),marks.end(),sortbythird); // sort marks of mathematics using comparators

	for(int i =0;i<n;i++)
	{
		cout<<get<0>(marks[i])<<" "<<get<1>(marks[i])<<" "<<get<2>(marks[i])<<"\n";
	}
	return 0;
}
