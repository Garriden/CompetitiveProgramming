	void merge(vector<int>& coins, int left, int mid, int right) {
		int n1 = mid - left + 1;
		int n2 = right - mid;

		vector<int> v1(n1);
		vector<int> v2(n2);

		for (int ii = 0; ii < n1; ++ii) {
			v1[ii] = coins[left + ii];
		}
		for (int ii = 0; ii < n2; ++ii) {
			v2[ii] = coins[mid + ii + 1];
		}

		int ii = 0, jj = 0, kk = left;
		while (ii < n1 && jj < n2) {
			if (v1[ii] < v2[jj]) {
				coins[kk++] = v1[ii++];
			} else {
				coins[kk++] = v2[jj++];
			}
		}

		while (ii < n1) {
			coins[kk++] = v1[ii++];
		}

		while (jj < n2) {
			coins[kk++] = v2[jj++];
		}
	}

	void mergeSort(vector<int>& coins, int left, int right) {
		if (right > left) {
			int mid = (right + left) / 2;
			mergeSort(coins, left, mid);
			mergeSort(coins, mid + 1, right);
			merge(coins, left, mid, right);
		}
	}


    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) {
            return 0;
        }

        mergeSort(coins,0,coins.size()-1);

        vector<int> DP(amount+1,INT_MAX);
        DP[0] = 0;

        for(int ii = 1; ii < amount + 1; ++ii) {
            for(int jj = 0; jj < coins.size(); ++jj) {
                if(ii - coins[jj] >= 0) {
                    if(DP[ii - coins[jj]] != INT_MAX) {
                        int val = 1 + DP[ii - coins[jj]];
                        if(val < DP[ii]) DP[ii] = val;
                    }
                }
            }
        }

        int ret = -1;
        if(DP[amount] != INT_MAX) {
            ret = DP[amount];
        }
        return ret;
    }
