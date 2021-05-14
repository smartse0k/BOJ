#include <iostream>
#include <vector>

using namespace std;

int map[501][501];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    
    cin >> map[1][1];
    
    for(int y=2; y<=N; y++) {
        for(int x=1; x<=y; x++) {
            int N;
            cin >> N;
            
            int l = -1, r = -1;
            
            if(x != 0) {
                l = N + map[y - 1][x - 1];
            }
            
            if(x != y) {
                r = N + map[y - 1][x];
            }
            
            map[y][x] = (l > r) ? l : r;
        }
    }
    
    int result = 0;
    for(int i=1; i<=N; i++) {
        result = max(map[N][i], result);
    }
    
    cout << result;

    return 0;
}
