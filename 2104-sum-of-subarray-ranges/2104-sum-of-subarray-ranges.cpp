#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> findpge(const vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<pair<int, int>> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top().second <= nums[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? -1 : st.top().first;
            st.push({i, nums[i]});
        }

        return ans;
    }

    vector<int> findnge(const vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<pair<int, int>> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top().second < nums[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? n : st.top().first;
            st.push({i, nums[i]});
        }

        return ans;
    }

    vector<int> findpse(const vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<pair<int, int>> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top().second >= nums[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? -1 : st.top().first;
            st.push({i, nums[i]});
        }

        return ans;
    }

    vector<int> findnse(const vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<pair<int, int>> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top().second > nums[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? n : st.top().first;
            st.push({i, nums[i]});
        }

        return ans;
    }

    long long allLargest(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        vector<int> nge = findnge(nums);
        vector<int> pge = findpge(nums);

        for (int i = 0; i < n; i++) {
            ans += 1LL * nums[i] *
                   (nge[i] - i) *
                   (i - pge[i]);
        }

        return ans;
    }

    long long allSmallest(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        vector<int> nse = findnse(nums);
        vector<int> pse = findpse(nums);

        for (int i = 0; i < n; i++) {
            ans += 1LL * nums[i] *
                   (nse[i] - i) *
                   (i - pse[i]);
        }

        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        return allLargest(nums) - allSmallest(nums);
    }
};