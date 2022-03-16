class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int32_t> s;
        int32_t i = 0;
        int32_t j = 0;
        bool res = true;
        while(j < popped.size()) {
            int32_t cur = popped[j];
            while (true) {
                if (s.size() > 0 && s.top() == cur) {
                    ++j;
                    s.pop();
                    break;
                } else {
                    if (i >= pushed.size()) {
                        res =false;
                        break;
                    } else {
                        s.push(pushed[i]);
                        ++i;
                    }
                }
            }
            if (!res) {
                break;
            }
        }
        return res;
    }
};