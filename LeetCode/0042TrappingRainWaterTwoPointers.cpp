    int trap(vector<int>& v) {
        int n = v.size();
        int alreadyWater = 0;
        int maxLeft = v[0];
        int maxRight = v[n - 1];
        int left = 1;
        int right = n - 2;

        while(left <= right) {

            if(maxLeft <= maxRight) {
                if(v[left] > maxLeft) maxLeft = v[left];
                alreadyWater += maxLeft - v[left];
                ++left;
            } else {
                if(v[right] > maxRight) maxRight = v[right];
                alreadyWater += maxRight - v[right];
                --right;
            }

        }

        return alreadyWater;
    }
