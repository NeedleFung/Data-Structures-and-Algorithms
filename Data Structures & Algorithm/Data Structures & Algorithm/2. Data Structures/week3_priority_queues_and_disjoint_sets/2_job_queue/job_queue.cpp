#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using std::vector;
using std::cin;
using std::cout;
using std::priority_queue;
using std::pair;
using std::greater;

class JobQueue
{
private:
    int num_workers_;
    vector<int> jobs_;

    vector<int> assigned_workers_;
    vector<long long> start_times_;

    void WriteResponse() const
    {
        for (int i = 0; i < jobs_.size(); ++i)
        {
            cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
        }
    }

    void ReadData()
    {
        int m;
        cin >> num_workers_ >> m;
        jobs_.resize(m);
        for(int i = 0; i < m; ++i)
            cin >> jobs_[i];
    }

    void AssignJobs()
    {
        //TODO: replace this code with a faster algorithm
        /*
        assigned_workers_.resize(jobs_.size());
        start_times_.resize(jobs_.size());
        vector<long long> next_free_time(num_workers_, 0);
        for (int i = 0; i < jobs_.size(); ++i)
        {
            int duration = jobs_[i];
            int next_worker = 0;
            for (int j = 0; j < num_workers_; ++j)
            {
                if (next_free_time[j] < next_free_time[next_worker])
                    next_worker = j;
            }
            assigned_workers_[i] = next_worker;
            start_times_[i] = next_free_time[next_worker];
            next_free_time[next_worker] += duration;
        }
        */
        assigned_workers_.resize(jobs_.size());
        start_times_.resize(jobs_.size());

        // Create a priority queue of workers
        auto comparator = [](const pair<int, long long>& left, const pair<int, long long>& right)
        {
            if (left.second == right.second)
            {
                return left.first > right.first; // Use index as tie-breaker
            }
            return left.second > right.second; // Prioritize based on finish_time
        };
        priority_queue<pair<int, long long>, vector<pair<int, long long>>, decltype(comparator)> workers(comparator);
        for (int i = 0; i < num_workers_; ++i)
        {
            workers.push({i, 0});
        }

        for (int i = 0; i < jobs_.size(); ++i)
        {
            int duration = jobs_[i];
            auto next_worker = workers.top();
            workers.pop();

            assigned_workers_[i] = next_worker.first;
            start_times_[i] = next_worker.second;

            next_worker.second += duration;
            workers.push(next_worker);
        }
    }

public:
    void Solve()
    {
        ReadData();
        AssignJobs();
        WriteResponse();
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    JobQueue job_queue;
    job_queue.Solve();
    return 0;
}
