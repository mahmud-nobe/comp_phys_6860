```console
--- create the code file
ubuntu@ubuntu2004:hw2$ touch bubble_sort.cxx
ubuntu@ubuntu2004:hw2$ xdg-open bubble_sort.cxx

--- compile and linking the code file
ubuntu@ubuntu2004:problem1$ g++ -o bubble_sort bubble_sort.cxx 
ubuntu@ubuntu2004:problem1$ ls
bubble_sort bubble_sort.cxx

--- test
ubuntu@ubuntu2004:problem1$ ./bubble_sort 
The random unsorted array: 
85 45 43 15 28 87 53 67 26 41 18 60 82 21 44 28 28 63 61 98 

The sorted array: 
15 18 21 26 28 28 28 41 43 44 45 53 60 61 63 67 82 85 87 98 

ubuntu@ubuntu2004:problem1$ ./bubble_sort 
The random unsorted array: 
3 2 48 72 92 17 21 84 8 92 27 9 73 23 65 77 29 59 42 22 

The sorted array: 
2 3 8 9 17 21 22 23 27 29 42 48 59 65 72 73 77 84 92 92 

ubuntu@ubuntu2004:problem1$ ./bubble_sort 
The random unsorted array: 
2 69 94 9 49 3 68 22 37 66 99 1 77 73 27 93 70 2 78 44 

The sorted array: 
1 2 2 3 9 22 27 37 44 49 66 68 69 70 73 77 78 93 94 99
```
