int recursion(vector<int> &nums, int i, int j)

{

    if (i > j)

        return 0;

    int choice1 = nums[i] + min(recursion(nums, i + 2, j), recursion(nums, i + 1, j - 1));

    int choice2 = nums[j] + min(recursion(nums, i + 1, j - 1), recursion(nums, i, j - 2));

    return max(choice1, choice2);

}

bool PredictTheWinner(vector<int>& nums)

{

    int n = nums.size();

    int bestScore = recursion(nums, 0, n - 1);

    int sum = 0;

    for (int i = 0; i < n; i++) sum += nums[i];

    if (bestScore >= sum - bestScore)

        return true;

    return false;

}