// TC: O(n) solution

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for(int a: arr) {
            if (a<=k) k++;
            if (a>k) return k;
        }
        return k;
    }
};

-------------------------------------------------------------------------------------

// TC: O(logn) solution

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.size()-1 ;
        int mid;
        while (low <= high) {
            mid = (low + high) / 2;
            // arr[m]-(m+1)   --> This gives umber of missing number before m'th index
            if ((arr[mid] - (1 + mid)) < k)  
                low = mid + 1;
            else
                high = mid-1;
        }
        return low + k;
    }
};
