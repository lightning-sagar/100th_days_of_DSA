class Solution {
public:
    int climbStairs(int n) {
        int a=0,b=1;
        int c,i=0;
        while(n>i){
            c=a+b;
            a=b;
            b=c;
            i++;
        }
        return c;
    }
};