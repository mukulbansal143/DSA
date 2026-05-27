//#include<bits/stdc++.h>
//using namespace std;



// ques 1 count the number of digits in a number 


1-------main method 



// int main(){
//     int n;
//     cin>>n;

//     while(n>0){
//         int lastdigit=n%10; // extraction of digits(main concept here)
//         cout<<lastdigit<<endl;
//         n=n/10;
//     }

//     return 0;
// }

time complexity= imp point WHENEVER LOOP IS RUNNING FOR NUMBER OF TIMES ITS DIVIDING LIKE HERE CODE DEPENDS ON 
HOW MANY TIMES N WILL BE DIVIDE BY 10 .THEREFORE TIME COMPLEXITY IN THIS CASE WILL BE O(LOG10(N)) 
IF N WILL BE DIVISIBLE BY ANY OTHER NUMBER THEN TIME COMPLEITY WOULD HAVE BEEN CHNAGED ACCORDINGLY

NOTE THAT OR MULTIPLICATION RELATED LOOPS ALSO TIME COMPLEXITY IS FUNTION OF LOG


2-----------shortcut method

int count= int (log10(n)+1);
return count;


------------------------------------------------------------------------------------------------------------------

ques 2 reverse a number

class Solution {
public:
    int reverse(int x) {
        int lastdigit;
        long long rev=0; //int data type cannot cover larger integers;
        while(x!=0){    //we have not used x>0 here as it will not consider cases for negative numbers
            lastdigit=x%10;
            rev=(rev*10)+lastdigit;

            if(rev>INT_MAX|| rev<INT_MIN) return 0;

            x=x/10;
        }
        return rev;  
    }
};

----------------------------------------------------------------------------------------------------------------------------------------

ques 3  check palindrome or not

class Solution {
public:
    bool isPalindrome(int x) {
        int lastdigit;
        int original=x;
        long long rev=0;
        while(x>0){  //we have use x>0 here as we want only positive numbers to go inside it since negative numbers can not be palindromes .therefore we have not used x!=0;

            lastdigit=x%10;
            rev=(rev*10)+lastdigit;

            x=x/10;

        }


        if(original==rev) return true;
        else return false;
    }
};

//we have made a new variable to store original x because inside then loop we are making changes in x and at the end of the while loop x will become 0 and code will return false always;

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

ques 4 check if the number is armstrong number or not

An armstrong number is a number which is equal to the sum of the digits of the number, raised to the power of the number of digits.

Example,
Input: n = 153
Output: true

Explanation: Number of digits : 3.
1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153.
Therefore, it is an Armstrong number.


class Solution {
public:
    bool isArmstrong(int n) {
        int original=n;
        int count=int (log10(n)+1);
        int sum=0;
        int lastdigit;


        while(n>0){
            lastdigit=n%10;
            sum=sum+pow(lastdigit,count);// in C++ WE HAVE TO USE POW() FUNTION FOR RAISE TO THE POWER OUTPUT AS ^ OPERATOR IS USED AS XOR OPERATOR IN CPP LANGUAGE
            n=n/10;           
        }

        if(original==sum) return true;
        else return false;
    }
};

----------------------------------------------------------------------------------------------------------------------------------------

//ques 5 print all divisors 

class Solution {
public:
    vector<int> divisors(int n) {

        vector<int>div;
        int i;
        for(i=1;i<=sqrt(n);i++){//but this sqrt is also a funtion so it will takes its own time to come so instead of using this we can use i*i<=n
            if(n%i==0){
                div.push_back(i);
                if((n/i)!=i) div.push_back(n/i);
                
            }
        
        sort(div.begin(),div.end());//sorting takes nlogn time where n is the number of factors here


        }
        return div;

    }
};

time complexity=o(root n)+no.of factors*log(no.of factors);


//ques 6 check for prime number

class Solution {
public:
    bool isPrime(int n) {
        int count=0;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                count++;
                if((n/i)!=i) count++;             
            }
        }

        if(count==2) return true;
        else return false;
    }
};

//ques fidn hcf or gcd= greatest common divisor
1------------------------
class Solution {
public:
    int GCD(int n1,int n2) {
        int gcd= 1;

        for(int i=1;i<min(n1,n2);i++){
            if(n1%i==0 && n2%i==0){
                gcd=i;
            }
        }
        
        return gcd;
    }
};


time complexity=o(min(n1,n2));

2--------------------

as we have to find highest commoen factor then we should process the loop from behind 

class Solution {
public:
    int GCD(int n1,int n2) {

        int gcd=1;
        for(int i=min(n1,n2);i>=1;i--){
            if(n1%i==0 && n2%i==0){
                gcd=i;
                break;
            }
        }
        return gcd;
    }
};

time complexity=o(min(n1,n2));



3-----------------EUCLIDEAN ALOGORITHM

class Solution {
public:
    int GCD(int n1,int n2) {

        while(n1>0 && n2>0){
            if(n1>n2) n1=n1%n2;
            else n2=n2%n1;
        }

        if(n1==0) return n2;
        else return n1;

    }
};

time complexity= since we know whenever multiplation or divisions operations are occuring continuously in a loop then we have time complexity of log n typedef
here ALSO WE HAVE MODULO OPERATION HAPPENING ALL TIME WHICH IS KIND OF SIMILAR TO DIVISION OPERATION SO HERE ALSO WE HAVE LOG N TIME COMPLEXITY

ALSO WE KNOW BASE OF LOG IS BY WHICH FACTOR NUMBER IS GETTING MULTIPLIED OR DIVIDED .HERE MODULO FACTOR KEEPS CHANGING AT ALL STEPS .THEREFORE ASSUME IT TO BE PHI

TIME COMPLEXITY=O(log (min(n1,n2))) where log has base phi.