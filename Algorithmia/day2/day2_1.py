print("\n")

with open("Algorithmia\day2\input1.txt") as f:
    inp = f.readlines()

words = inp[0][6:-1].split(",")
print(words)
inscription = inp[2].split(" ")
print(inscription)
total = 0

for word in words:
    for inscription_chunk in inscription:
        for i in range(0, len(inscription_chunk) - len(word) +1, 1):
            if inscription_chunk[i:i + len(word)] == word:
                total += 1

print("Total: ", total)