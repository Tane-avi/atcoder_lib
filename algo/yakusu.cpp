//用途によって改造することがある。
//https://github.com/Tane-avi/atcoder_lib
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
#include <bitset>
#include <random>
#include <iomanip>

using namespace std;
using ll = long long;
#define rep(i,k) for (ll i = 0; i < (ll)(k); i++)

vector<vector<ll>> yakusu(int N){//N=30万くらいまで
    vector<vector<ll>> V(N + 1);
    for (int i = 1; i <= N; i++){
        if (i == 1) V[1].push_back(1);
        else {
            V[i].push_back(1);
            V[i].push_back(i);
            for (int j = 2; j * j <= i; j++){
                if (i % j == 0) {
                    V[i].push_back(j);
                    if (j * j != i)V[i].push_back(i / j);
                }
            }
        }
    }
    return V;
}