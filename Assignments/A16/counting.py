import sys
import time # Calculating the time
sys.setrecursionlimit(20000)
start = time.time() # start my timer
# Counting sort in Python programming
def countingSort(array):
    size = len(array)
    output = [0] * size

    # Initialize count array
    count = [0] * 10

    # Store the count of each elements in count array
    for i in range(0, size):
        count[array[i]] += 1

    # Store the cummulative count
    for i in range(1, 10):
        count[i] += count[i - 1]

    # Find the index of each element of the original array in count array
    # place the elements in output array
    i = size - 1
    while i >= 0:
        output[count[array[i]] - 1] = array[i]
        count[array[i]] -= 1
        i -= 1

    # Copy the sorted elements into original array
    for i in range(0, size):
        array[i] = output[i]


data = []
fileName = str(input('Enter the file name: '))
file1 = open(fileName)
for x in file1.readlines():
    data.append(int(x))
countingSort(data)
print("Sorted Array in Ascending Order:")
print(f'Time in seconds : {time.time() - start}')

# print(data)