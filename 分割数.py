def split_num(n, m, M):
    """
    最大n個を最大m分割(mod M)

    dp : list, shape = [m+1, n+1]
        dp[i][j] : j個をi分割
    """
    dp = [[0 for _ in range(n+1)] for _ in range(m+1)]
    dp[0][0] = 1
    for i in range(1, m+1):
        for j in range(n+1):
            if j >= i:
                dp[i][j] = (dp[i-1][j] + dp[i][j-i]) % M
            else:
                dp[i][j] = dp[i-1][j]
    return dp
