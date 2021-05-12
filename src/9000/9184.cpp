#include <iostream>
#include <vector>
#include <utility>
#include <map>

using namespace std;

map< tuple<int, int, int>, int > db;

int w(int a, int b, int c) {
    //cout << "run " << a << " " << b << " " << c << "\n";
    
    if(a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    
    if(a > 20 || b > 20 || c > 20) {
        return w(20, 20, 20);
    }
    
    tuple<int, int, int> key = {a, b, c};
    auto findRow = db.find(key);
    if( findRow != db.end() ) {
        return findRow->second;
    }
    
    int result = 1;
    
    if(a < b && b < c) {
        result = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        db.insert({key, result});
        return result;
    }
    
    result = w(a - 1, b, c)
            + w(a - 1, b - 1, c) 
            + w(a - 1, b, c - 1) 
            - w(a - 1, b - 1, c - 1);
    db.insert({key, result});
    return result;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int A, B, C;
    
    while(true) {
        cin >> A >> B >> C;
        
        if(A == -1 && B == -1 && C == -1) {
            break;
        }
        
        cout << "w(" << A << ", " << B << ", " << C << ") = ";
        cout << w(A, B, C) << "\n";
    }

    return 0;
}
