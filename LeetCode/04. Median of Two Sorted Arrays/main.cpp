class Solution {
public:
    vector<int> mergeSortedArrays(const vector<int>& arr1, const vector<int>& arr2) {
        vector<int> merged;
        int i = 0, j = 0;

        while (i < arr1.size() && j < arr2.size()) {
            if (arr1[i] <= arr2[j]) {
                merged.push_back(arr1[i++]);
            } else {
                merged.push_back(arr2[j++]);
            }
        }

        while (i < arr1.size()) {
            merged.push_back(arr1[i++]);
        }

        while (j < arr2.size()) {
            merged.push_back(arr2[j++]);
        }

        return merged;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged = mergeSortedArrays(nums1, nums2);
        if(merged.size() % 2 != 0){
            return static_cast<double>(merged[merged.size()/2]);
        } else {
            return (merged[merged.size()/2] + static_cast<double>(merged[merged.size()/2 - 1]))/2;
        }
    }
};
