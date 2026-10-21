// Linear Search
// class Solution {
// public:
//     int peakIndexInMountainArray(vector<int>& arr) {
//         int n = arr.size();
//         for (int i = 0; i < n - 1; ++i) {
//             if (arr[i] > arr[i + 1]) {
//                 return i;
//             }
//         }
//         return 0;
//     }
// };

// Binary Search
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int left = 0;
        int right = n - 1;

        while(left < right){
            int mid = left + (right - left) / 2;

            if(arr[mid] < arr[mid + 1])
                left = mid + 1;
            else
                right = mid;
        }

        return left;
    }
};