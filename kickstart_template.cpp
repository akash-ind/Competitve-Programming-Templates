#include<bits/stdc++.h>
using namespace std;
#define For(i, j, n) for(int i=j;i<n;i++)
#define Rep(n) for(int i=n-1;i>=0;i--)
#define ll long long
#define pb push_back
#define pll pair<ll, ll>
#define vi vector<int>
#define endl "\n"
#define all(a) (a).begin(), (a).end()
#define deb(x) cout<<#x<<"="<<x<<endl
#define deb2(x, y) cout<<#x<<"="<<x<<" ,"<<#y<<"="<<y<<endl;
void input(vector<int> &arr, int n);
void p_y_n(bool y = false)
{
    if(y)
    {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}

void solve()
{

}


int main()
{
    int t;
    cin>>t;
    For(i, 1, t+1)
    {
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}




void input(vector<int> & arr, int n)
{
    For(i, 0, n)
    {
        cin>>arr[i];
    }
}




/* Suggestions:

    1. Always check for overflow.
    2. Getting WA. Then check for graphical method or try brute force. 
*/