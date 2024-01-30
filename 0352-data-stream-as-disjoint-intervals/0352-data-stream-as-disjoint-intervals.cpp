
class SummaryRanges {
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        // Insert the new value into intervals
        intervals.push_back({value, value});
        
        // Sort the intervals based on start values
        std::sort(intervals.begin(), intervals.end());
        
        // Merge overlapping intervals
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= intervals[i - 1][1] + 1) {
                intervals[i][0] = std::min(intervals[i][0], intervals[i - 1][0]);
                intervals[i][1] = std::max(intervals[i][1], intervals[i - 1][1]);
                intervals.erase(intervals.begin() + i - 1);
                --i;
            }
        }
    }
    
    std::vector<std::vector<int>> getIntervals() {
        return intervals;
    }

private:
    std::vector<std::vector<int>> intervals;
};


/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */