class Solution {
public:
    typedef long long ll;

    bool check(vector<int>& time, ll mid, int& totalTrips) {
        ll trips = 0;
        for(auto& i: time) {
            trips += mid/i;
        }
        return (trips >= totalTrips);
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(), time.end());
        int n = time.size();
        ll low = (ll)time[0];
        ll high = (ll)time[n-1]*totalTrips;

        while(low<high) {
            ll mid = (low + high) / 2;
            if (check(time, mid, totalTrips)) {
                high = mid;
            } else {
                low = mid+1;
            }
        }
        return low;
    }
};
