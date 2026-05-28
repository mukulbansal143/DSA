WHAT IS SUBARRAY??

subarray is contiguous elements of array
eg--[2,3,4,5,6,45,33,21,22];

subarray can be 2,3,4   or   6,45    or 33,21,22  etc.
but not be 2,4,5 nor 45,22;

like it must be adjacent


ques --- Longest subarray with sum K

Given an array nums of size n and an integer k, 
find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.


Example 1

Input: nums = [10, 5, 2, 7, 1, 9],  k=15

Output: 4

Explanation:

The longest sub-array with a sum equal to 15 is [5, 2, 7, 1], which has a length of 4. 
This sub-array starts at index 1 and ends at index 4, and the sum of its elements (5 + 2 + 7 + 1) equals 15. 
Therefore, the length of this sub-array is 4


code: 

1------------------BRUTE FORCE 

class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int n=nums.size();
        int i,j,l;
        int len=0;
        for(i=0;i<n;i++){
            for(j=i;j<n;j++){
                int sum=0;
                for(l=i;l<=j;l++){
                    sum+=nums[l];
                }
                if(sum==k){
                    len=max(len,j-i+1);
                }
            }
        }
        return len;       
    }
};

time complexity= approxxx o(n cube);
space complexity=o(1);

2--------optimizing brute force

this brute force can be optimised that we dont need to use another loop for addition and instead of this we can directly add in j loop only 

class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int n=nums.size();
        int i,j;
        int len=0;
        for(i=0;i<n;i++){
            int sum=0;
            for(j=i;j<n;j++){
                sum+=nums[j];
                if(sum==k){
                    len=max(len,j-i+1);
                }
            }
        }
        return len;
    }
};

this is better than brute force as it has time complexity=o(n square);
space complexity=o(1);


3------------------