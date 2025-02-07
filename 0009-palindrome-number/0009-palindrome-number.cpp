class Solution {
public:
    long long int reverse(int n){
        long long int rev=0;
        while(n>0){
            rev=rev*10+n%10;
            n/=10;
        }
        return rev;
    }
    bool isPalindrome(int x) {
        if(x>=0&&x<=9)
            return true;
        if(x>0){
            long long int temp=reverse(x);
            if((long long int)x==temp)
                return true;
            else{
                return false;
            }
        }
        return false;
    }
};