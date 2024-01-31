class Solution {
	int encode(string &word) {
		int code = 0;
		for (auto ch: word) {
			int id = ch - 'a';
			code = (code | (1 << id));
		}
		return code;
	}
public:
	int wordCount(vector<string> &startWords, vector<string> &targetWords) {
		unordered_map<int, bool> has;
		for (auto &word: startWords) {
			has[encode(word)] = true;
		}
		int answer = 0;
		for (auto &word: targetWords) {
			int len = (int) word.size();
			int code = encode(word);
			for (auto &ch: word) {
				int id = ch - 'a';
				int newCode = (code & (~(1 << id))); // new encoded value after removing the char
				if (has[newCode]) {
					answer += 1;
					break;
				}
			}
		}
		return answer;
	}
};
