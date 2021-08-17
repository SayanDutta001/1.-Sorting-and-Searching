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

// Approach 1: O(nlogn+3n) (If the restriction on extra space is not imposed) Using an extra space and then putting all the elements of 
// the two arrays and sorting the new array and then inserting the elements from the new sorted array to a1 and a2
// a1[]={1,4,7,8,10}
// a2[]={2,3,9}
// a3[n1+n2]={1,4,7,8,10,2,3,9} -> sorting a3[]={1,2,3,4,7,8,9,10} O(nlogn+n) for sorting and insertion of elements from a1 and a2
// a1[]={1,2,3,4,7} // O(n) for insertion from a3 to a1
// a2[]={8,9,10} // O(n) for insertion from a3 to a2

//Approach 2: insertion sort kind of algorithm
// void mergeSoredArraysWithoutExtraSpace(vector<int>&a1,vector<int>&a2)
// {
//     int i,j;
//     i=j=0;
//     while(i < a1.size() and j < a2.size())
//     {
//         if(a1[i] <= a2[j]) // if element of a1 is in correct place then we increment i to the next position
//             i++;
//         else
//         {
//             swap(a2[j],a1[i++]); // if not present in correct position we swap with a2's first element
//             // after swapping a2 will be unsorted, now we need to sort it again to complete the process
//             if(j < a2.size()-1 and a2[j]>a2[j+1]) // the sorting can only happen if there are atleast two elements in a2
//             {
//                 int temp = a2[j];
//                 int tempj = j+1;
//                 while(tempj<a2.size() and a2[tempj]<temp)
//                 {
//                     a2[tempj-1] = a2[tempj];
//                     tempj++;
//                 }
//                 a2[tempj - 1] = temp; 
//             }
//         }
//     }
//     return;
// }

// Approach 3: Gap Method
void mergeSoredArraysWithoutExtraSpace(vector<int>&a1,vector<int>&a2)
{
    // 1 4 7 8 10 2 3 9
    int n = a1.size();
    int m = a2.size();
    int size = n + m;
    int gap = size/2 + size%2;
    while(gap>0)
    {
        int low = 0;
        int high = gap;
        while(low<n and high<n) // when both low and high pointers are pointing towards the first array i.e gap < n
        {
            if(a1[low]>a1[high])
                swap(a1[low],a1[high]);
            low++,high++;
        }

        high = (high > n)? abs(high - n) : 0; // when the high pointer is pointing towards an element in the second array, there can be two such cases which is 
                                              // quite evident from the code 
        while(low < n and high < m) // low pointer in the first array and the high pointer present in the second array
        {
            if(a1[low]>a2[high])
                swap(a1[low],a2[high]);
            low++,high++;
        }

        if(low==n) // when low pointer crosses the boundary of the first array, low is made to point towards the first element of the second array
            low=0;
        while(high<m) // when both the pointers are present in the second array
        {
            if(a2[low]>a2[high])
                swap(a2[low],a2[high]);
            low++,high++;
        }
        if(gap == 1) // for gap==1 the code will run once and when it arrives to this point the code should stop else there's gonna be a segmentation fault 
             break;  //  since 1%2 == 1, the code will run on and on
      
        gap = gap/2+gap%2;
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
	
	int n,m;
    cin>>n>>m;
    vector<int>a,b;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }

    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        b.push_back(x);
    }

    mergeSoredArraysWithoutExtraSpace(a,b);

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<m;i++)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;
	return 0;
}

