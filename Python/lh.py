import math

# 1.输入两个double类型的数据
a = float(input())
b = float(input())

# 2.计算他们的和

c = 5 * a + 2 * b

n = float((input()))

week = math.floor(n / c)
n = n - week * c
sum = week * 7

day = 1
while n > 0:
    if day <= 5:
        n -= a
    else:
        n -= b
    
    day += 1
    sum += 1

# 3.输出
print(sum)

# 161,705,710,706,215 + 246,284,262,426,904  407,989,973,133,119

# 32341142141243
# 123142131213452
# 1231245266546423424
