// Possible Words From Phone Digits

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        vector<string> res;
        map<int,vector<char>> mp;
        for(int i=0;i<N;i++){
            if(a[i]==2 && mp.find(a[i])==mp.end()){
                mp[2].push_back('a');
                mp[2].push_back('b');
                mp[2].push_back('c');
            }
            else if(a[i]==3 && mp.find(a[i])==mp.end()){
                mp[3].push_back('d');
                mp[3].push_back('e');
                mp[3].push_back('f');
            }
            else if(a[i]==4 && mp.find(a[i])==mp.end()){
                mp[4].push_back('g');
                mp[4].push_back('h');
                mp[4].push_back('i');
            }
            else if(a[i]==5 && mp.find(a[i])==mp.end()){
                mp[5].push_back('j');
                mp[5].push_back('k');
                mp[5].push_back('l');
            }
            else if(a[i]==6 && mp.find(a[i])==mp.end()){
                mp[6].push_back('m');
                mp[6].push_back('n');
                mp[6].push_back('o');
            }
            else if(a[i]==7 && mp.find(a[i])==mp.end()){
                mp[7].push_back('p');
                mp[7].push_back('q');
                mp[7].push_back('r');
                mp[7].push_back('s');
            }
            else if(a[i]==8 && mp.find(a[i])==mp.end()){
                mp[8].push_back('t');
                mp[8].push_back('u');
                mp[8].push_back('v');
            }
            else if(a[i]==9 && mp.find(a[i])==mp.end()){
                mp[9].push_back('w');
                mp[9].push_back('x');
                mp[9].push_back('y');
                mp[9].push_back('z');
            }
        }
        string str="";
        int i=0;
        solve(mp,a,res,i,N,str);

        return res;
    }
    void solve(map<int,vector<char>> mp,int a[],vector<string>& res,int i,int N,string str){
        if(str.length()==N){
            res.push_back(str);
            return;
        }
        for(auto x:mp[a[i]]){
            solve(mp,a,res,i+1,N,str+x);
        }
    }
};
