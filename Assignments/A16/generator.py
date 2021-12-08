import random
# RandomOrder
# for i in random.sample(range(10000,20001), 10000):
#     print(i)

# DescendingOrder
# for i in sorted(random.sample(range(10000,20001), 10000)):
#     print(i)

# AscendingOrder
for i in sorted(random.sample(range(10000,20001), 10000),reverse=True):
    print(i)

