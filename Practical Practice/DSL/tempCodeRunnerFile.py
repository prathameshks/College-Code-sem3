
def fibonacci_search(arr, key):
    n = len(arr)
    start = -1
    fibo = [0, 1]
    m = 1
    while (fibo[m] < n):
        fibo.append(fibo[m]+fibo[m-1])
        m+=1

    while (fibo[m] >= 0):
        i = min(start+fibo[m-2], n-1)

        if (arr[i] < key):
            start = i
            m -= 2
        elif (arr[i] > key):
            m -= 1
        else:
            return i
    return -1


def fibonacci_search_withvars(arr, key):
    n = len(arr)
    start = -1
    fibom2 = 0
    fibom1 = 1
    fibom = 1
    while (fibom < n):
        fibom += fibom1
        fibom2 = fibom1
        fibom1 = fibom - fibom1

    while (fibom > 0):
        i = min(start+fibom2, n-1)

        if (arr[i] < key):
            start = i
            fibom = fibom2
            fibom1 -= fibom2
            fibom2 = fibom - fibom1
        elif (arr[i] > key):
            fibom2 = fibom1 - fibom2
            fibom1 = fibom - fibom1
            fibom = fibom1 + fibom2
        else:
            return i
    return -1


ar = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
for i in range(10):
    print(fibonacci_search(ar, ar[i]))
