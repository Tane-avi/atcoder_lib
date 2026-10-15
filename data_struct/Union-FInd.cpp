//このコードは改変して使うことがある
struct UnionFind {
    vector<int> par,height; 
    
    UnionFind(int N) : par(N),height(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
        for(int i = 0; i < N; i++) height[i] = 1;//連結成分の大きさ
    }
    
    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    
    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); 
        int ry = root(y); 
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        if(height[rx] < height[ry]){
            par[rx] = ry;
        }
        else{
            par[ry] = rx;
            if(height[rx] == height[ry]){
                ++height[rx];
            }; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
        }
    }
    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};