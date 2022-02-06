

class UnionFind {
    vector<int> parent;
    vector<int> rank;
    int _count;
public:
    UnionFind(int n) :
            _count(n) {
        this->parent.resize(n);
        this->rank.resize(n);

        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int p) {
        while (p != parent[p]) {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }
    int count() {
        return _count;
    }
    bool connected(int p, int q) {
        return find(p) == find(q);
    }
    void join(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ){
            return;
        }
        if (rank[rootP] < rank[rootQ]) parent[rootP] = rootQ;
        else if (rank[rootQ] < rank[rootP]) parent[rootQ] = rootP;
        else {
            parent[rootQ] = rootP;
            rank[rootP]++;
        }
        _count--;
    }
};