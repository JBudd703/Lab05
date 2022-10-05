"""
Lab 04 - Time Complexity & Profiling
Written by Jack Budd and Jonathan Xavioer
Section 28121
"""

import time
from stringdata import get_data

dataset = get_data()

#Linear search searches the list one by one for the element, starting at position 0 in the list and going until the
#element is found.
def linear_search(container, element):
    print('Linear Search for', element)
    start_time = time.time()
    for i in range(len(container)): #Iterates through data set
        if container[i] == element: #Checks to see if the element at the index is the word we're looking for
            end_time = time.time()
            time_elapsed = end_time - start_time #Calculates time taken
            print('Time:', time_elapsed)
            return i #Returns index
    end_time = time.time()
    time_elapsed = end_time - start_time
    print('Time:', time_elapsed)
    return -1

#Binary search searches the list by dividing the list in two and determining if the element is in the top or bottom half
#of the list. Once this is determined, that half will be divided into two more halves. This will happen until the
#element is found as the midpoint.
def binary_search(container, element):
    print('Binary Search for', element)
    start_time = time.time()
    minIndex = 0
    maxIndex = len(container) - 1
    midIndex = int((minIndex + (maxIndex - minIndex) / 2)) #Midpoint index is the average of the max and the min indices, plus the min index

    while minIndex <= maxIndex:
        if element == dataset[midIndex]:
            end_time = time.time()
            time_elapsed = end_time - start_time
            print("Time: ", time_elapsed)
            return midIndex
        elif element > dataset[midIndex] and element < dataset[midIndex + 1]: #Catches case where the element doesn't actually exist
            end_time = time.time()
            time_elapsed = end_time - start_time
            print('Time:', time_elapsed)
            return -1
        elif element < dataset[midIndex]:
            maxIndex = midIndex
            midIndex = int((minIndex + (maxIndex - minIndex) / 2))
            continue
        elif element > dataset[midIndex]:
            minIndex = midIndex
            midIndex = int((minIndex + (maxIndex - minIndex) / 2))
            continue


def main():
    print(linear_search(dataset, 'not_here'), '\n')
    print(binary_search(dataset, 'not_here'), '\n')

    print(linear_search(dataset, 'mzzzz'), '\n')
    print(binary_search(dataset, 'mzzzz'), '\n')

    print(linear_search(dataset, 'aaaaa'), '\n')
    print(binary_search(dataset, 'aaaaa'), '\n')

if __name__ == '__main__':
    main()