#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <climits>
#include <chrono>
#include <atcoder/all>

using namespace std;

//このコードは改変して使うことがある

/*
ほんまごめん、セグ木パンチ
*/
struct Segtree { //最大値
  vector<long long> data;
  
  Segtree(int N) {
        int tmp = 1;
        while (tmp < N * 2) tmp *= 2;
        for (int i = 0; i < tmp; i++){
          data.push_back((long long)(0));
        }
    }
  
  void update(int pos, long long x){
    pos += data.size() / 2 - 1;
    data[pos] = x;
    while (pos >= 2){
      pos /= 2;
      data[pos] = max(data[pos * 2], data[pos * 2 + 1]);
    }
  }
  
  long long query(int l, int r, int a, int b, int u){
    if (r <= a || b <= l) return (long long) -1;
    if (l <= a && b <= r) return data[u];
    
    int m = (a + b) / 2;
    long long ans_L = query(l,r,a,m,u * 2);
    long long ans_R = query(l,r,m,b,u * 2 + 1);
    return max(ans_L,ans_R);
  }
};

// tree.query(L,R,1,tree.data.size() / 2 + 1,1)で[L,R)の最大値を求めることができる