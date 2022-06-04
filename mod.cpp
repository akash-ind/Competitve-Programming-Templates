#include<bits/stdc++.h>
using namespace std;

int gcd_extended(int a, int b, int &x, int &y)
{
    if(a == 0)
    {
        x = 0, y = 1;
        return b;
    }
    int k = gcd_extended(b%a, a, x, y);
    x = y - (b/a)*x;
    y = x;
    return k;
}

int modulo_inverse(int a, int mod)
{
    int x, y;
    int k = gcd_extended(a, mod, x, y);
    if(k!= 1)
    {
        return -1;
    }
    else{
        return x;
    }
}