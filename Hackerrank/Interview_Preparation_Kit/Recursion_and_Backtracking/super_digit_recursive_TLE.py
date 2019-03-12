
import math
import os
import random
import re
import sys

# Complete the superDigit function below.
def superDigit(n, k):
    return recursive_solve(str(n) * k)

def recursive_solve(splitted):
    if len(str(splitted)) == 1:
        print("Final answer ", int(splitted))
        return int(splitted)

    tmp_sum = 0
    for digit in str(splitted):
        tmp_sum += int(digit)

    return recursive_solve(tmp_sum)

if __name__ == '__main__':

    nk = input().split()

    n = nk[0]

    k = int(nk[1])

    result = superDigit(n, k)

    # fptr.write(str(result) + '\n')

    # fptr.close()


