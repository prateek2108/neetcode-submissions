class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // X -> Y -> idle -> X -> Y | k ~ 10^5
        int k = tasks.size();
        unordered_map<char, int> mp;
        int maxF = 0, cnt = 0;

        for (char x : tasks)
            mp[x]++;

        for (auto x : mp)
            maxF = max(x.second, maxF);

        for (auto x : mp) {
            if (x.second == maxF)
                cnt += 1;
        }

        // idle spaces required = (maxF - 1) * n
        // (maxF - 1) slots of n spaces => count no of distinct elements

        return max(maxF + (maxF - 1) * n + (cnt - 1), k);
    }
};
