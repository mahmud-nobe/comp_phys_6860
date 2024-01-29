```console
--- create the code file
ubuntu@ubuntu2204:problem_2$ touch projectile_dist.cxx

--- compile and linking the code file
ubuntu@ubuntu2204:problem_2$ g++ -o projectile_dist projectile_dist.cxx
ubuntu@ubuntu2204:problem_2$ ls
projectile_dist  projectile_dist.cxx

--- test 1
ubuntu@ubuntu2204:problem_2$ ./projectile_dist 
Please provide the following information about the projectile:
Initial Velocity (in meter/second): 10
Angle with the ground (in degree, between 0 to 180): 90
The horizontal distance in meter is: -0.00

--- test 2
ubuntu@ubuntu2204:problem_2$ ./projectile_dist 
Please provide the following information about the projectile:
Initial Velocity (in meter/second): 10
Angle with the ground (in degree, between 0 to 180): 10
The horizontal distance in meter is: 3.49

--- test 3
ubuntu@ubuntu2204:problem_2$ ./projectile_dist 
Please provide the following information about the projectile:
Initial Velocity (in meter/second): 10
Angle with the ground (in degree, between 0 to 180): 45
The horizontal distance in meter is: 10.19
```
