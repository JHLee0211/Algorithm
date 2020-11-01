#include bitsstdc++.h 
using namespace std;
  
int solution(int n, vectorvectorint data) {
	int answer = 0;
	vectorint x;
	vectorint y;
	setint x_set;
	setint y_set;
    vectorvectorint  S(n, vectorint(n, 0)); 
    
	for (int i = 0; i  data.size(); i++) {
		x_set.insert(data[i][0]);
		y_set.insert(data[i][1]);
	}  
	for (auto it = x_set.begin(); it != x_set.end(); it++) {
		x.push_back(it);
	}
	for (auto it = y_set.begin(); it != y_set.end(); it++) {
		y.push_back(it);
	}

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
 

	for (int i = 0; i  data.size(); i++) {
		for (int j = 0; j  data.size(); j++) {
			if (x[j] == data[i][0]) {
				data[i][0] = j;
				break;
			}
		}
	}
	for (int i = 0; i  data.size(); i++) {
		for (int j = 0; j  data.size(); j++) {
			if (y[j] == data[i][1]) {
				data[i][1] = j;
				break;
			}
		}
	}

 

	for (int i = 0; i  n; i++) {  
		S[data[i][0]][data[i][1]] = 1;
	}
    for (int i = 0; i  n; i++) {
        for (int j = 0; j  n; j++) {

            S[i][j] += (i - 1 = 0  S[i - 1][j]  0)
                    + (j - 1 = 0  S[i][j - 1]  0)
                    - (i - 1 = 0 && j - 1 = 0  S[i - 1][j - 1]  0);
        }
    }

 

	  int ans = 0;
     N^2 모든 쐐기 조합에 대하여 검사
    for (int i = 0; i  n; i++) {
        for (int j = i + 1; j  n; j++) {

             조건#1 검사  직사각형이 아닌 경우
            if (data[i][0] == data[j][0]  data[i][1] == data[j][1]) continue;

             조건#2 검사  내부에 쐐기가 존재하는 경우
            int startX, startY, endX, endY;

            startX =  min(data[i][0], data[j][0]);
            startY =  min(data[i][1], data[j][1]);
            endX =  max(data[i][0], data[j][0]);
            endY =  max(data[i][1], data[j][1]);

            int cnt;

            if (startX + 1  endX - 1  startY + 1  endY - 1) {

                cnt = 0;
            } else {

                cnt = S[endX - 1][endY - 1] - S[endX - 1][startY] - S[startX][endY - 1] + S[startX][startY];
            }

            if (cnt == 0) ans++;
        }
    }

    return ans;

 
}