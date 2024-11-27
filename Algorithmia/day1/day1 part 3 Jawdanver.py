print("\n")
with open("Algorithmia\day1\input3.txt", "r") as f:
    inp = f.readline()



STRIDE = 3

total = 0
for c in inp:
    match (c):
        case 'B': total += 1
        case 'C': total += 3
        case 'D': total += 5

for i in range(0, len(inp), STRIDE):
    count = STRIDE - inp[i:i+STRIDE].count('x')
    if (count > 0):
        total += count * (count - 1)

print(total)