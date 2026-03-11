class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)    return 1;

        string binary = "";
        while(n>0){
            char ans = n%2;
            n /= 2;
            binary = ans + binary;
        }
        int s = binary.size();
        string res = "";
        for(int i=0; i<s; i++){
            if(binary[i]==1)    res += '0';
            else    res += '1';
        }
        return stoi(res, nullptr, 2);;
    }
};