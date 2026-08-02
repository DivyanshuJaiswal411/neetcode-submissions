#include <vector>
#include <numeric>

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int total_gas = 0;
        int total_cost = 0;
        
        for (int i = 0; i < gas.size(); i++) {
            total_gas += gas[i];
            total_cost += cost[i];
        }

        // Impossible if total gas is less than total cost required
        if (total_gas < total_cost) return -1;

        int curr_tank = 0;
        int start_idx = 0;

        for (int i = 0; i < gas.size(); i++) {
            curr_tank += gas[i] - cost[i];
            
            // If tank drops below 0, reset start position to next station
            if (curr_tank < 0) {
                start_idx = i + 1;
                curr_tank = 0;
            }
        }

        return start_idx;
    }
};