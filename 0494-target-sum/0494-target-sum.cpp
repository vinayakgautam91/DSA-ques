class Solution {
public:
    struct PairHash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };

    unordered_map<pair<int, int>, int, PairHash> dp;

    int recurse(vector<int>& nums, int target, int i, int curr) {
        if (i == nums.size()) {
            return curr == target;
        }

        pair<int, int> state = {i, curr};

        if (dp.find(state) != dp.end()) {
            return dp[state];
        }

        return dp[state] =
            recurse(nums, target, i + 1, curr + nums[i]) +
            recurse(nums, target, i + 1, curr - nums[i]);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        dp.clear();
        return recurse(nums, target, 0, 0);
    }
};