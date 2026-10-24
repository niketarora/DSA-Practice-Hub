class Solution {
public:
    int calDay(string day, const vector<int> &prefixSum){
        int month = stoi(day.substr(0,2));
        int date = stoi(day.substr(3));
        return prefixSum[month -1] + date;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> dateofmonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> prefixSum = {0};
        for(int ele : dateofmonth){
            prefixSum.push_back(prefixSum.back() + ele);
        }
        int arrAlice = calDay(arriveAlice, prefixSum);
        int lAlice = calDay(leaveAlice, prefixSum);
        int arrBob = calDay(arriveBob, prefixSum);
        int lBob = calDay(leaveBob, prefixSum);

        return max(0, min(lAlice, lBob) - max(arrAlice, arrBob) + 1);
    }
};