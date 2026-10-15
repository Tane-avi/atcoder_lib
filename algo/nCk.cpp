#include <iostream>
#include <atcoder/all>
using namespace std;

//このコードは改変して使うことがある
// AtCoder の modint を使う
//二項係数、結果が小さいもの
long long com(long long n, long long k){
    long long res = 1;
    if (n != 0 && k == 0) return 1;
    for (int i = n; i >= n - k + 1; i--){
        res *= i;
    }
    for (int i = 1; i <= k; i++){
        res /= i;
    }
    return res;
}

// 素数で割った余りを取る必要があるもの
using mint = atcoder::modint998244353;

const int MAX = 510000;
mint fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    const int MOD = mint::mod();
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i;
        inv[i] = MOD - inv[MOD%i] * (MOD / i);
        finv[i] = finv[i - 1] * inv[i];
    }
}

// 二項係数計算
mint COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * finv[k] * finv[n - k];
}

// COMinit()をmainで呼び出して前処理(O(N))
// COM(n,k).val()で呼び出し