print("")

with open("Algorithmia\day1\input1.txt", "r") as f:
    inp = f.readline()

total = 0

for letter in inp:
    match letter:
        case "A":
            continue
        case "B":
            total += 1
        case "C":
            total += 3

print("Total:", total)
