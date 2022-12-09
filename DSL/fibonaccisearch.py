def get_fibo(n):
    seq = [0, 1]
    elm = 1
    while (elm < n):
        elm = seq[-1]+seq[-2]
        seq.append(elm)
    return seq


def fibo_search(arr, key, n):
    fibo = get_fibo(n)
    m = len(fibo)-1

    offset = -1

    while (m > 2):
        i = min(offset+fibo[m-2], n-1)

        if key > arr[i]:
            m -= 1
            offset = i
        elif key < arr[i]:
            m -= 2
        else:
            return i

    return -1


arr = [1, 2, 4, 6, 7, 9, 10, 13, 15, 17, 19, 22]
n = len(arr)

print(fibo_search(arr, 1, n))
