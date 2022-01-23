// Given a destination D , find the minimum number of steps required to reach that destination.

class Solution{
public:
    int minSteps(int D){
        // code here
        int sum=0;
        int i=1;
        while(true){
            sum+=i;
            if(sum>=D && (sum-D)%2==0){
                return i;
            }
            i++;
        }
        return -1;
    }
};
