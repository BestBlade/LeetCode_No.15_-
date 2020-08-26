/*----------------------------------------------------------------------|
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三	|
个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存|
在唯一答案。															|
																		|
 																		|
																		|
示例：																	|
																		|
输入：nums = [-1,2,1,-4], target = 1									|
输出：2																	|
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。						|
 																		|
																		|
提示：																	|
																		|
3 <= nums.length <= 10^3												|
-10^3 <= nums[i] <= 10^3												|
-10^4 <= target <= 10^4													|
																		|
来源：力扣（LeetCode）													|
链接：https://leetcode-cn.com/problems/3sum-closest						|
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。	|
-----------------------------------------------------------------------*/

/*	暴力破解O(N^3),三重循环
*	执行用时：232 ms, 在所有 C++ 提交中击败了8.16%的用户
*	内存消耗：10.2 MB, 在所有 C++ 提交中击败了35.87%的用户
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int>& nums, int target)
{
	int result = -100000;

	if (nums.size() < 3 || nums.size() > 1000 || target < -10000 || target>10000)
	{
		return false;
	}

	int length = nums.size();
	sort(nums.begin(), nums.end());

	for (int i = 0; i < length - 2; i++)
	{
		for (int j = i+1; j < length - 1;j++)
		{
			for (int k = j + 1; k < length; k++)
			{
				int sum = nums[i] + nums[j] + nums[k];
				int abs = (sum > target) ? sum - target : target - sum;

				int abs1 = (result > target) ? result - target : target - result;

				result = (abs < abs1) ? sum : result;

				if (result == target)
				{
					return result;
				}
			}
		}
	}
	return result;
}
int main()
{
	vector<int> nums = { -1,2,1,-4 };

	int target = 1;

	int result;

	result = threeSumClosest(nums, target);

	cout << result;
}