class FreqStack {
public:
    int32_t max_freq;
    unordered_map<int32_t, stack<int32_t>> cnt_mq;
    unordered_map<int32_t, int32_t> freq_mq;
    FreqStack() {
        max_freq = 0;
    }
    
    void push(int val) {
        int32_t cur_freq = ++freq_mq[val];
        max_freq = max(max_freq, cur_freq);
        cnt_mq[cur_freq].push(val);
    }
    
    int pop() {
        auto& s = cnt_mq[max_freq];
        int32_t res = s.top();
        s.pop();
        if (s.empty()) {
            --max_freq;
        }
        --freq_mq[res];
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */