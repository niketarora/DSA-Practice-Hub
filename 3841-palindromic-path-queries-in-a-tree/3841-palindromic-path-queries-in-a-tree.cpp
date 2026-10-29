#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
private:
    vector<vector<int>> adj;
    vector<int> tin, tout;
    vector<vector<int>> up;
    int timer;
    int LOGN;

    // Fenwick Tree (Binary Indexed Tree) for prefix XOR queries
    class BIT {
        int size;
        vector<int> tree;
    public:
        BIT(int n) : size(n), tree(n + 1, 0) {}
        void update(int i, int delta) {
            for (++i; i <= size; i += i & -i) {
                tree[i] ^= delta;
            }
        }
        int query(int i) {
            int sum = 0;
            for (++i; i > 0; i -= i & -i) {
                sum ^= tree[i];
            }
            return sum;
        }
    };

    void dfs(int u, int p) {
        tin[u] = ++timer;
        up[u][0] = p;
        for (int i = 1; i < LOGN; ++i) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }
        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u);
            }
        }
        tout[u] = timer;
    }

    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int get_lca(int u, int v) {
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;
        for (int i = LOGN - 1; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v)) {
                u = up[u][i];
            }
        }
        return up[u][0];
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        adj.assign(n, vector<int>());
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        timer = 0;
        LOGN = 0;
        while ((1 << LOGN) <= n) LOGN++;
        
        tin.resize(n);
        tout.resize(n);
        up.assign(n, vector<int>(LOGN));

        dfs(0, 0);

        BIT bit(timer + 2);
        for (int i = 0; i < n; ++i) {
            int mask = 1 << (s[i] - 'a');
            bit.update(tin[i], mask);
            bit.update(tout[i] + 1, mask);
        }

        vector<bool> result;
        for (const string& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;
            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;
                
                int old_mask = 1 << (s[u] - 'a');
                int new_mask = 1 << (c - 'a');
                int diff = old_mask ^ new_mask;
                
                s[u] = c;
                bit.update(tin[u], diff);
                bit.update(tout[u] + 1, diff);
            } else {
                int u, v;
                ss >> u >> v;
                
                int lca = get_lca(u, v);
                int path_xor = bit.query(tin[u]) ^ bit.query(tin[v]) ^ (1 << (s[lca] - 'a'));
                
                // Can be rearranged into a palindrome if at most 1 bit is set
                result.push_back((path_xor & (path_xor - 1)) == 0);
            }
        }

        return result;
    }
};
