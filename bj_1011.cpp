//0~3: 1 1 1 
//0~4: 1 2 1
//0~5: 1 2 1 1
//0~6: 1 2 2 1
//0~7: 1 2 2 1 1
//0~8: 1 2 2 2 1 
//0~9: 1 2 3 2 1
//0~16:1 2 3 4 3 2 1
//0~20:1 2 3 4 4 3 2 1
//0~21:1 2 3 4 4 3 2 1 1
//0~25:1 2 3 4 5 4 3 2 1

#include <iostream>
#include <math.h>

using namespace std;
int main() {
	int N;
	cin >> N;
	int tmp_ans[5] = { -1,1,2,3,3};
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		b = b - a;
		a = 0;
		if (b <= 4) {
			cout << tmp_ans[b] << endl;
			continue;
		}
		
		double p;
		int sq_int;
		
		for (p = b-1 ; p >= 1; p--) {
			sq_int = sqrt(p);
			if (sqrt(p) == sq_int) {

				break;
			}
		}
		if (p + sq_int < b) {
			cout << 2 * sq_int+1 << endl;
		}
		else {
			cout << 2 * sq_int << endl;
		}
		
		

	}
	return 0;
}
