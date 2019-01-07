class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return x;
        long long N = n;
        if (n < 0)
            return pow(1/x, -N);
        return pow(x, N);
    }

    double pow(double x, long long n) {
        if (n == 0) return 1;
        if (n == 1) {
            return x;
        }
        double val = myPow(x, n/2);
        if (n % 2) {
            return   val * val * x;
        }
        return val * val;
    }
};
