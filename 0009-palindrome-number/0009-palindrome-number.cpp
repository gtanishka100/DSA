class Solution {
public:
    bool isPalindrome(int x) {
        long int newx=0,dig;
        int num=x;
        while(x!=0){
            dig=x%10;
            x=x/10;
            newx=10*newx+dig;
        }
        if(num==0) return true;
        else if(newx==num && num>0) return true;
        else return false;
    }
};