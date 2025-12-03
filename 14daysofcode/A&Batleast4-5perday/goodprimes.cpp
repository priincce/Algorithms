#include <iostream>
bool good(long long x) {
    return x % 2 != 0 && x % 3 != 0 && x % 5 != 0 && x % 7 != 0;
}

long long get_naive(long long x) {
    long long ans = 0;
    for (long long i = 0; i < x; ++i) {
        if (good(i)) {
            ans++;
        }
    }
    return ans;
}
long long get(long long r) {
    const long long period = 210;
    long long full_periods = r / period;
    long long remainder = r % period;

    const long long count_in_period = 48; 
    return (full_periods * count_in_period) + get_naive(remainder);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    if (!(std::cin >> t)) return 0; 

    for (int i = 0; i < t; ++i) {
        long long l, r;
        std::cin >> l >> r;
        long long result = get(r + 1) - get(l);
        std::cout << result << "\n";
    }

    return 0;
}
