// ABC417, problemb

#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG  //[]で配列外参照をするとエラーにしてくれる。上下のやつがないとTLEになるので注意
                        // ABC311Eのサンプル4みたいなデバック中のTLEは防げないので注意
#endif

#include <bits/stdc++.h>
using namespace std;
#include <algorithm>

#define PRINT_VAR(x)  // 変数名を出力

template <typename T>
using vc = vector<T>;  // prioriy_queueに必要なのでここにこれ書いてます
template <typename T>
using vv = vc<vc<T>>;

//-------------1.型系---------------
using ll = long long;
ll INF = 2e18;

using ld = long double;

template <class T>
using pq = priority_queue<T, vc<T>>;  // 大きい順
template <class T>
using pq_g = priority_queue<T, vc<T>, greater<T>>;  // 小さい順

//-------------2.配列系--------------
using vl = vc<ll>;
using vvl = vv<ll>;
using vvvl = vv<vl>;
using vvvvl = vv<vvl>;
using vs = vc<string>;
using vvs = vv<string>;

int main(){
    int N,M;
    cin >> N >> M;
    vl A(N);
    for(int i = 0;i < N;i++){
        cin >> A[i];
    }
    vl B(M);
    for(int i = 0;i < M;i++){
        cin >> B[i];
    }
    int j = 0;
    int i = 0;
    while(1){
        if(A[i] == B[j]){
            A.erase(A.begin() + i);
            j++;
        }else i++;
        if(i == N || j == M)break;
    }
    for(int i = 0;i < N;i++){
        cout << A[i] << " ";
    }
    // 問題文を挿入
    return 0;
}