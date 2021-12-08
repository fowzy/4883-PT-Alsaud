import sys
import time # Calculating the time
sys.setrecursionlimit(1000000)
start = time.time() # start my timer
# Bucket Sort in Python
def bucketSort(array):
    bucket = []

    # Create empty buckets
    for i in range(len(array)):
        bucket.append([])

    # Insert elements into their respective buckets
    for j in array:
        index_b = int(10 * j)
        bucket[index_b].append(j)

    # Sort the elements of each bucket
    for i in range(len(array)):
        bucket[i] = sorted(bucket[i])

    # Get the sorted elements
    k = 0
    for i in range(len(array)):
        for j in range(len(bucket[i])):
            array[k] = bucket[i][j]
            k += 1
    return array


array = []
fileName = str(input('Enter the file name: '))
file1 = open(fileName)
for x in file1.readlines():
    array.append(float(x))
print("Sorted Array in descending order is")
bucketSort(array)
print(f'Time in seconds : {time.time() - start}')
