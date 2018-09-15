"""
Only the O(N) solution will pase the test, not the O(N^2) brute force solution which leads to TLE
Algorithm:
For example: [2,3,1,4,0]
There are two types of the situation
Case1: value > index
The easiest way is just shift the number to the rightmost, we shift index+1 so it will be the rightmost, definitely gets the score


Case2: value <= index
This situation will originally gets score, so if we shift it right, it can still gets the score due to increase the index.
So the first interval is [index+1 (to the rightmost), len - 1(to its right in the last shift)]
Now we just have to focus on shift left. we can shift at most index - value, so the second interval is [0, index-value]
"""
class Solution:
    def bestRotation(self, arr):
        best = 0
        shift = 0
        total_len = len(arr)
        #start_pos_arr = []
        pair = []
        #initial the start_pos_arr to record the starting position of the given array
        #initial score
        for index, value in enumerate(arr):
            if index < value: #one segment for this ones
                pair.append([index + 1 ,total_len - (value - index)]) #segment start and end
            else: #two segments for this one
                pair.append([index + 1, total_len - 1])
                pair.append([0, index - value])


        segment_query = [0] * (total_len + 1)  #aux arrat for the prefix sum, segment query
        for i in range (len(pair)): #+1 padding
            segment_query[pair[i][0]] += 1 #go in the interval, overlapping with all the other segment
            segment_query[pair[i][1] + 1] -= 1 #leave the interval, cancelling the infulence of segment overlapping

        cur_pts = 0
        for i in range (len(segment_query)):
             cur_pts += segment_query[i]
             if( cur_pts > best):
                 best = cur_pts
                 shift = i

        return shift
