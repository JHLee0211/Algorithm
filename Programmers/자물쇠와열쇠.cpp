/*
 - https://programmers.co.kr/learn/courses/30/lessons/60059
*/
#include <string>
#include <vector>
using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int M = key.size(), N = lock.size();
    vector<vector<int>> map(2 * (M - 1) + N, vector<int>(2 * (M - 1) + N, 2));
    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            map[i + M - 1][j + M - 1] = lock[i][j];
        }
    }

    for(int r = 0 ; r < 4 ; r++){
        //rotate 90
        vector<vector<int>> cpykey(M, vector<int>(M, 0));
        for(int i = 0 ; i < M ; i++){
            for(int j = 0 ; j < M ; j++){
                cpykey[i][j] = key[M- 1 - j][i];
            }
        }
        key = cpykey;
        
        for(int i = 0 ; i < N + M - 1 ; i++){
            for(int j = 0 ; j < N + M - 1 ; j++){
                vector<vector<int>> tmp = map;
                for(int k = 0 ; k < M ; k++){
                    for(int l = 0 ; l < M ; l++){
                        tmp[i + k][j + l] ^= key[k][l];
                    }
                }           
                
                bool success = true;
                for(int i = 0 ; i < N ; i++){
                    for(int j = 0 ; j < N ; j++){
                        if(tmp[i + M - 1][j + M - 1] == 0){
                            success = false;
                            i = N;
                            break;
                        }
                    }
                }
                
                if(success){
                    return true;
                }
            }
        }
    }
    return answer;
}