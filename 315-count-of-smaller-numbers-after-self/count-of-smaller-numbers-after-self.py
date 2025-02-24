class Solution(object):
    def countSmaller(self, nums):
        n = len(nums)
        counts = [0] * n  # This will hold the result for each index

        # Pair each value with its original index
        nums_with_index = [(val, idx) for idx, val in enumerate(nums)]

        def merge_sort(start, end):
            # Sort the subarray nums_with_index[start:end+1] in place
            # and update counts[] during the merge step.
            if start >= end:
                return
            
            mid = (start + end) // 2
            merge_sort(start, mid)
            merge_sort(mid + 1, end)

            # Merge step
            left_part = start
            right_part = mid + 1
            temp = []
            smaller_count = 0  # how many elements from right part have been moved

            while left_part <= mid and right_part <= end:
                # If left value <= right value, place it and add smaller_count
                if nums_with_index[left_part][0] <= nums_with_index[right_part][0]:
                    val, original_idx = nums_with_index[left_part]
                    counts[original_idx] += smaller_count
                    temp.append((val, original_idx))
                    left_part += 1
                else:
                    # If right value < left value, it means this right value
                    # is a smaller element for all remaining left elements
                    val, original_idx = nums_with_index[right_part]
                    temp.append((val, original_idx))
                    right_part += 1
                    smaller_count += 1
            
            # Add the remaining elements in left_part
            while left_part <= mid:
                val, original_idx = nums_with_index[left_part]
                counts[original_idx] += smaller_count
                temp.append((val, original_idx))
                left_part += 1

            # Add the remaining elements in right_part
            while right_part <= end:
                temp.append(nums_with_index[right_part])
                right_part += 1

            # Copy back into nums_with_index
            for i in range(len(temp)):
                nums_with_index[start + i] = temp[i]

        # Perform merge sort on the entire range
        merge_sort(0, n - 1)
        return counts