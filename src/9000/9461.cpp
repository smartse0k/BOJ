#include <iostream>
#include <vector>

using namespace std;

vector<long long> db;

long long P(const int n) {
    for(int i=db.size(); i<=n; i++) {
        db.push_back( db[i - 1] + db[i - 5] );
    }
    
    return db[n];
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    db.push_back(0);
    db.push_back(1);
    db.push_back(1);
    db.push_back(1);
    db.push_back(2);
    db.push_back(2);
    db.push_back(3);
    
    int T;
    cin >> T;
    
    for(int i=0; i<T; i++) {
        int N;
        cin >> N;
        
        cout << P(N) << "\n";
    }

    return 0;
}
