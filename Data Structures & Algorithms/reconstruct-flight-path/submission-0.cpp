class Solution {
public:
    unordered_map<string, multiset<string>> graph;
    vector<string> path;

    void solve(string airport) {

        while (graph[airport].size() > 0) {

            string nextAirport = *graph[airport].begin();

            graph[airport].erase(graph[airport].begin());

            solve(nextAirport);
        }

        path.push_back(airport);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {

        for (int i = 0; i < tickets.size(); i++) {
            graph[tickets[i][0]].insert(tickets[i][1]);
        }

        solve("JFK");

        reverse(path.begin(), path.end());

        return path;
    }
};