#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <ctime>
#include <vector>
using namespace std;

inline int binpow (int a, int n) {
    if (n == 0)
		return 1;
	if (n % 2 == 1)
		return binpow (a, n-1) * a;
	else {
		int b = binpow (a, n/2);
		return b * b;
	}
}

int     main()
{
    
    srand((int)time(0));
    vector<int> arr;
        for(int i = 0; i < 10e8; i++) {
            arr.push_back(1+rand()%9);
        }

    unsigned int start = clock();
    int n = 1;

    for (auto i : arr) {
            n = 1+rand()%5;
            binpow(i,n);
            
        }
    

    unsigned int end = clock();
    unsigned int t = (end - start);
    cout << t;
}