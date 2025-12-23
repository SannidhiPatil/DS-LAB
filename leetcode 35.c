int searchInsert(int* nums, int numsSize, int target) {
    int pos = 1, j = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            return i;
            break;
        }
    }
    if (target < nums[0]) {
        return 0;
    } 
    else if (target > nums[numsSize - 1]) {
        return numsSize;
    } 
    else {
        while (pos == 1) {
            if (target > nums[j] && target < nums[j + 1]) {
                return (j + 1);
                break;
            } 
            else {
                j++;
            }
        }
    }
    return 0;
}
