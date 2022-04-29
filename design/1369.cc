class UndergroundSystem {
public:
    std::unordered_map<int32_t, std::pair<std::string, int32_t>> mp_id_record;
    std::unordered_map<std::string, double> mp_station_total_time;
    std::unordered_map<std::string, double> mp_station_cnt;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mp_id_record[id] = std::make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        auto tt = mp_id_record[id];
        std::string key = tt.first + ":" + stationName;
        mp_station_total_time[key] += t - tt.second;
        mp_station_cnt[key] += 1.0;
    }
    
    double getAverageTime(string startStation, string endStation) {
        std::string key = startStation + ":" + endStation;
        return mp_station_total_time[key] / mp_station_cnt[key];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */