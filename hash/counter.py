from collections import Counter
lines = []
with open("uids.txt") as f:
    for line in f:
        lines.append(line.strip('\n'))

print Counter(lines).most_common(10000)
