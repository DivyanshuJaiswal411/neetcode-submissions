class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;

        vector<std::pair<int, double>> cars(n);
        for (int i = 0; i < n; i++) {
            double timeToTarget = (double)(target - position[i]) / speed[i];
            cars[i] = {position[i], timeToTarget};
        }
        sort(cars.begin(), cars.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });

        stack<double> st;

        for (int i = 0; i < n; i++) {
            double currentTime = cars[i].second;
            if (st.empty() || currentTime > st.top()) {
                st.push(currentTime);
            }
        }

        return st.size();

    }
};
