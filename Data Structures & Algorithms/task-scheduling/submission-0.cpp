class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::unordered_map<char, int> freq;
        int max_freq = 0;

        for (char task : tasks) {
            freq[task]++;
            max_freq = std::max(max_freq, freq[task]);
        }

        int max_count = 0;
        for (auto& [task, count] : freq) {
            if (count == max_freq) {
                max_count++;
            }
        }

        int min_time = (max_freq - 1) * (n + 1) + max_count;
        return std::max((int)tasks.size(), min_time);
    }
};
