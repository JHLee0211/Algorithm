#include <iostream>
#include <cstring> //memset

using namespace std;

const int MAX = 1000 + 1;
const int MOD = 1000000003;

int N, K;

long long cache[MAX][MAX];
void preCalculate(void)

{

	//N>=4�̹Ƿ� N=1, 2, 3�� ���� ���� �ϳ� ������ ��� �̸� ����

	for (int i = 1; i <= 3; i++)

		cache[i][1] = i;



	for (int i = 4; i <= N; i++)

	{

		int maxChoose = i / 2; //2���� �ǳʶپ�� ���� �ִ� ����

		for (int choose = 1; choose <= maxChoose; choose++)
		{

			if (choose == 1) //���� �ϳ��� ���� ���                  

				cache[i][choose] = i;

			else

				//������ �����ϴ� ���(��ĭ �ǳ� �پ� �̵�)�� �������� �ʴ� ���(��ĭ �̵�)

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

