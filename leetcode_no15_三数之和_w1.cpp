/*----------------------------------------------------------------------|
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c 	|
，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。			|
																		|
注意：答案中不可以包含重复的三元组。									|
																		|
																		|
示例：																	|
																		|
给定数组 nums = [-1, 0, 1, 2, -1, -4]，									|
																		|
满足要求的三元组集合为：												|
[																		|
  [-1, 0, 1],															|
  [-1, -1, 2]															|
]																		|
																		|
来源：力扣（LeetCode）													|
链接：https://leetcode-cn.com/problems/3sum								|
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。	|
-----------------------------------------------------------------------*/

/*	排序双指针法
*
*	执行用时：104 ms, 在所有 C++ 提交中击败了71.19%的用户
*	内存消耗：19.9 MB, 在所有 C++ 提交中击败了40.65%的用户
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) 
{
	int length = nums.size();
	vector<vector<int>> result;
	int goal = { 0 };																/*	三个数和为0	*/

	if (nums.size() < 3)
	{
		return result;
	}

	sort(nums.begin(), nums.end());
	if (nums[0] > 0 || nums[nums.size() - 1] < 0)
	{
		return result;
	}

	for (int fir = 0; fir < length; fir++)
	{
		if (fir > 0 && nums[fir] == nums[fir - 1])									/*	确保第一个数和上次取的数不相同	*/
		{
			continue;
		}
		int thi = length - 1;
		int target = -nums[fir];
		for (int sec = fir + 1; sec < length; sec++)
		{
			if (sec > fir + 1 && nums[sec] == nums[sec - 1])						/*	当sec==fir+1的时候就不用判断nums[sec]和nums[sec-1]是否相同了，只有sec>fir+1的时候才要判断	*/
			{
				continue;
			}
			while (sec < thi && nums[sec] + nums[thi] > target)						/*	当sec==thi或者nums[sec]+nums[thi]<=-nums[fir]的时候退出循环	*/
			{																		/*	将thi倒着递减来不断缩小和减少程序运算步骤	*/
				thi--;
			}
			if (sec == thi)
			{
				break;
			}
			if (nums[sec] + nums[thi] == target)
			{
				result.push_back({ nums[fir],nums[sec],nums[thi] });
			}
		}

	}

	return result;
}

int main()
{

}