class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int32_t add = 0;
        int32_t ai = a.size() - 1;
        int32_t bi = b.size() - 1;
        while(true) {
            if (ai < 0 && bi < 0 && add == 0) {
                break;
            }
            int32_t sum = add;
            if (ai >= 0) {
                if (a[ai] == '1') {
                    ++sum;
                }
            }
            if (bi >= 0) {
                if (b[bi] == '1') {
                    ++sum;
                }
            }
            if (sum & 1) {
                res = "1" + res;
            } else {
                res = "0" + res;
            }
            if (sum >= 2) {
                add = 1;
            } else {
                add = 0;
            }
            --ai;
            --bi;
        }
        return res;
    }
};