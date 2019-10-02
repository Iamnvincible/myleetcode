#ifndef PRIME_SIEVE
#define PRIME_SIEVE
#include <vector>
class prime_sieve {
 private:
  const unsigned primesunderk[10] = {0,    4,     25,     168,     1229,
                                     9592, 78498, 664579, 5761455, 50847534};

 public:
  /*
  埃拉托斯特尼筛法
  找出不大于n的所有素数
  n:无符号整数
  返回值:vector
   */
  std::vector<unsigned> Eratosthenes(unsigned n) {
    bool* is_prime = new bool[n + 1]();
    std::vector<unsigned> primes;
    if (n <= 1) {
      return primes;
    }
    is_prime[0] = is_prime[1] = true;
    for (size_t i = 2; i <= n; i++) {
      if (!is_prime[i]) {
        primes.push_back(i);
        for (size_t j = i * i; j <= n; j += i) {
          is_prime[j] = true;
        }
      }
    }
    delete[] is_prime;
    return primes;
  }
  /*
  欧拉筛法
  找出不大于n的所有素数，更快
  n:无符号整数
  返回值:vector
   */
  std::vector<unsigned> Euler(unsigned n) {
    bool* is_prime = new bool[n + 1]();
    std::vector<unsigned> primes;
    if (n <= 1) {
      return primes;
    }
    is_prime[0] = is_prime[1] = true;
    for (size_t i = 2; i <= n; i++) {
      if (!is_prime[i]) {
        primes.push_back(i);
      }
      for (size_t j = 0; i * primes[j] <= n; j++) {
        is_prime[i * primes[j]] = true;
        if (i % primes[j] == 0) break;
      }
    }
    delete[] is_prime;
    return primes;
  }
  /*
  找出前n个素数
  n:无符号整数
  返回值:vector
   */
  std::vector<unsigned> getnPrimes(unsigned n) {
    unsigned level = 0;
    for (size_t i = 0; i < 10; i++) {
      if (n <= primesunderk[i]) {
        level = i;
        break;
      }
    }
    unsigned bound = 1;
    while (level--) {
      bound *= 10;
    }
    std::vector<unsigned> upbound = Euler(bound);
    upbound.resize(n);
    return upbound;
  }
};

#endif