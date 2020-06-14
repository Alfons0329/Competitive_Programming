class Solution:
    def bestRotation(self, arr):
        best = 0
        shift = 0
        total_len = len(arr)
        for i in range(total_len):
            sc = 0
            # print(arr)
            for j in range(len(arr)):
                if arr[j] <= j:
                    sc += 1

                    # print('sc ',sc)
                    if sc > best:
                        best = sc
                        shift = i
            tmp = arr[0]
            arr = arr[1:]
            arr.append(tmp)

        return shift
