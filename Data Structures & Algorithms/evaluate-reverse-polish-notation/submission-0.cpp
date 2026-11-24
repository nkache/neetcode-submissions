class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        unordered_set<string> ops = {"+", "-", "*", "/"};

        for (string s: tokens)
        {
            if (ops.count(s))
            {
                int n1 = numbers.top();
                numbers.pop();
                int n2 = numbers.top();
                numbers.pop();

                if (s == "+") {
                    numbers.push(n1 + n2);
                }
                else if (s == "-") {
                    numbers.push(n2 - n1);
                }
                else if (s == "*") {
                    numbers.push(n1 * n2);
                }
                else if (s == "/") {
                    numbers.push(n2 / n1);
                }
            }
            else
            {
                numbers.push(stoi(s));
            }
        }

        return numbers.top();
    }
};
