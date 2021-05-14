#include <iostream>
#include <vector>

using namespace std;

long long sum = 0;
long long db[101][10] = {0, };

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    
    for(int i=1; i<10; i++) {
        db[1][i] = 1;
    }
    
    for(int i=2; i<=N; i++) {
    	for(int jj=0; jj<10; jj++) {
    		long long lastCount = db[i - 1][jj]; 
    	
	    	switch(jj) {
	    		case 0:
	    			db[i][1] += lastCount % 1000000000;
	    			break;
	    		case 9:
	    			db[i][8] += lastCount % 1000000000;
	    			break;
	    		default:
	    			db[i][jj-1] += lastCount % 1000000000;
	    			db[i][jj+1] += lastCount % 1000000000;
	    			break;
			}
		}
    }
    
    for(int i=0; i<10; i++) {
    	long long count = db[N][i];
    	//cout << count << "\n";
    	sum += db[N][i];
	}
	
	sum %= 1000000000;
    
    cout << sum;

    return 0;
}
