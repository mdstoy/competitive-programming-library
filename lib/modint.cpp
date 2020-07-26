using ll = long long;

class mint {
        ll value;
        int mod;
    public:
        constexpr mint(ll src = 0, int m = 1000000007) noexcept : value((src % m + m) % m), mod(m) {}

        constexpr ll v() { return value; }

        constexpr mint operator+(const mint rhs) const noexcept {return mint(*this) += rhs;}
        constexpr mint operator-(const mint rhs) const noexcept {return mint(*this) -= rhs;}
        constexpr mint operator*(const mint rhs) const noexcept {return mint(*this) *= rhs;}
        constexpr mint operator/(const mint rhs) const noexcept {return mint(*this) /= rhs;}

        constexpr mint &operator+=(const mint rhs) noexcept {
            value += rhs.value;
            if (value >= mod) value -= mod;
            return *this;
        }

        constexpr mint &operator-=(const mint rhs) noexcept {
            if (value < rhs.value) value += mod;
            value -= rhs.value;
            return *this;
        }

        constexpr mint &operator*=(const mint rhs) noexcept {
            value = value * rhs.value % mod;
            return *this;
        }
        
        constexpr mint &operator/=(mint rhs) noexcept {
            ll exp = mod - 2;
            while (exp) {
                if (exp % 2) *this *= rhs;
                rhs *= rhs;
                exp /= 2;
            }
            return *this;
        }

        constexpr mint pow(ll p) noexcept {
            if (p == 0) return 1;
            else if (p % 2 == 1) return pow(p - 1) * *this;
            else { mint a = pow(p / 2); return a * a; }
        }
};
