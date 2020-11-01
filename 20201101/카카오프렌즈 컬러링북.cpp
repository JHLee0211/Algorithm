#include <bits/stdc++.h> 

using namespace std;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int M, N;
int sum;
int cur_color;
void res(vector<vector<int>> &picture, vector<vector<int>> &map, int m, int n) {

	map[m][n] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = m + dx[i];
		int ny = n + dy[i];

		if (nx<0 || ny<0 || nx >= M || ny >= N) {
			continue;
		}  
		if ((picture[nx][ny]==cur_color) && map[nx][ny]==0) {   
			sum++;
			res(picture,map, nx, ny);
		}
	}
	return;
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	M = m;
	N = n;
	vector<vector<int> > map(m, vector<int>(n, 0));
	int buf = 0;
	int ans = 0;
	for (int i = 0; i<m; i++) {
		for (int j = 0; j<n; j++) {
			if (map[i][j] == 0 && picture[i][j]>0) {
				buf++;
				sum = 1;
				cur_color = picture[i][j];
				cout << "test is : " << i << " " << j << " "<<cur_color<<endl;
				res(picture,map, i, j);
				ans = max(ans, sum);
			}
		}
	}
	answer[0] = buf;
	answer[1] = ans; 
	return answer;
}