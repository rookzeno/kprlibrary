class UnionFind {
private:
    int n;
    vector<int> uni;
public:
    UnionFind(int _n) {
        n = _n;
        uni.clear();
        uni.resize(n, -1);
    }
    int root(int x) {
        if (uni[x] < 0) return x;
        return uni[x] = root(uni[x]);
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (uni[x] > uni[y]) swap(x, y);
        uni[x] += uni[y];
        uni[y] = x;

    }
    int getSize(int x) {
        return -uni[root(x)];
    }
    void print() {
        for (auto x : uni) cout << x << " ";
        cout << endl;
    }
};
