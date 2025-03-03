// O(n) approach , space = O(n)
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        // Extra space approach

        vector<int> less, piv, greater;

        for (int num : nums) {
            if (num < pivot)
                less.push_back(num);
            else if (num == pivot)
                piv.push_back(num);
            else
                greater.push_back(num);
        }

        // Sorting before inserting
        // sort(less.begin(), less.end());
        // sort(greater.begin(), greater.end());

        vector<int> result;
        result.insert(result.end(), less.begin(), less.end());
        result.insert(result.end(), piv.begin(), piv.end());
        result.insert(result.end(), greater.begin(), greater.end());

        return result;
    }
};

