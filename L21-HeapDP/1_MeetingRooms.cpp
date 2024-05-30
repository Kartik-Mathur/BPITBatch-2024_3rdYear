class Solution {
public:

	// static bool compare(vector<int> &a, vector<int> &b) {
	// 	return a[0] < b[0];
	// }

	static bool compare(vector<int> &a, vector<int> &b) {
		if (a[0] == b[0]) return a[1] < b[1];
		return a[0] < b[0];
	}

	int minMeetingRooms(vector<vector<int>>& meetings) {

		sort(meetings.begin(), meetings.end(), compare);

		priority_queue<int, vector<int>, greater<int> > q;

		for (int i = 0 ; i < meetings.size(); i++) {
			if (q.empty()) {
				// If koi room nhi liya hai abhi tak, simply end time ko
				// push krdo queue ke andar
				q.push(meetings[i][1]);
			}
			else {
				if (q.top() <= meetings[i][0]) {
					q.pop();
				}
				q.push(meetings[i][1]);
			}
		}

		return q.size();
	}
};