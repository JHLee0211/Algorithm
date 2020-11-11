#include <bits/stdc++.h>
using namespace std;

int solution(string str1, string str2)

{
    int size1, size2, ans = 65536;
    double all = 0, dup = 0; 
    map<string, int> map1;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    size1 = str1.size();
    size2 = str2.size();
    for (int i = 0; i < size1 - 1; i++) {
        if (str1[i] < 97 || str1[i] > 122)
            continue;
        if (str1[i + 1] < 97 || str1[i + 1] > 122)
            continue;
        string str;
        str = str1[i];
        str += str1[i + 1];
        all++;
        if (map1.count(str))
            map1[str]++;
        else
            map1[str] = 1;
    }
    for (int i = 0; i < size2 - 1; i++) {
        if (str2[i] < 97 || str2[i] > 122)
            continue;
        if (str2[i + 1] < 97 || str2[i + 1] > 122)
            continue;
        string str;
        str = str2[i];
        str += str2[i + 1];
        if (map1.count(str)) {
            if (map1[str] > 0) {
                map1[str]--;
                dup++;
            } else
                all++;
        } else
            all++;
    }

    if (all != 0)
        ans = (int)((double)ans * (dup / all));
    return ans;
}