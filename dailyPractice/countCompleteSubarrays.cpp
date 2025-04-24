#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
bool isEqual(unordered_map<int, int> &mp, unordered_map<int, int> &curMp)
{

    return mp.size() == curMp.size();
}
int countCompleteSubarrays(vector<int> &nums)
{
    int flag = 0, curIndex, numsLength = nums.size(), cnt = 0, headIndex = 0;
    unordered_map<int, int> mp, curMp;
    for (int num : nums)
    {
        if (mp.find(num) == mp.end())
        {
            flag++;
        }
        mp[num]++;
    }
    for (int i = 0; i < flag; i++)
    {
        curMp[nums[i]]++;
    }
    curIndex = flag;
    while (curIndex <= nums.size())
    {
        if (isEqual(mp, curMp))
        {
            cnt += numsLength - curIndex + 1;
            curMp[nums[headIndex]]--;
            headIndex++;
            if (curMp[nums[headIndex - 1]] == 0)
            {
                curMp.erase(nums[headIndex - 1]);
            }
            continue;
        }
        if (curIndex == numsLength)
        {
            break;
        }
        curMp[nums[curIndex]]++;
        curIndex++;
    }
    return cnt;
}
int main()
{
    vector<int> nums = {5, 5, 5, 5};
    cout << countCompleteSubarrays(nums) << endl;
    return 0;
}