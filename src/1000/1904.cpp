#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <string>

using namespace std;

int db[1000001];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    db[1] = 1;
    db[2] = 2;
    
    int N;
    cin >> N;
    
    for(int i=3; i<=N; i++) {
        db[i] = 0;
        db[i] += db[i - 2] * 2; // 전전 개수 * 앞,뒤(2)
        db[i] += (db[i - 1] - db[i - 2]);
        db[i] = db[i] % 15746;
    }
    
    cout << db[N];

    return 0;
}
