
import math
import os
import random
import re
import sys

# Complete the superDigit function below.
def superDigit(n, k):
    pre_sum = 0

    for digit in str(n): # cut down the redundancy
        pre_sum += int(digit)

    pre_sum *= k

    return iterative_solve(pre_sum)

def iterative_solve(splitted):

    tmp_sum = 0
    while len(str(splitted)) != 1:
        tmp_sum = 0
        for digit in str(splitted):
            tmp_sum += int(digit)

        splitted = str(tmp_sum)

    return tmp_sum

if __name__ == '__main__':
    # fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nk = input().split()

    n = nk[0]

    k = int(nk[1])

    result = superDigit(n, k)
    print("Final answer ", result)
    # fptr.write(str(result) + '\n')

    # fptr.close()


