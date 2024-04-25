class Tuple {
public:
	long long int len;
	long long int si;
	string s;
};

class Solution {
public:
	string decodeAtIndex(string s, int k) {
		long long len = 0;
		stack<Tuple> stck;
		Tuple t {0, 0, ""};

		for (int i = 0; i < s.size(); ++i)
		{
			if (isalpha(s[i])) {
				t.s += s[i];
				len++;

				if (len == k) return string(1, s[i]);
			}
			else {
				int digit = s[i] - '0';
				len = len * digit;
				t.len = len;
				stck.push(t);

				if (len > k) break;
				t.si = len;
				t.s = "";

			}
		}

		while (!stck.empty()) {
			Tuple t = stck.top();
			stck.pop();

			k %= (t.si + t.s.size());
			if (k == 0) k = t.si + t.s.size();
			if (t.si < k) return string(1, t.s[k - t.si - 1]);
		}
		return "";
	}
};


















