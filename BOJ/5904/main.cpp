#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;
typedef long long dl;
dl N;
void Divide(int count) {
    int mid = 1 + count + 2;
    dl sum = 0ll;
    for (int i = 0; i < count; i++) {
        int tmp = 1 + i + 2;
        sum = sum * 2 + tmp;
    }
    // N이 현재 Divide 함수내에서, 중간값 이전일때
    if (N <= sum) {
        Divide(count - 1);
    }
    // N이 중간값 이전이 아니고, 중간값 사이에 존재할 때
    else if (N <= sum + mid) {
        if (N == sum + 1) {
            cout << 'm';
        }
        else cout << 'o';
    }
    // N이 중간값 이후에 존재할 때
    else {
        // N의 수를 재조정하고, 재귀함수를 호출한다. 
        // 중간값 이후에 N이 존재하며 재귀함수를 호출할 때 이전단계로 가므로.
        N -= (sum + mid);
        Divide(count - 1);
    }
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N;
    int count = 0;
    dl sum = 0ll;
    int cnt = 0;
    // S(x)에서 x를 찾는다. x== cnt
    while(1){
        int tmp = 1 + count + 2;
        sum = sum * 2 + tmp;
        if (N < sum) {
            break;
        }
        cnt++;
    }
    Divide(cnt);
    
}
