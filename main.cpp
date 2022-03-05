#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1182;

/*
Example 1:
Input: colors = [1,1,2,1,3,2,2,3,3], queries = [[1,3],[2,2],[6,1]]
Output: [3,0,3]
Explanation:
The nearest 3 from index 1 is at index 4 (3 steps away).
The nearest 2 from index 2 is at index 2 itself (0 steps away).
The nearest 1 from index 6 is at index 3 (3 steps away).
*/
tuple<vector<int>, vector<vector<int>>, vector<int>>
testFixture1()
{
  auto colors = vector<int>{1, 1, 2, 1, 3, 2, 2, 3, 3};
  auto queries = vector<vector<int>>{{1, 3}, {2, 2}, {6, 1}};
  auto output = vector<int>{3, 0, 3};

  return make_tuple(colors, queries, output);
}

/*
Example 2:
Input: colors = [1,2], queries = [[0,3]]
Output: [-1]
Explanation: There is no 3 in the array.
*/
tuple<vector<int>, vector<vector<int>>, vector<int>>
testFixture2()
{
  auto colors = vector<int>{1, 2};
  auto queries = vector<vector<int>>{{0, 3}};
  auto output = vector<int>{-1};

  return make_tuple(colors, queries, output);
}
void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << Util::toString(get<2>(f)) << endl;
  auto result = Solution::shortest(get<0>(f), get<1>(f));
  cout << "result: " << Util::toString(result) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Test 2 - exepct to see " << Util::toString(get<2>(f)) << endl;
  auto result = Solution::shortest(get<0>(f), get<1>(f));
  cout << "result: " << Util::toString(result) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}