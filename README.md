# C_Programs
A collection of different C programs I have implemented each with a different purpose.

## Sorting
There are three sorting algorithms implemented that one will find within this repository. The first two are within the sorting file which contains a simple swap method that just swaps the value of two integers based on their pointers. 

### Insertion Sort
The first sorting algorithm implemented is an insertion sort. Insertion sort is a simple algorithm that builds the final sorted array one value at a time. It inserts the item where it should be and then pushes everything down one slot in the array. It is not very efficent for solving arrays that contain a large amount of items as it runs in O(n^2) time. An example of how it works can be found below.

<p align="center">
  <img width="460" height="300" src="https://user-images.githubusercontent.com/35609863/61492600-ad016000-a97f-11e9-9bd9-b5c053d47994.png">
</p>

### Selection Sort
The second implemented sorting algorithm is selection sort. Selection sort works by continously finding the minimum value and placing it at the start. Once that is found, then it works in ascending order to find the next element and then place it one spot infront of the previous element. Once again, the runtime is O(n^2) as the algorithm needs to iterate through the list multiple times through. An example of how it works can be found below.

<p align="center">
  <img width="460" height="300" src="https://user-images.githubusercontent.com/35609863/61492674-d3bf9680-a97f-11e9-8470-9a5bc15bce28.png">
</p>

### Bucket Sort
The final implemented sorting algorithm is in it's own file called bucket.c. This file contains bucket sort implemented on an array size n. The way this works is by grouping together all the values within either a certain range, value, property, etc... Once everything is sorted in it's proper grouping, then it is all grouped back together and sorted in the order desired. The average time complexity of bucket sort is O(n + k). An example of bucket sort can be found below. 

<p align="center">
  <img width="460" height="300" src="https://user-images.githubusercontent.com/35609863/61493234-10d85880-a981-11e9-8374-a620391fbaa7.png">
</p>



## Citations
Insertion sort: https://www.geeksforgeeks.org/insertion-sort/

Selection sort: https://www.hackerearth.com/practice/algorithms/sorting/selection-sort/tutorial/

Bucket sort: https://medium.com/karuna-sehgal/an-introduction-to-bucket-sort-62aa5325d124
