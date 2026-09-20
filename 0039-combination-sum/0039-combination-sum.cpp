class Solution {
public:
    void getAllCombinations(vector<int>& arr, int idx, int target,
                            vector<vector<int>>& ans,
                            vector<int>& combin) {

        if (target == 0) {
            ans.push_back(combin);
            return;
        }

        if (idx == arr.size() || target < 0) {
            return;
        }

        // Take current element
        combin.push_back(arr[idx]);
        getAllCombinations(arr, idx, target - arr[idx], ans, combin);
        combin.pop_back();

        // Skip current element
        getAllCombinations(arr, idx + 1, target, ans, combin);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combin;

        getAllCombinations(candidates, 0, target, ans, combin);

        return ans;
    }
};