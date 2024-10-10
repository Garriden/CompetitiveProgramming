int trap(vector<int>& height) {
	int N = height.size();
	vector<int> maxLeft(N);
	vector<int> maxRight(N);
	vector<int> minV(N);

	int currentMax = 0;
	int alreadyWater = 0;

	cout << "maxLeft: ";
	maxLeft[0] = 0;
	for(int ii = 1; ii < N; ++ii) {
		if(height[ii-1] > currentMax) currentMax = height[ii-1];
		maxLeft[ii] = currentMax;
		cout << ", " << maxLeft[ii];
	}

	cout << endl <<  "maxRight: ";
	currentMax = 0;
	maxRight[N-1] = 0;
	for(int ii = N-2; ii > 0; --ii) {
		if(height[ii+1] > currentMax) currentMax = height[ii+1];
		maxRight[ii] = currentMax;
		cout << ", " << maxRight[ii];
	}
	cout << endl << "min: ";

	for(int ii = 0; ii < N-1; ++ii) {
		minV[ii] = min(maxLeft[ii], maxRight[ii]);
		cout << " " << minV[ii];
		if(minV[ii]-height[ii] > 0) alreadyWater += minV[ii]-height[ii];
	}

	return alreadyWater;
}
