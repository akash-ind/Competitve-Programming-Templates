#include<bits/stdc++.h>
using namespace std;


class LCA{
    public:
        vector<vector<int>> g;
        vector<vector<int>> up;
        vector<int> depth;
        vector<int> tin, tout;
        int timer;
        LCA(vector<vector<int>> g)
        {
            this->g = g;
            int N = g.size();
            this->up = *new vector<vector<int>>(N, vector<int>(26, 0));
            this->depth = *new vector<int>(N);
            this->tin = *new vector<int>(N);
            this->tout = *new vector<int>(N);
            this->timer = 0;
        }

        void preprocess(int st = 0, int p = 0)
        {
            tin[st] = timer++;
            depth[st] = timer;
            up[st][0] = p;
            for(int i = 1;i<26;i++)
            {
                up[st][i] = up[up[st][i-1]][i-1];
            }
            for(int v: g[st])
            {
                if(p != v)
                {
                    preprocess(v, st);
                }
            }
            tout[st] = timer++;
        }


        bool is_ancestor(int u, int v)
        {
            return tin[u]< tin[v] && tout[v] > tout[v];
        }

        int get_lca(int u, int v)
        {
            if(is_ancestor(u, v))
            {
                return u;
            }
            if(is_ancestor(v, u))
            {
                return v;
            }
            for(int i = 25;i>=0;i--)
            {
                if(!is_ancestor(up[u][i], v))
                {
                    u = up[u][i];
                }
            }
            return up[u][0];
        }
};