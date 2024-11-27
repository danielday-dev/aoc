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

def count_bonus_potions(idx):
    global inp

    xs = 0

    if inp[idx] == "x":
        xs += 1
    if inp[idx+1] == "x":
        xs += 1
    if inp[idx+2] == "x":
        xs += 1

    if xs < 1:
        return 6
    if xs < 2:
        return 2
    return 0


print("\n")

with open("Algorithmia\day1\input3.txt", "r") as f:
    inp = f.readline()


total = 0

for i in range(0, len(inp), 3):

    checkbattle(inp[i])

    checkbattle(inp[i+1])

    checkbattle(inp[i+2])

    total += count_bonus_potions(i)

print("Total:", total)

