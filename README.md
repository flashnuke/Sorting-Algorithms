Sorting / searching algorithms written in CPP

# Sort Algorithms

## Bubble Sort

Sort the array by iterating over the elements, compare the current element with the next one and swap places if bigger. Repeat until all indices are iterated.
<br>The inner loop iterates till `n-1-iterations_count` because there's no need to access `n-iterations_count` after iterating for `iterations_count`, as the right elements are already there, starting from the last index and going down.<br>The `bubble_sort_efficient()` method is more efficient, because if during a full iteration no swap was performed (meaning the array is already sorted), the loop breaks.

#### Properties
* Time complexity - Best O(n) Average O(n<sup>2</sup>) Worst O(n<sup>2</sup>)
* Space complexity - O(1)
* Stability - Yes

## Selection Sort

Sort the array by iterating over the elements with another nested iteration, save the index of the minimum value (initialized as the current index of the outer iteration and if inside the nested iteration a smaller value is found, mark it as the new minimum index).<br>The nested `for-loop` starts from `i + 1` (where `i` is the index of the outer `for-loop`) since anything below that has been placed there previously.

#### Properties
* Time complexity - Best, Average and Worst O(n<sup>2</sup>)
* Space complexity - O(1)
* Stability - No

## Insertion Sort

Iterate (`for-loop`) over the array, and compare each element with the preceding element. If the preceding element is smaller, move it forward and compare again with the previous element.<br>Repeat (inner `while-loop`) until either the preceding element is not smaller then the current elememt, or the beginning of the array is reached and set the current value as the index of the last element that was moved forward in position.

#### Properties
* Time complexity - Best O(n), Average and Worst O(n<sup>2</sup>)
* Space complexity - O(1)
* Stability - Yes

## Merge Sort

A "divide and conquer" type of algorithm (where one big task is divided into many smaller tasks that are then solved and merged). Recursively split the array into 2 smaller subarrays, until at least one of the subarrays is of size 1. 
<br> Then enter the `merge()` method, that iterates over the two sub arrays (one of them is of size 1, the other is of maximum size 2), and merges them into one sorted array. While iterating, if one of the subarrays runs out of elements (meaning all of its elements have been sorted and merged already), then the remainder of the other array is fully merged at once.

#### Properties
* Time complexity - Best, Average and Worst O(log(n))
* Space complexity - O(n) (initializing subarrays in `merge()`)
* Stability - Yes (if elements are equal, the element from the first array is merged first)
