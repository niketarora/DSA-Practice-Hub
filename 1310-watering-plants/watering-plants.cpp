class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int i = 0;
        int res = 0;

        while (i < plants.size()) {
            int cap = capacity;

            res += i + 1;
            cap -= plants[i];
            i++;
            while (i < plants.size() && cap >= plants[i]) {
                res++;
                cap -= plants[i];
                i++;
            }
            if (i < plants.size()) {
                res += i;
            }
        }

        return res;
    }
};
