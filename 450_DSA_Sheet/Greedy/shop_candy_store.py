def candyStore(self, candies,N,K):
    candies.sort()
    # for minimum case
    # first buy min candies and then get free candies of maximum price
    buy_min = 0
    free_min = N-1
    ans = [0]*2
    while(buy_min<=free_min):
        ans[0]+=candies[buy_min]
        free_min = free_min - K
        buy_min+=1
    # for maximum case
    # first buy max candies and then get free candies of minimum price
    buy_max = N-1
    free_max = 0
    while(free_max<=buy_max):
        ans[1]+=candies[buy_max]
        free_max = free_max + K
        buy_max-=1
    return ans