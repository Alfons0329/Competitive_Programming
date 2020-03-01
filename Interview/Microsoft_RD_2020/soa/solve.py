if __name__ =='__main__':
    n = int(input())
    a = input().split()
    a_int = []
    for i in range(n):
        a_int.append(int(a[i]))
    print(sum(a_int[0 for i in range(n)]))
