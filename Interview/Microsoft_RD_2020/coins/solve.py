def solution(n, m, coins):
    # dp[i]: least coin usage to reach target $i
    min_coins = 1 << 32
    dp = [min_coins for i in range(m + 1)]
    dp[0] = 0

    for i in range(1, m + 1):
        min_coins = 1 << 32
        for j in coins:
            # sub problem, just query the optimal solution of $(i - j)
            if i - j >= 0:
                min_coins = min(min_coins, dp[i - j] + 1)
        dp[i] = min_coins
    
    return dp[m] if dp[m] != 1 << 32 else -1

if __name__ == '__main__':
    t = int(input())
    while t:
        # IO
        t -= 1
        nm = input().split()
        n, m = int(nm[0]), int(nm[1])
        coins_str = input().split()

        coins_list = [int(i) for i in coins_str]
        # solve
        print(solution(n, m, coins_list))
