#include<bits/stdc++.h>
#include<vector>
using namespace std;

class SegementTree{
    public:
    vector<long long> data;
    vector<long long> ST;
    int identity;
    SegementTree(vector<long long> data, int identity = 0)
    {
        this->data = data;
        this->identity = identity;
        ST.resize(4*data.size(), identity);
    }

    SegementTree(int sz)
    {
        data.resize(sz);
        ST.resize(4*sz);
    }

    long long calc(long long a, long long b);

    long long build(int index, int st, int en)
    {
        if(st > en)
        {
            return identity;
        }
        if(st == en)
        {
            ST[index] = data[st];
            return ST[index];
        }
        int mid = st+ (en-st)/2;
        long long first = build(index*2, st, mid);
        long long sec = build(index*2+1, mid+1, en);
        return calc(first, sec);
    }

    long long build()
    {
        build(1, 0, data.size()-1);
    }

    long long update(int index, int u_index, int st, int en)
    {
        if(st > en)
        {
            return identity;
        }
        if(u_index < st || u_index > en)
        {
            return ST[index];
        }
        if(st == en)
        {
            ST[index] = data[u_index];
            return ST[index];
        }
        int mid = st + (en - st)/2;
        long long first = update(index*2, u_index, st, mid);
        long long sec = update(index*2+1, u_index, mid+1, en);
        return calc(first, sec);
    }

    long long update(int index, int value)
    {
        data[index] = value;
        update(1, index, 0, data.size()-1);
    }

    long long query(int index, int low, int hi, int st, int en)
    {
        if(hi < st || low > en)
        {
            return identity;
        }
        if(low == st && hi == en)
        {
            return ST[index];
        }

        int mid = st + (en-st)/2;

        long long first = query(index*2, low, min(mid, hi), st, mid);
        long long sec = query(index*2+1, max(mid+1, low), hi, mid+1, en);

        return calc(first, sec);
        
    }

    long long query(int low, int hi)
    {
        return query(1, low, hi, 0, data.size()-1);
    }
};