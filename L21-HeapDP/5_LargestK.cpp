class Solution {
public:

	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int> > q;

		// for each
		for (int element : nums) {
			if (q.size() < k) {
				q.push(element);
			}
			else {
				if (q.top() < element) {
					q.pop();
					q.push(element);
				}
			}
		}
		return q.top();
	}
};