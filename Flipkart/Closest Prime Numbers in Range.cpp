class Solution
{
public:
    vector<int> pr;
    void sieve(int n, int l)
    {
        // Create a boolean array "prime[0..n]" and initialize
        // all entries it as true. A value in prime[i] will
        // finally be false if i is Not a prime, else true.
        bool prime[n + 1];
        memset(prime, true, sizeof(prime));

        for (int p = 2; p * p <= n; p++)
        {
            // If prime[p] is not changed, then it is a prime
            if (prime[p] == true)
            {
                // Update all multiples of p greater than or
                // equal to the square of it numbers which are
                // multiple of p and are less than p^2 are
                // already been marked.
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }

        // Print all prime numbers
        for (int p = 2; p <= n; p++)
            if (prime[p] && p >= l)
                pr.push_back(p);
        // cout << p << " ";
    }

    vector<int> closestPrimes(int left, int right)
    {
        sieve(right, left);
        if (pr.size() <= 1)
            return {-1, -1};
        sort(pr.begin(), pr.end());
        int cnt = INT_MAX;
        vector<int> ans;
        for (int i = 0; i < pr.size() - 1; i++)
        {
            int p = pr[i + 1] - pr[i];
            if (p < cnt)
            {
                cnt = p;
                ans = {pr[i], pr[i + 1]};
            }
        }
        return ans;
    }
};