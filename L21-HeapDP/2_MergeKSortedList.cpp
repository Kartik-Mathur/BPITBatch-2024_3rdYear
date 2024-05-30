#define node ListNode
class Solution {
public:

	node* mergeKLists(vector<node*>& lists) {

		priority_queue<pair<int, node*>, vector<pair<int, node*>>,
		               greater<pair<int, node*>> > q;

		for (int i = 0; i < lists.size(); ++i) {
			if (list[i]) {
				q.push({list[i]->val, list[i]});
			}
		}

		node* head = NULL, *tail = NULL;
		while (!q.empty()) {
			pair<int, node*> x = q.top();
			q.pop();
			if (!head) {
				head = tail = x.second;
			}
			else {
				tail->next = x.second;
				tail = tail->next;
			}

			if (tail->next) {
				q.push({tail->next->val, tail->next});
			}
			tail->next = NULL;

		}

		return head;

	}
};