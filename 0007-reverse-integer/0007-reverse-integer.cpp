class Solution {
public:
    int reverse(int x) {
        if(x>=0&&x<=9)
            return x;
        int n=abs(x*1LL);
        long rev=0;
        while(n){
            rev=rev*10+n%10;
            n/=10;
        }
       if(rev>INT_MAX||rev<INT_MIN)
           return 0;
        if(x<0)
        return -rev;
        return rev;
    }
};