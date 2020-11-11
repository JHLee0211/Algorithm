#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class traffic {
public:
    double start, end;

    traffic();
    traffic(double start, double end) : start(start), end(end) {} ;
    traffic(string log) {
        double hour = stoi(log.substr(11, 2)),
               minute = stoi(log.substr(14, 2)),
               sec = stod(log.substr(17, 6)),
               elapsed_time = stod(log.substr(24, log.size() - 24));

        end = hour * 3600L + minute * 60L + sec;
        start = end - elapsed_time + .001L;
    }
};

bool isOverlapped(traffic left, traffic right) {
    if ((left.start < right.end || fabs(left.start - right.end) < .001L) &&
        (right.start < left.end || fabs(right.start - left.end) < .001L))
        return true;
    return false;
}

int getMaximumPayload(vector<traffic> & v) {
    int maxPayload = 0;
    for (int x = 0; x < v.size(); x++) {
        int payloadLeft = 0, payloadRight = 0;

        traffic lRange(v[x].start - .999L, v[x].start);
        traffic rRange(v[x].end, v[x].end + .999L);

        for (int y = 0; y < v.size(); y++) {

            // 왼쪽
            if (isOverlapped(lRange, v[y])) 
                payloadLeft++;            

            // 오른쪽
            if (isOverlapped(rRange, v[y])) 
                payloadRight++;

        }
        maxPayload = max(maxPayload, payloadLeft);
        maxPayload = max(maxPayload, payloadRight);
    }
    return maxPayload;
}
int solution(vector<string> lines) {
    vector<traffic> logs;

    for (auto& line : lines) {
        traffic log(line);
        logs.push_back(log);
    }

    return getMaximumPayload(logs);
}