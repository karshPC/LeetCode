class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;         // Pointer for last valid element in nums1
        int j = n - 1;         // Pointer for last element in nums2
        int k = m + n - 1;     // Pointer for last index of the combined array

        // Move backwards and place the larger element at index k
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        // Copy remaining elements from nums2 if any are left
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
        
        // Note: Remaining items in nums1 are already in their correct places
    }
};
