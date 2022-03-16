class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string cur = "";
        for (int32_t i = 0; i < path.size(); ++i) {
            if (path[i] == '/') {
                if (cur.size() == 0) {
                    continue;
                } else {
                    if (cur == "..") {
                        if (!s.empty()) {
                            s.pop();
                        }
                    } else if (cur == ".") {
                    } else {
                        s.push(cur);
                    }
                    cur = "";
                }
            } else {
                cur += path[i];
            }
        }
        if (cur.size() > 0) {
            if (cur == "..") {
                if (!s.empty()) {
                    s.pop();
                }
                cur = "";
            } else if (cur != ".") {
                cur = "/" + cur;
            } else {
                cur = "";
            }
        }
        while(!s.empty()) {
            cur = "/" + s.top() + cur;
            s.pop();
        }
        if (cur.size() == 0) {
            cur = "/";
        }
        return cur;
    }
};