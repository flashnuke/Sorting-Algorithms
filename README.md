Sorting / searching algorithms written in CPP

# Sort Algorithms

## Bubble Sort

Sort the array by iterating over the elements, compare the current element with the next one and swap places if bigger. Repeat until all indices are iterated.
<br>The inner loop iterates till `n-1-iterations_count` because there's no need to access `n-iterations_count` after iterating for `iterations_count`, as the right elements are already there, starting from the last index and going down.<br>The `bubble_sort_efficient()` method is more efficient, because if during a full iteration no swap was performed (meaning the array is already sorted), the loop breaks.

#### Properties
* Time complexity - Best O(n) Average O(n<sup>2</sup>) Worst O(n<sup>2</sup>)
* Space complexity - O(1)
* Stability - Yes
