// Approach 1 : Only 48/56 TestCases solved and bit of complex method
// class UndergroundSystem {
//     unordered_map<int,pair<string,int>>checkInStamp;
//     unordered_map<int,pair<string,int>>checkoutStamp;
// public:
//     UndergroundSystem() {
//     }
    
//     void checkIn(int id, string stationName, int t) {
//         checkInStamp[id] = make_pair(stationName,t);
//     }
    
//     void checkOut(int id, string stationName, int t) {
//         checkoutStamp[id] = make_pair(stationName,t);
//     }
    
//     double getAverageTime(string startStation, string endStation) {
//         int totalTravelTime = 0;
//         int count = 0;
//         for(auto entry : checkoutStamp){
//             int id = entry.first;
//             if(checkInStamp.count(id) && checkoutStamp.count(id)){
//                 string checkInStation = checkInStamp[id].first;
//                 string checkOutStation = checkoutStamp[id].first;
//                 if(checkInStation == startStation && checkOutStation == endStation){
//                     totalTravelTime += checkoutStamp[id].second - checkInStamp[id].second;
//                     count++;
//                 }
//             }
//         }
//         return <double>(totalTravelTime)/count;
//     }
// };

// Approach 2 (Optimal Approach)

struct StationTime {
    string stationName;
    int time;
};

class UndergroundSystem {
    unordered_map<int, StationTime> checkInStamp;
    unordered_map<string, pair<int, int>> travelTime; 
    // Key: "startStation-endStation", Value: {totalTravelTime, totalCount}
public:
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        StationTime checkInInfo = {stationName, t};
        checkInStamp[id] = checkInInfo;
    }
    
    void checkOut(int id, string stationName, int t) {
        const StationTime& checkInInfo = checkInStamp[id];
        string journey = checkInInfo.stationName + "-" + stationName;
        travelTime[journey].first += (t - checkInInfo.time);
        travelTime[journey].second++;
        checkInStamp.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string journey = startStation + "-" + endStation;
        const auto& totalTimeCount = travelTime[journey];
        return static_cast<double>(totalTimeCount.first) / totalTimeCount.second;
        // Here we using static_cast for typecasting purposes
    }
};