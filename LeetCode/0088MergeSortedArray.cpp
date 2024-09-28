class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        vector<int> vaux(m);

        for(int ii = 0; ii < m; ++ii) {
            vaux[ii] = nums1[ii];
        }

        int i = 0;
        int j = 0;
        while(i < m && j < n) {
            if(vaux[i] < nums2[j]) {
                nums1[i+j] = vaux[i];
                i++;
            } else {
                nums1[i+j] = nums2[j];
                j++;
            }

        }

        while(i < m) {
            nums1[i+j] = vaux[i];
            i++;
        }

        while(j < n) {
            nums1[i+j] = nums2[j];
            j++;
        }

    }
};
