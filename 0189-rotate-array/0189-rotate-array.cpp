class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        if(k > n)  k %= n;
        int j = n - k;
        while(j<n){
            ans.push_back(nums[j]);
            j++;
        }  
        j = n - k;
        for(int i=0; i<j; i++){
            ans.push_back(nums[i]);
        }  
        for(int i=0; i<nums.size();i++){
            nums[i] = ans[i];
        }
    }
};
// class Solution {
// public:
//     void display(vector<int> &a){
//     for(int i=0; i<a.size();i++){
//         cout<<a[i]<<" ";
//     }
//     cout<<endl;
//     }
//     void reversePart(int i, int j, vector<int> &a){
//         while(i<=j){
//             swap(a[i], a[j])
//             i++;
//             j--;
//         }
//     }
//     void rotate(vector<int>& nums, int k) {
//         int n = nums.size();
//         if (k>n) k=k%n;
//         reversePart(0,n-1-k,nums);
//         reversePart(n-k,n-1,nums);
//         reversePart(0,n-1,nums);
//         display(nums); 
//     }
// };