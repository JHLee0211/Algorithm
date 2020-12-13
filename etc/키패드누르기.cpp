#include <string>
#include <vector>
#include <cmath>
using namespace std;

int xpos[10] = {2,1,2,3,1,2,3,1,2,3};
int ypos[10] = {1,4,4,4,3,3,3,2,2,2};

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int lxpos = 1, lypos = 1, rxpos = 3, rypos = 1;
    for(auto num : numbers) {
        if(num == 1 || num == 4 || num == 7) {
            lxpos = xpos[num];
            lypos = ypos[num];
            answer += 'L';
        }
        else if(num == 3 || num == 6 || num == 9) {
            rxpos = xpos[num];
            rypos = ypos[num];
            answer += 'R';
        }
        else {
            int ldis = abs(xpos[num] - lxpos) + abs(ypos[num] - lypos);
            int rdis = abs(xpos[num] - rxpos) + abs(ypos[num] - rypos);
            if(ldis < rdis) {
                lxpos = xpos[num];
                lypos = ypos[num];
                answer += 'L';
            }
            else if(ldis > rdis) {
                rxpos = xpos[num];
                rypos = ypos[num];
                answer += 'R';
            }
            else {
                if(hand == "left") {
                    lxpos = xpos[num];
                    lypos = ypos[num];
                    answer += 'L';
                }
                else {
                    rxpos = xpos[num];
                    rypos = ypos[num];
                    answer += 'R';
                }
            }
            
        }
    }
    return answer;
}