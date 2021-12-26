from cs50 import get_int
incorrect_input = True

while incorrect_input:
    h  = get_int("Height: ")
    if ((h >= 1) and (h <=8)):
        incorrect_input = False
    else:
        continue

for i in range(1, h+1):
    print(f"{' ' * (h - i)}{'#' * i}  {'#' * i}")