class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if ( N < 0 ) {
            x = 1 / x;
            N = -N;
        }
        return fastpow(x, N);
    }

    double fastpow(double x, long long n) {
        if (n == 0) {
            return 1.0;
        }
        double temp = fastpow(x, n/2);
        return (n % 2 == 0)? temp * temp: temp * temp * x;
        
    }
};