
class Solution {
public:

    string encode(vector<string>& strs) {
    string ans = to_string(strs.size()) + ",";

    for (string s : strs) {
        ans += to_string(s.length()) + ",";
    }

    for (string s : strs) {
        ans += s;
    }

    return ans;
    }

    vector<string> decode(string s) {
    vector<string> result;

    int i = 0;
    int n = 0;

    while (i < s.size() && s[i] != ',') {
        n = n * 10 + (s[i] - '0');
        i++;
    }

    i++;

    vector<int> lengths;

    for (int j = 0; j < n; j++) {
        int len = 0;

        while (i < s.size() && s[i] != ',') {
            len = len * 10 + (s[i] - '0');
            i++;
        }

        lengths.push_back(len);
        i++;
    }

    for (int len : lengths) {
        result.push_back(s.substr(i, len));
        i += len;
    }

    return result;
}
};
