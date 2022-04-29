class Solution {
public:

    std::unordered_map<std::string, int32_t> mp_ori_key;
    std::unordered_map<int32_t, std::string> mp_key_ori;
    int32_t cur = 0;
    std::string base_url = "http://tinyurl.com/";

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        auto iter = mp_ori_key.find(longUrl);
        std::string res = "";
        if (iter == mp_ori_key.end()) {
            mp_ori_key[longUrl] = cur;
            mp_key_ori[cur] = longUrl;
            res = base_url + std::to_string(cur);
            ++cur;
        } else {
            res = base_url + std::to_string(iter->second);
        }
        return res;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int32_t id = std::stoi(shortUrl.substr(base_url.size()));
        return mp_key_ori[id];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));