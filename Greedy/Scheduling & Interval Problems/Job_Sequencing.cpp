#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;
    int deadline;
    int profit;
};

bool comparison(Job first, Job second)
{
    return first.profit > second.profit;
}

// T.C -> O(N log N + N * M), S.C -> O(M).
vector<int> jobScheduling(Job jobs[], int n)
{
    sort(jobs, jobs + n, comparison);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
    {
        if (jobs[i].deadline > maxDeadline)
        {
            maxDeadline = jobs[i].deadline;
        }
    }

    vector<int> timeline(maxDeadline + 1, -1);
    int countJobs = 0;
    int totalProfit = 0;
    for (int i = 0; i < n; i++)
    {
        for (int slot = jobs[i].deadline; slot > 0; slot--)
        {
            if (timeline[slot] == -1)
            {
                timeline[slot] = jobs[i].id;
                countJobs++;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }
    return {countJobs, totalProfit};
}

int main()
{
    Job jobs[] = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15}};
    int n = sizeof(jobs) / sizeof(jobs[0]);

    vector<int> result = jobScheduling(jobs, n);
    cout << result[0] << ' ' << result[1] << '\n';
    return 0;
}