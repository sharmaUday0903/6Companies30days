/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution
{
public:
    int findInMountainArray(int target, MountainArray &M)
    {
        int left = 0, right = M.length() - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (M.get(mid) < M.get(mid + 1))
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        int p = left;
        left = 0;
        right = p;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (M.get(mid) > target)
            {
                right = mid - 1;
            }
            else if (M.get(mid) < target)
            {
                left = mid + 1;
            }
            else
                return mid;
        }
        left = p;
        right = M.length() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (M.get(mid) < target)
            {
                right = mid - 1;
            }
            else if (M.get(mid) > target)
            {
                left = mid + 1;
            }
            else
                return mid;
        }

        return -1;
    }
};