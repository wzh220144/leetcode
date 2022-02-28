class Solution {
public:

    struct Job {
        int32_t start_time;
        int32_t end_time;
        int32_t profit;
    };

    int32_t search(vector<Job>& jobs, int32_t target) {
        int32_t low = 0;
        int32_t high = jobs.size() - 1;
        while(low <= high) {
            int32_t mid = low + ((high - low) >> 1);
            if (jobs[mid].start_time >= target) {
                if (mid == 0 || jobs[mid - 1].start_time < target) {
                    return mid;
                }
                high = mid - 1;
            } else if (jobs[mid].start_time < target) {
                low = mid + 1;
            }
        }
        return -1;
    }

    int32_t dfs(int32_t index, vector<Job>& jobs, vector<int32_t>& dp) {
        if (dp[index] >= 0) {
            return dp[index];
        }
        int32_t i = search(jobs, jobs[index].end_time);
        dp[index] = std::max(0, jobs[index].profit);
        for(; i < jobs.size(); ++i) {
            if (dp[i] >= 0) {
                dp[index] = std::max(jobs[index].profit + dp[i], dp[index]);
                break;
            } else {
                dp[index] = std::max(dp[index], jobs[index].profit + dfs(i, jobs, dp));
            }
        }
        if (index + 1 < jobs.size()) {
            dp[index] = std::max(dp[index], dfs(index + 1, jobs, dp));
        }
        return dp[index];
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<Job> jobs;
        vector<int32_t> dp;
        for (int32_t i = 0; i < startTime.size(); ++i) {
            Job job;
            job.start_time = startTime[i];
            job.end_time = endTime[i];
            job.profit = profit[i];
            jobs.emplace_back(std::move(job));
            dp.emplace_back(-1);
        }
        std::sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
            if (a.start_time == b.start_time) {
                return a.end_time < b.end_time;
            }
            return a.start_time < b.start_time;
        });
        return dfs(0, jobs, dp);
    }
};