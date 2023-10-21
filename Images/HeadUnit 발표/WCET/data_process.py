lst1 = []
lst2 = []
lst3 = []
lst4 = [[0.0001 * i, 0] for i in range(40)]

file = open('delay.txt', 'r')

for line in file:
    lst1.append(line.strip())

file.close()

for i in range(len(lst1) - 1):
    if not lst1[i].startswith('2023') and not lst1[i + 1].startswith('2023'):
        lst2.append((float(lst1[i]), float(lst1[i + 1])))

for item in lst2:
    lst3.append(max(item) - min(item))

cnt = 0
for item in lst3:
    if item <= 0.0005:
        cnt += 1
print(cnt)

print(min(lst3), max(lst3))

for item in lst3:
    for i in range(40):
        if 0.0001 * i <= item < 0.0001 * (i + 1):
            lst4[i][1] += 1
            break

file = open('clean.txt', 'w')

for a, b in lst4:
    file.write(str(a) + ' ' + str(b) + '\n')

file.close()

# total 967
# within 0.5ms = 822
