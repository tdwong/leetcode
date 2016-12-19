### NOT MY IMPLEMENTATION ###

#https://www.hackerrank.com/challenges/quicksort3

# original link:
#   https://www.hackerrank.com/challenges/quicksort3/forum/comments/101090
#

n = int(raw_input())
ar = [int(x) for x in raw_input().split()]

def swap(arr,x,y):
    mem = arr[x]
    arr[x] = arr[y]
    arr[y] = mem
    return arr

def qsort(ar,start,end):
    # base case
    if end-start <= 0:
        return ar
    # pivot
    pivot = ar[end]
    # init index for pivot
    ind = start
    # loop less final value (pivot)
    for i in xrange(start,end):
        if ar[i] <= pivot:
            ar = swap(ar,i,ind)
            ind += 1
        else:
            pass
    swap(ar,ind,end)
    print ' '.join(str(x) for x in ar)
    # left side
    ar = qsort(ar,start,ind-1)
    # right side
    ar = qsort(ar,ind+1,end)
    return ar
    
qsort(ar,0,n-1)

