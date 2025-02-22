#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the next day's attendance
vector<bool> calculateNextDay(const vector<bool>& currentStatus, const vector<vector<int>>& friends) {
    int n = currentStatus.size();
    vector<bool> nextStatus(n, false);

    for (int i = 0; i < n; ++i) {
        int wfoFriends = 0;
        for (int friendID : friends[i]) {
            if (currentStatus[friendID]) {
                ++wfoFriends;
            }
        }

        if (currentStatus[i]) {
            // Rule for WFO to continue WFO
            nextStatus[i] = (wfoFriends == 3);
        } else {
            // Rule for WFH to switch to WFO
            nextStatus[i] = (wfoFriends < 3);
        }
    }

    return nextStatus;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Read friendships
    vector<vector<int>> friends(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        friends[u].push_back(v);
        friends[v].push_back(u);
    }

    int k;
    cin >> k;

    // Day 1: All employees are working from office
    vector<bool> currentStatus(n, true);
    int rosteringValue = n;
    int days = 1;

    while (rosteringValue < k) {
        currentStatus = calculateNextDay(currentStatus, friends);

        // Calculate rostering value for the current day
        int dailyAttendance = 0;
        for (bool status : currentStatus) {
            if (status) {
                ++dailyAttendance;
            }
        }

        rosteringValue += dailyAttendance;
        ++days;
    }

    cout << days << endl;

    return 0;
}
