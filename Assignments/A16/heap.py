import time # Calculating the time
start = time.time() # start my timer

# Heap Sort in python


def heapify(arr, n, i):
    # Find largest among root and children
    largest = i
    l = 2 * i + 1
    r = 2 * i + 2

    if l < n and arr[i] < arr[l]:
        largest = l

    if r < n and arr[largest] < arr[r]:
        largest = r

    # If root is not largest, swap with largest and continue heapifying
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)


def heapSort(arr):
    n = len(arr)

    # Build max heap
    for i in range(n//2, -1, -1):
        heapify(arr, n, i)

    for i in range(n-1, 0, -1):
        # Swap
        arr[i], arr[0] = arr[0], arr[i]

        # Heapify root element
        heapify(arr, i, 0)


arr = []
fileName = str(input('Enter the file name: '))
file1 = open(fileName)
for x in file1.readlines():
    arr.append(float(x))
heapSort(arr)
n = len(arr)
print("Sorted array is")
print(f'Time in seconds : {time.time() - start}')

# for i in range(n):
#     print("%d " % arr[i], end='')
