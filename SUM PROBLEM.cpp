//2 SUM PROBLEM

in this ques we have two varieties

. whether those 2 numbers which sum up to target exist or not-->> yes or no 
. return the indices of that 2  numbers if they exist

1---------------brute force

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int i,j;
        vector<int>idx;

        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target){
                    idx.push_back(i);
                    idx.push_back(j);
                    break;
                }
            }
        }
        return idx;    //if we change return type to string and use yes or no then 1st variety will get covered
    }
};

time complexity=o(n square) approx;
space complexity=o(1);



2--------------better solution(using hash map)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int i;
        int j;

        map<int,int>mpp;

        for(i=0;i<n;i++){
            int a=nums[i];
            int rem=target-a;
            if(mpp.find(rem)!=mpp.end()){
                return {i,mpp[rem]}; //to cover 1st variety just return yes or no here
            }
            mpp[a]=i;
        }
        return {-1,-1};    //to cover 1st variety just return yes or no here
    }
};

time complexity=o(nlogn); because every find and insert in map takes logn time;
space complexity=o(n)

3----------more better (using unordered map instead of just map)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int i;
        int j;

        unordered_map<int,int>mpp;

        for(i=0;i<n;i++){
            int a=nums[i];
            int rem=target-a;
            if(mpp.find(rem)!=mpp.end()){
                return {i,mpp[rem]};
            }
            mpp[a]=i;
        }
        return {-1,-1};    
    }
};

time complexity=o(n);
space compelxity=o(n);

it is the most optimal approach for variety 2;

4------------if we have given a condition that we cant use map data structure 

class Solution {
public:
    string<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int left=0;
        int right=n-1;

        while(left<right){
            int sum=nums[left]+nums[right];
            if(sum==target) return "YES";
            else if(sum>target) right--;
            else left++;
            
        }
        return "NO";
        
    }
};


time complexity=o(n) for while loop + o(nlogn ) for sorting
               =o(n)+o(nlogn);

space complexity=o(1);

this method is only for variety 1 
as for variety 2 we have to return indices but they got changed due to sorting 

the most optimal approach for vareity 1 is this 4th method 

