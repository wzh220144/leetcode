class MyHashMap {
private:
  int m_size, capacity;
  double load_factor;
  std::vector<std::vector<std::pair<int, int>>> table;

  int hash(int key) { return key % capacity; }

  std::vector<std::pair<int, int>>::iterator search(int key) {
    int h = hash(key);
    auto &bucket = table[h];
    std::vector<pair<int, int>>::iterator iter = bucket.begin();
    while (iter != bucket.end()) {
      if (iter->first == key) {
        break;
      }
      ++iter;
    }
    return iter;
  }

  void rehash() {
    m_size = 0;
    capacity = max(2, capacity);
    std::vector<std::vector<std::pair<int, int>>> old_table(move(table));
    table = std::vector<std::vector<std::pair<int, int>>>(capacity);

    for (auto &chain : old_table) {
      for (std::pair<int, int> &x : chain) {
        put(x.first, x.second);
      }
    }
  }

public:
  MyHashMap() : m_size(0), capacity(2), load_factor(0.75), table(capacity) {}

  void put(int key, int value) {
    int h = hash(key);
    auto iter = search(key);
    if (iter != table[h].end()) {
      iter->second = value;
    } else {
      ++m_size;
      int h = hash(key);
      table[h].push_back(std::make_pair(key, value));
      if (m_size >= load_factor * capacity) {
        capacity *= 2;
        rehash();
      }
    }
  }

  void remove(int key) {
    int h = hash(key);
    auto iter = search(key);

    if (iter == table[h].end()) {
      return;
    }

    --m_size;
    table[h].erase(iter);

    if (m_size <= 0.5 * load_factor * capacity) {
      capacity /= 2;
      rehash();
    }
  }

  int get(int key) {
    int h = hash(key);
    auto iter = search(key);
    if (iter == table[h].end()) {
      return -1;
    } else {
      return search(key)->second;
    }
  }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */