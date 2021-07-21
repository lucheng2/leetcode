import random

n = random.randint(10, 20);
test = []
for i in range(n):
    test.append(random.randint(0, 10))
print(n)
print(' '.join(map(str, test)))

