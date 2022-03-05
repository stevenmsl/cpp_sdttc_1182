#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>
#include <functional>
#include <math.h>

using namespace sol1182;
using namespace std;

/*takeaways
  - to qualify for time complexity O(NlogN), we build a dictionary
    which use color as its key, and a list of indexes of that
    color in the colors vector as its value. The list is sorted
    because of how we populated it.
  - We then use lower_bound to find the closest index. The time
    complexity for lower_bound is O(logN)
*/

vector<int> Solution::shortest(vector<int> &colors, vector<vector<int>> &queries)
{

  /*lower_bound
    - returns an iterator to the first element in the range which does
      not compare less than target
    - nums needs to be sorted in ascending order
  */
  auto closet = [](vector<int> &nums, int target)
  {
    auto pos = lower_bound(nums.begin(), nums.end(), target) -
               nums.begin();
    if (pos == 0)
      return nums[pos];
    if (pos == nums.size())
      return nums[pos - 1];

    /*
      - example [4,7,8]
      - if you are looking for the value that is closest to 5
        the lower_bound will return you 7 but its implementation
        as 7 is the first element not less than 5 than can be
        found
      - so you need to check the previous one, which is 4, to
        see which one is closer to 5
    */
    if (nums[pos] - target < target - nums[pos - 1])
      return nums[pos];
    return nums[pos - 1];
  };

  /*dictionary to speed up the searching process
    - key is the color
    - value is a list of indexes of that color
      in the color vector
  */
  auto dict = unordered_map<int, vector<int>>();
  const int n = colors.size();
  for (auto i = 0; i < n; i++)
    dict[colors[i]].push_back(i);

  auto result = vector<int>();
  for (auto query : queries)
  {
    auto color = query[1];
    if (dict.count(color) == 0)
    {
      result.push_back(-1);
      continue;
    }
    auto target = query[0];
    auto index = closet(dict[color], target);
    /* we want the distance between them */
    result.push_back(abs(index - target));
  }
  return result;
}