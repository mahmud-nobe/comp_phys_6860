```console
--- create the code file
ubuntu@ubuntu2004:hw2$ touch secant_diff.cxx
ubuntu@ubuntu2004:hw2$ xdg-open secant_diff.cxx

--- compile and linking the code file
ubuntu@ubuntu2004:hw2$ g++ -o secant_diff secant_diff.cxx 
ubuntu@ubuntu2004:hw2$ ls
secant_diff  secant_diff.cxx 

--- test 1
ubuntu@ubuntu2004:hw2$ ./secant_diff 
Please provide the stepsize, h: 0.005

At x = 0
Analytical soln: 1
Numerical Soln: 0.999996
Relative Error: 4.16666e-06

At x = 0.785398
Analytical soln: 0.707107
Numerical Soln: 0.705336
Relative Error: 0.00250416

At x = 1.5708
Analytical soln: 6.12323e-17
Numerical Soln: -0.00249999
Relative Error: 4.0828e+13

At x = 2.35619
Analytical soln: -0.707107
Numerical Soln: -0.708872
Relative Error: -0.00249583

At x = 3.14159
Analytical soln: -1
Numerical Soln: -0.999996
Relative Error: -4.16666e-06

--- test 2
ubuntu@ubuntu2004:hw2$ ./secant_diff 
Please provide the stepsize, h: 0.001

At x = 0
Analytical soln: 1
Numerical Soln: 1
Relative Error: 1.66667e-07

At x = 0.785398
Analytical soln: 0.707107
Numerical Soln: 0.706753
Relative Error: 0.000500167

At x = 1.5708
Analytical soln: 6.12323e-17
Numerical Soln: -0.0005
Relative Error: 8.16562e+12

At x = 2.35619
Analytical soln: -0.707107
Numerical Soln: -0.70746
Relative Error: -0.000499833

At x = 3.14159
Analytical soln: -1
Numerical Soln: -1
Relative Error: -1.66667e-07

--- test 3
ubuntu@ubuntu2004:hw2$ ./secant_diff 
Please provide the stepsize, h: 0.1

At x = 0
Analytical soln: 1
Numerical Soln: 0.998334
Relative Error: 0.00166583

At x = 0.785398
Analytical soln: 0.707107
Numerical Soln: 0.670603
Relative Error: 0.0516242

At x = 1.5708
Analytical soln: 6.12323e-17
Numerical Soln: -0.0499583
Relative Error: 8.15882e+14

At x = 2.35619
Analytical soln: -0.707107
Numerical Soln: -0.741255
Relative Error: -0.0482925

At x = 3.14159
Analytical soln: -1
Numerical Soln: -0.998334
Relative Error: -0.00166583

--- test 4
ubuntu@ubuntu2004:hw2$ ./secant_diff
Please provide the stepsize, h: 0.00001

At x = 0
Analytical soln: 1
Numerical Soln: 1
Relative Error: 1.66668e-11

At x = 0.785398
Analytical soln: 0.707107
Numerical Soln: 0.707103
Relative Error: 5.00001e-06

At x = 1.5708
Analytical soln: 6.12323e-17
Numerical Soln: -5e-06
Relative Error: 8.16562e+10

At x = 2.35619
Analytical soln: -0.707107
Numerical Soln: -0.70711
Relative Error: -4.99999e-06

At x = 3.14159
Analytical soln: -1
Numerical Soln: -1
Relative Error: -1.01156e-11

```
