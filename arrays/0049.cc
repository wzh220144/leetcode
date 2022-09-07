/*49. 字母异位词分组
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。

 

示例 1:

输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
示例 2:

输入: strs = [""]
输出: [[""]]
示例 3:

输入: strs = ["a"]
输出: [["a"]]*/
class Solution {
public:

    bool isuniq(const std::string& x, std::string& key) {
        key = x;
        std::sort(key.begin(), key.end());
        bool res = true;
        char pre = '\0';
        for (const auto& c : key) {
            if (c == pre) {
                res = false;
                break;
            }
            pre = c;
        }
        return res;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        std::map<std::string, std::vector<std::string>> t;
        for (const auto& str : strs) {
            std::string key = "";
            isuniq(str, key);
            t[key].emplace_back(str);
        }
        for (const auto& p : t) {
            res.emplace_back(std::move(p.second));
        }
        return res;
    }
};