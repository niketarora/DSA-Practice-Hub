class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> numsA;
        vector<int> numsB(n,0);
        numsA.push_back(0);
        int count = 0;
        for(int i=0; i<n-1; i++){
            if(s[i] == 'b')   count++;
            numsA.push_back(count);
        }
        numsB[n-1] = 0;
        count = 0;
        for(int j=n-1; j>0; j--){
            if(s[j] == 'a')   count++;
            numsB[j-1] = count;
        }
        int sum = INT_MAX;
        for(int i=0; i<n; i++){
            int add = numsA[i] + numsB[i];
            if(add<sum) sum = add;
        }
        return sum;
    }
};