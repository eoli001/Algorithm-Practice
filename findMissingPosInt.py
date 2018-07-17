# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # write your code in Python 3.6
    x=1
    A.sort()
    for i in range(0,len(A)):
        if(A[i] > x):
            return x
        elif(x <= A[i]):
            x=x+1
    return x


    [1,1,3]