class Solution {
public:
    vector<vector<int>> ans;
    vector<int> combin;

    void getAllCombinations(vector<int>& candidates, int idx, int target) {

        if (target == 0) {
            ans.push_back(combin);
            return;
        }

        if (target < 0 || idx >= candidates.size()) {
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {

            if (i > idx && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break;

         
            combin.push_back(candidates[i]);

           
            getAllCombinations(candidates, i + 1, target - candidates[i]);

            combin.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        ans.clear();
        combin.clear();

        getAllCombinations(candidates, 0, target);

        return ans;
    }
};