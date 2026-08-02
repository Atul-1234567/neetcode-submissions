class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        for (int start = 0; start < n; start++) {

            int tank = gas[start];
            int i = start;

            while (true) {

                tank -= cost[i];

                if (tank < 0)
                    break;

                i = (i + 1) % n;

                if (i == start)
                    return start;

                tank += gas[i];
            }
        }

        return -1;
    }
};