class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1e9 + 7;

        int m = r - l + 1;

        vector<int> up(m), down(m);
        vector<int> preUp(m), preDown(m);
        vector<int> newUp(m), newDown(m);

        // length 2 initialization
        for(int i = 0; i < m; i++) {
            up[i] = i;
            down[i] = m - i - 1;
        }


        for(int len = 3; len <= n; len++) {

            preUp[0] = up[0];
            preDown[0] = down[0];

            for(int i = 1; i < m; i++) {
                preUp[i] = (preUp[i-1] + up[i]) % MOD;
                preDown[i] = (preDown[i-1] + down[i]) % MOD;
            }


            for(int i = 0; i < m; i++) {

                if(i > 0)
                    newUp[i] = preDown[i-1];
                else
                    newUp[i] = 0;


                if(i < m-1)
                    newDown[i] = 
                    (preUp[m-1] - preUp[i] + MOD) % MOD;
                else
                    newDown[i] = 0;
            }


            up.swap(newUp);
            down.swap(newDown);
        }


        long long ans = 0;

        for(int i = 0; i < m; i++) {
            ans += up[i];
            ans += down[i];
            ans %= MOD;
        }

        return ans;
    }
};