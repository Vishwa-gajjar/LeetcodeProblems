class Solution {
public:
    bool check (int speed, vector<int>& pile, int h) {
        int hoursRequired = 0;
        for(int i: pile) {
            if (i%speed > 0) {
                hoursRequired += i/speed + 1;
            }else {
                hoursRequired += i/speed;
            }
        }
        return hoursRequired <= h;
    }

    int minEatingSpeed(vector<int>& pile, int hours) {
        sort(pile.begin(), pile.end());
        int l = 1, h=pile[pile.size()-1];

        while(l<h) {
            int mid = l+(h-l)/2;
            if (check(mid, pile, hours)) {
                h=mid;
            } else {
                l = mid+1;
            }
        }
        return l;
    }
};
