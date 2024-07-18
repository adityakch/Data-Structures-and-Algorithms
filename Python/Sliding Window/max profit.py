def max_profit(prices):
    max_profit = 0
    min_price = prices[0]

    for price in prices:
        min_price = min(min_price, price)
        max_profit = max(max_profit, price - min_price)

    return max_profit




prices = [10,1,5,6,7,1]
print(max_profit(prices))