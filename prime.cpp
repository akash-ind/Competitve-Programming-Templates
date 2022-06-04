#include<bits/stdc++.h>
using namespace std;


const int N = 1e5+10;

bool prime_no[N] = {true};
vector<int> prime;

void find_prime()
{
    for(int i = 2;i<N;i++)
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