public class Solution
{
    public int removeDuplicates(int[] nums)
    {
        int dupes = 0;
        
        for (int i = 1; i < nums.length; i++)
        {
            if (nums[i] == nums[i - 1])
                dupes++;
            
            nums[i - dupes] = nums[i];
        }
        
        return nums.length - dupes;
    }
}

//delete duplicate from an array in 1ms
