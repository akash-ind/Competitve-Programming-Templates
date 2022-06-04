#include<bits/stdc++.h>
using namespace std;
#define For(i, j, n) for(int i=j;i<n;i++)
#define Rep(n) for(int i=n-1;i>=0;i--)
#define ll long long
#define pb push_back
#define vi vector<int>
const int N = 1e5+10;
int n;
int arr[N];
bool prime_no[N] = {true};
vector<int> prime;

void find_prime()
{
    For(i, 2, N)
    {
        if(!prime_no[i])
        {
            continue;
        }
        for(int j = i+i;j<N;j+=i)
        {
            prime_no[j] = false;
        }
        prime.push_back(i);
    }
}

void solve()
{

}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}











/* Suggestions:

    1. Always check for overflow.
    2. Getting WA. Then check for graphical method or try brute force. 
*/