#include <iostream>
#include <cstring> //memset

using namespace std;

const int MAX = 1000 + 1;
const int MOD = 1000000003;

int N, K;

long long cache[MAX][MAX];
void preCalculate(void)

{

	//N>=4이므로 N=1, 2, 3에 대해 색상 하나 선택할 경우 미리 정의

	for (int i = 1; i <= 3; i++)

		cache[i][1] = i;



	for (int i = 4; i <= N; i++)

	{

		int maxChoose = i / 2; //2개씩 건너뛰어야 색상 최대 선택

		for (int choose = 1; choose <= maxChoose; choose++)
		{

			if (choose == 1) //색상 하나를 택할 경우                  

				cache[i][choose] = i;

			else

				//색상을 선택하는 경우(한칸 건너 뛰어 이동)와 선택하지 않는 경우(한칸 이동)

				cache[i][choose] = (cache[i - 2][choose - 1] + cache[i - 1][choose]) % MOD;

		}

	}

}


int main(void)

{

	cin >> N >> K;



	preCalculate();



	cout << cache[N][K] << endl;

	return 0;

}

