bool sortBySecond(vector<int>& first, vector<int>& second) {
      return (first.back() < second.back());
}

class Solution {
  public:

    vector<vector<int>*> constructOptimalSchedule(vector<vector<int>>& intervals) {
      vector<vector<int>*> retval;

      sort(intervals.begin(), intervals.end(), sortBySecond);

      for (long unsigned i = 0; i < intervals.size(); i++) {
        if (retval.size() == 0) {
          retval.push_back(&intervals[i]);
        }

        if(intervals[i].front() >= retval.back()->back()) {
          retval.push_back(&intervals[i]);
        }

      }

      return retval;

    }
};
