#include <iostream>
#include <vector>
#include <algorithm>

bool Solve(std::vector<int>& nums, std::vector<int>& subsets, int targetSum, int index)
{
    if (index == nums.size())
    {
        for (auto subset : subsets)
            if (subset != targetSum)
                return false;
        return true;
    }

    for (int i = 0; i < subsets.size(); i++)
    {
        if (subsets[i] + nums[index] <= targetSum)
        {
            subsets[i] += nums[index];
            if (Solve(nums, subsets, targetSum, index + 1))
                return true;
            subsets[i] -= nums[index];
            if (subsets[i] == 0)
                return false;
        }
    }
    return false;
}

bool Partition3Subsets(std::vector<int>& nums)
{
    if (nums.size() < 3)
        return false;
    int sum = 0;
    for (auto num : nums)
        sum += num;
    if (sum % 3)
        return false;

    std::vector<int> subsets(3, 0);
    sort(nums.rbegin(), nums.rend());
    return Solve(nums, subsets, sum / 3, 0);
}

int main()
{
    int n;
    std::cin>>n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; i++)
        std::cin>>nums[i];
    std::cout<<Partition3Subsets(nums);
    return 0;
}
