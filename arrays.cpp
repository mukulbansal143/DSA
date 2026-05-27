#include<bits/stdc++.h>
using namespace std;


ques 1---------------------------------------------------------------------------------------------------
// check if the array is sorted or not

bool check_sort(int arr[],int n)
{
    for(int i=1;i<n;i++){
        if(arr[i]>=arr[i-1]){

        }
        else{
            return false;
        } 
    }
    return true;
    
}

int main(){
    // check_sort(arr[]={2,2,3,14,6,9},6); THIS IS WRONG AS WE CANT DECLARE ARRAY IN FUCTION CALL

    int arr[]={2,4,28,219,885};
    int n=6;
    int y=check_sort(arr,5);

    if(y==true){
        cout<<"SORTED";
    }
    else{
        cout<<"NOT SORTED";
    }

    return 0;
}


ques 2 -----------------------------------------------------------------------------------------------------------
// REMOVE DUPLICATES FROM AN ARRAY
//1----->>brute solution

void rem_dup(int arr[],int n)
{
    set< int >st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    } //time complexity=o(nlogn)

    int index=0;
    for(auto it:st){
        arr[index]=it;
        index++;
    }//time complexity=o(n)

    for(int i=0;i<index;i++){
        cout<<arr[i]<<" ";
    }
}

//overall time complexity=o(nlogn) since  n is very smaller than nlogn neglect it.
//space complexity=o(n)

int main(){
    int arr[]={1,2,2,2,3,3,3,3,3,4,4,5};
    int n=12;

    rem_dup(arr,12);
    return 0;
}

//2----->>>optimal solution(2 pointer approach)

//1st element ko array me insert kro then check konsa element != 1st element -- insert it into array and so on.

int i=0;
for(int j=1;j<n;j++){
    if(arr[j]!=arr[i]){
        arr[i+1]=arr[j];
        i++;
    }
}
return i+1;


//ques 3-----------------------------------------------------------------------------------------------------

//left rotate an array by 1 step only

int temp=arr[0];
for(int i=1;i<n;i++){
    arr[i-1]=arr[i];  //time complexity=o(n)
}                      
arr[n-1]=temp;

space which we are using in this is only array space=o(n)
but if someone asks what extra space we r using in this, then we will say o(1) as no extra space is taken here

//ques 4-------------------------------------------------------------------------------------------------------------






right rotate an array by k places

1---------------brute solution

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        vector<int>temp(k);

        for(int i=0;i<k;i++){
            temp[i]=nums[n-k+i];
        }

        for(int i=n-k-1;i>=0;i--){
            nums[i+k]=nums[i];
        }

        for(int i=0;i<k;i++){
            nums[i]=temp[i];
        }
    }
};

time complexity=o(k)+(n-k)+o(k)=approx o(n+k)

space complexity=o(d) as it is extra space taken by the program and here that extra space is temp array of d spaces


//2--------optimal solution

since in  brute solution it is taking o(d) of space complexity but to reduce this space complexity to o(1)
we have another approach 

void reverse(int arr[],int start;int end)
{
    while(start<=end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }

}
reverse(arr,arr+d)
reverse(arr+d,arr+n)
reverse(arr,n)

this solution does not create a temp variable of d places and only used o(1) of extra space which is space 
complexity;
but in this solution space complexity is reduced but time complexity becomes o(d)+o(n-d)+o(n) =o(2n)  which is double of previous one but we can say 
its approximately equal to o(n) only

----------------------------------------------------------------------------------------------------------------

//ques 5- Move zeroes at the end

1-----Brute solution

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        vector<int> temp;
        
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                temp.emplace_back(nums[i]);
            }
        }

        int x=temp.size();
        for(int i=0;i<x;i++){
            nums[i]=temp[i];
        }

        for(int i=x;i<n;i++){
            nums[i]=0;
        }
        
    }
};

time complexity=o(n)+o(x)+o(n-x)=o(2n) = o(n)

space complexity= extra space used to solve the problem is temp array which is  created of size  equal to number of non zero numbers which can be at max n
therefore space complexity=o(n);


2------------2 pointer approach

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                j=i;
                break;
            }
        }

        if(j==-1) return;

        for(int i=j+1;i<n;i++){
            if(nums[i]!=0){
                int temp=nums[j];
                nums[j]=nums[i];
                nums[i]=temp;
                j++;
            }
        }    
    }
};

time complexity=o(x)+o(n-x)
=o(n);

space complexity =o(1) as no extra space or varible except temp has been taken during this logic

-------------------------------------------------------------------------------------------------------------
//ques 6 linear search

for(int i=0;i<n;i++){
    if(nums[i]==x){
        return i; //if we want 1st occurence of x 
    }
}

return -1;

but if we want last occurence of x then we have to start iteration from last index (backward)

---------------------------------------------------------------------------------------------------------------------
//ques 7 union of 2 sorted arrays

1-------brute solution

class Solution{
public:
    vector<int> Findunion(vector<int>& a,vector<int>& b){
        int n1=a.size();
        int n2=b.size();

        set<int>st;
        
        for(int i=0;i<n1;i++){
            st.insert(a[i]);
        }

        for(int i=0;i<n2;i++){
            st.insert(b[i]);
        }

        vector<int>temp;
        for(auto it:st){
            temp.emplace_back(it);
        }
        return temp;
    }
};

time complexity=o(n1ogn)+o(n2logn)+o(n1+n2);

space complexity= o(n1+n2)+o(n1+n2);
out of these 2 o(n1+n2) one is used to provide the output in iteraion and used by code


2--------optimal solution



class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();

        int i=0;
        int j=0;

        vector<int> uni_on;

        while(i<n1 && j<n2){
            if(nums1[i]<=nums2[j]){
                if(uni_on.size()==0    ||uni_on.back()!=nums1[i]   ){
                    uni_on.push_back(nums1[i]);
                }
                i++;
            }
            else{
                if(uni_on.size()==0  ||uni_on.back()!=nums2[j] ){
                        uni_on.push_back(nums2[j]);
                }
                j++;
            }


        }

        while(i<n1){
                if(uni_on.back()!=nums1[i] ||  uni_on.size()==0 ){
                    uni_on.push_back(nums1[i]);
                }
                i++;
        }

        while(j<n2){
                if(uni_on.back()!=nums2[j] ||  uni_on.size()==0 ){
                    uni_on.push_back(nums2[j]);
                }
                j++;
            }
        
        return uni_on;
    }
};

time complexity= o(n1+n2);


space complexity=o(n1+n2);  
but important point is that : this space complexity is used for the output and not used in the algo

//ques 8 intersection of two arrays in sorted order

1---------brute solution

class Solution {
public:
    vector<int> intersectionArray(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int i;
        int j;

        vector<int> intersection_arr;

        for(i=0;i<n1;i++){
            for(j=0;j<n2;j++){
                if(nums1[i]==nums2[j] && (intersection_arr.size()==0  || intersection_arr.back()!=nums1[i])){
                    intersection_arr.push_back(nums1[i]);
                    break;
                }
            }
        }

        return intersection_arr;
    }
};

time complexity=o(n1.n2)

space complexity=o(k) where k is the number of common elements 
but this space complexity is used for providing the output and not by the program


2-------optimal solution

class Solution {
public:
    vector<int> intersectionArray(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int i=0;
        int j=0;

        vector<int> inter_arr;

        while(i<n1 && j<n2){

            if(nums1[i]<nums2[j]){
                i++;
            }

            else if(nums1[i]>nums2[j]){
                j++;
            }


            else{
                if(inter_arr.size()==0 ||  inter_arr.back()!=nums1[i]){
                    inter_arr.push_back(nums1[i]);
                }
            i++;
            j++;
            }
        }       
        return inter_arr;
    }
};

time complexity=o(n1+n2)

space complexity=o(k) where k is number of common elements which at max can be n if n1==n2 and  all have same elements
therefor to provide output space complexity is o(n)

but technically we have to give space complexity excluding the output array taken unlike here we have given o(k) just for k common __cpp_lib_incomplete_container_elements
but actual ans for interviews must be given exluding ther output space that is o(1) here

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//ques 9 find missing number

1-----------brute solution

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n=nums.size();

        for(int i=0;i<=n;i++){
            int flag=0;
            for(int j=0;j<n;j++){
                if(nums[j]==i){
                    flag=1;
                    break;
                }
            }

            if(flag==0) return i;

        }
        
    }
};

time complexity= o(n^2)

space complexity=o(1)

2-----------better solution

using hashing (watch video 19 of time 5 : 36)---------------------------------------------------------------------------------------------------------------------------------------------------------------------



3--------- optimal solution

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        
        int expectedsum=((n)*(n+1))/2;
        int actualsum=0;

        for(int i=0;i<n;i++){
            actualsum+=nums[i]; 
        }

        return (expectedsum-actualsum);
    }
};

time complexity=o(n)

space complexity=o(1);

4-----------Another optimal approach using xor gate

watch it again


//ques  10 maximum consecutive 1's

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int i;
        int j;
        int count1=0;
        int count2=0;

        for(i=0;i<n;i++){
            if(nums[i]==1 ){
                count1++;
                count2=max(count1,count2);
            }
            else count1 =0;
        }

        return count2;
        
    }
};

time complexity=o(n);

space complexity=o(1);

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//ques 11  find the number that appears once in a array containing all numbers twice except for that one

1-----------brute force 

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int i;
        int j;
        for(i=0;i<n;i++){
            int count =0;
            for(j=0;j<n;j++){
                if(nums[i]==nums[j]){
                    count++;
                }
            }
        if(count==1) return nums[i];
        }
    return -1;   
    }
};


time complexity=o(n^2);

space complexity=o(1);


2-------better solution (hashing)

class Solution{    
public:    
    int singleNumber(vector<int>& nums){
        int n=nums.size();
        int maxi=nums[0];
        int i;
        
        for(i=0;i<n-1;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
            }
        }

        vector<int> hash(maxi+1,0);
        for(i=0;i<n;i++){
            hash[nums[i]]++;
        }

        for(i=0;i<n;i++){
            if(hash[nums[i]]==1) return nums[i];
        }
        return -1;
    }
};


time complexity=o(n);
space complexity=o(maxi+1)

One limitation:
This hashing approach fails for negative numbers because vector indexing cannot be negative



3--------more better using map since map data structure (opposite to vector) also covers negative and large numbers

class Solution{    
public:    
    int singleNumber(vector<int>& nums){
        int n=nums.size();
        int i;
        map<long long , long long>mpp;
        for(i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(i=0;i<n;i++){
            if(mpp[nums[i]]==1) return nums[i];
        }
        return -1;    
    }
};

time complexity=o(nlogn)+o(n);
space complexity=o(n/2+1) as all elements occurs twice except one element;
therefore those whose frequecy is 2 will get stored in map as 
element--> 2
but that element which occurs only in 1 freq will be stored as element --> 1;



4--------------more better using unordered map instead of just map to optimize time complexity

class Solution{    
public:    
    int singleNumber(vector<int>& nums){
        int n=nums.size();
        int i;
        unordered_map<long long , long long>mpp;
        for(i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(i=0;i<n;i++){
            if(mpp[nums[i]]==1) return nums[i];
        }
        return -1;    
    }
};

time complexity=o(n); but it could be o(n2 ) as we know in worst critical case which happens very rarely
that unordered map will take o(n) instead of  o(1);

5------------optimal solution using xor appproach

^  = this is operator used for xor in cpp;

a^a=0
0^a=a;
a^0=a;
0^0=0;

if we use xor opeartions among all the elements in an array then elements which appear twice will give 
output 0 by a^a=0;
and at the end we will left with only that element which is present in unique freq 
that unique element is let say x;

we will be left with x^0 and which is equal to x;

therefore it will be the most optimal approach of this quess;



class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int i;
        int xorr=0;
        for(i=0;i<n;i++){
            xorr=xorr^nums[i];
        }
        return xorr;
    }
};

time complexity=o(n);
space complexity=o(1);


----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

ques 12- 



















