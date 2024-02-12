```console
--- create the code file
ubuntu@ubuntu2004:problem2$ touch mean_std_array.cxx
ubuntu@ubuntu2004:problem2$ xdg-open mean_std_array.cxx

--- compile and linking the code file
ubuntu@ubuntu2004:problem2$ g++ -o mean_std_array mean_std_array.cxx 
ubuntu@ubuntu2004:problem2$ ls
mean_std_array mean_std_array.cxx

--- test
ubuntu@ubuntu2004:problem2$ ./mean_std_array 
What is the length of your array: 10
The random unsorted array: 
37 38 37 26 8 28 12 24 32 38 
Mean: 28
Standard Deviation: 10.2665

ubuntu@ubuntu2004:problem2$ ./mean_std_array 
What is the length of your array: 15
The random unsorted array: 
48 10 24 31 10 16 15 15 29 19 22 46 7 5 50 
Mean: 23.1333
Standard Deviation: 14.366

ubuntu@ubuntu2004:problem2$ ./mean_std_array 
What is the length of your array: 4
The random unsorted array: 
39 46 5 12 
Mean: 25.5
Standard Deviation: 17.3566

ubuntu@ubuntu2004:problem2$ ./mean_std_array 
What is the length of your array: 2
The random unsorted array: 
10 34 
Mean: 22
Standard Deviation: 12
```
