/*
  题目：
  我们有一个由平面上的点组成的列表 points。需要从中找出 K 个距离原点 (0, 0) 最近的点。
  （这里，平面上两点之间的距离是欧几里德距离。）
  你可以按任何顺序返回答案。除了点坐标的顺序之外，答案确保是唯一的。

  示例 1：
  输入：points = [[1,3],[-2,2]], K = 1
  输出：[[-2,2]]
  解释： 
  (1, 3) 和原点之间的距离为 sqrt(10)，
  (-2, 2) 和原点之间的距离为 sqrt(8)，
  由于 sqrt(8) < sqrt(10)，(-2, 2) 离原点更近。
  我们只需要距离原点最近的 K = 1 个点，所以答案就是 [[-2,2]]。

  示例 2：
  输入：points = [[3,3],[5,-1],[-2,4]], K = 2
  输出：[[3,3],[-2,4]]
  （答案 [[-2,4],[3,3]] 也会被接受。）
  
  提示：
  1 <= K <= points.length <= 10000
  -10000 < points[i][0] < 10000
  -10000 < points[i][1] < 10000

  参考：
  https://leetcode-cn.com/problems/k-closest-points-to-origin/solution/c-xiao-gen-dui-by-0x404/
*/
class Solution
{
public:
    struct Point
    {
        int x;
        int y;
        Point(const int _x, const int _y) : x(_x), y(_y)
        {
        }
        bool operator<(const Point &pt2) const
        {
            return sqrt(x * x + y * y) > sqrt(pt2.x * pt2.x + pt2.y * pt2.y);
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {
        priority_queue<Point> pq;
        for (int i = 0; i < points.size(); i++)
        {
            Point pt(points[i][0], points[i][1]);
            pq.push(pt); // 每push一个元素都会做一次堆结构的调整
        }

        vector<vector<int>> res;
        for (int i = 1; i <= K; i++)
        {
            res.push_back(vector<int>{pq.top().x, pq.top().y});
            pq.pop();
        }
        return res;
    }
};
