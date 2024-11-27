def checkbattle(letter):
    global total
    match letter:
        case "A" | "x":
            total += 0
        case "B":
            total += 1
        case "C":
            total += 3
        case "D":
            total += 5

print("\n")

with open("Algorithmia\day1\input2.txt", "r") as f:
    inp = f.readline()


total = 0

for i in range(0, len(inp), 2):

    checkbattle(inp[i])

    checkbattle(inp[i+1])

    if inp[i] != "x" and inp[i+1] != "x":
        total += 2

print("Total:", total)

