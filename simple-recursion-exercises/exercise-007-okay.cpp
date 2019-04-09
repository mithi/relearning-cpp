// An "okay" implementation (not the best)
// Implement pow(x, n), which calculates x raised to the power n.
// -100.0 < x < 100.0
// n is a 32-bit signed integer, within the range [−231, 231 − 1]
// Account for problems of overflow and precision
// do binary
class Solution {
public:
    double myPow(double x, int n) {
        // Anything raised to zero is one
        // One raised to anything is one
        if (n == 0 || x == 1.0) { return 1.0; };

        // To avoid recursive stackoverflows,
        // let's do this optimization
        // if n is a multiple of 2 ie n = 2*m then
        // expoit exponentiation property:
        // x^(2*m) = (x^m)*(x^m) = (x*x)^m
        // which is log(n)
        if (n % 2 == 0) {
            return myPow( x * x, n / 2);
        }

        // example:  x^(-5) = 1 / (x^(5))
        if (n < 0) { return 1.0 / myPow(x, -n); }

        // example: x^5 = x * (x^4)
        return x * myPow(x, n - 1);
    }
};