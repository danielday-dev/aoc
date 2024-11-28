print("\n")

with open("Algorithmia\day2\input2.txt") as f:
    inp = f.readlines()

words = inp[0][6:-1].split(",")
# print(words)
inscription = inp[2:]
# print(inscription)

inscription_map = []

for i in range(len(inscription)):
    #remove \n jic
    inscription[i] = inscription[i][:-1]
    inscription_map.append([])
    for j in range(len(inscription[i])):
        #add bitmask to each letter
        # inscription[i][j] = [inscription[i][j], 0]
        inscription_map[i].append(0)

total = 0

for word in words:
    for chunk_counter in range(len(inscription)):
        for i in range(0, len(inscription[chunk_counter]) - len(word) +1, 1):
            if inscription[chunk_counter][i:i + len(word)] == word:
                for symbol_counter in range(len(word)):
                    inscription_map[chunk_counter][i + symbol_counter] = 1

        backwards_chunk = inscription[chunk_counter][::-1]
        inscription_map[chunk_counter] = inscription_map[chunk_counter][::-1]

        for i in range(0, len(backwards_chunk) - len(word) +1, 1):
            if backwards_chunk[i:i + len(word)] == word:
                for symbol_counter in range(len(word)):
                    inscription_map[chunk_counter][i + symbol_counter] = 1

        inscription_map[chunk_counter] = inscription_map[chunk_counter][::-1]


for chunk_counter in range(len(inscription_map)):

    total += inscription_map[chunk_counter].count(1)
    # print(inscription_map[chunk_counter].count(1))

print("Total: ", total)