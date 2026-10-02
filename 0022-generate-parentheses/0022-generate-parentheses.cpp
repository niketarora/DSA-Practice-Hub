class Solution {
public:
    void generate(string s, int open, int close, int n, vector<string> &v){
        //base condition
        if(close == n){
            v.push_back(s);
            return;
        }
        if(open != n){
            generate(s+'(', open+1, close, n, v);
        }
        if(open>close){
            generate(s+')', open, close+1, n, v);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        generate("", 0, 0, n, v);
        return v;
    }
};