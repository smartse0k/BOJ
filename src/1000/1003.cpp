#include <iostream>
#include <vector>

using namespace std;

vector<int> fibList;

int fibonacci(int n) {
    if(fibList.size() <= n) {
        fibList.push_back( fibonacci(n - 1) + fibonacci(n - 2) );
    }
    
    return fibList[n];
}

int getZero(int n) {
    if(n == 0) return 1;
    return fibonacci(n - 1);
}

int getOne(int n) {
    return fibonacci(n);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    fibList.push_back(0);
    fibList.push_back(1);
    
    int N;
    cin >> N;
    
    for(int i=0; i<N; i++) {
        int input;
        cin >> input;
        
        cout << getZero(input) << " " << getOne(input) << "\n";
    }


    return 0;
}
