class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();
        int total = 0;
        for(int i=0; i<n; i++){
            total += apple[i];
        }
        sort(capacity.begin(), capacity.end(),  greater<int>());
        int count = 0;
        for(int j=0; j<m; j++){
            total -= capacity[j];
            count++;
            if(total<=0)    return count;
        }
        return count;
    }
};