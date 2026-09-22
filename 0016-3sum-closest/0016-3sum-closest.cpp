class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int dif = INT_MAX;
        int ans = 0;
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == target)
                    return target;

                if (abs(sum - target) < dif) {
                    dif = abs(sum - target);
                    ans = sum;
                }

                if (sum > target)
                    k--;
                else
                    j++;
            }
        }

        return ans;
    }
};
