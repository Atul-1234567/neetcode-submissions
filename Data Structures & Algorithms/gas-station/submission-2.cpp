// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int fuel = 0, total = 0, start = 0;

//         for (int i = 0; i < gas.size(); i++) {
//             fuel += gas[i] - cost[i];
//             total += gas[i] - cost[i];

//             if (fuel < 0) {
//                 start = i + 1;
//                 fuel = 0;
//             }
//         }
//         if(total >= 0){
//             return start;
//         }
//         else{
//             return -1;
//         }
//     }
// };



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