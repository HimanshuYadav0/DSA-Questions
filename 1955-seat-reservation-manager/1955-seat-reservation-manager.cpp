class SeatManager {
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            available_seats.push(i);
        }
    }
    
    int reserve() {
        int seat = available_seats.top();
        available_seats.pop();
        reserved_seats.insert(seat);
        return seat;
    }
    
    void unreserve(int seatNumber) {
        if (reserved_seats.find(seatNumber) != reserved_seats.end()) {
            reserved_seats.erase(seatNumber);
            available_seats.push(seatNumber);
        }
    }
    
private:
    priority_queue<int, vector<int>, greater<int>> available_seats;
    unordered_set<int> reserved_seats;
};


/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */