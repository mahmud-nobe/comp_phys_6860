```console
(root_env) ubuntu@ubuntu2204:problem2$ g++ -o pendulum pendulum.cxx -lgsl -lgslcblas `root-config --cflags --libs`
(root_env) ubuntu@ubuntu2204:problem2$ ./pendulum 

This program numerically solves the Pendulum Equations

Input data: 
Initial values theta = 2.14737 phi = 0 
 Parameters: g= 9.1 l= 1 
 Starting step size (h): 0.000
 Time parameters: 0.000 40.000 0.010 
 Absolute  and relative error requested: 1.000e-08 1.000e-10 
 Number of equations (dimension): 2 

 Time   theta   phi   
0.000  2.147  0.000 
1.000  -1.296  -3.855 
2.000  -0.942  4.542 
18.000  1.107  -4.250 
19.000  -2.139  0.356 
20.000  1.466  3.439 
21.000  0.723  -4.855 
22.000  -2.082  1.011 
23.000  1.723  2.676 
24.000  0.297  -5.227 
25.000  -1.968  1.696 
26.000  1.917  1.937 
27.000  -0.148  -5.284 
28.000  -1.795  2.423 
29.000  2.050  1.238 
30.000  -0.583  -5.012 
31.000  -1.560  3.182 
32.000  2.126  0.575 
33.000  -0.983  -4.474 
34.000  -1.260  3.935 
35.000  2.147  -0.070 
36.000  -1.331  -3.775 
37.000  -0.900  4.608 
38.000  2.114  -0.716 
39.000  -1.616  -3.016 

(root_env) ubuntu@ubuntu2204:problem2$ root plot.C 
   ------------------------------------------------------------------
  | Welcome to ROOT 6.30/04                        https://root.cern |
  | (c) 1995-2024, The ROOT Team; conception: R. Brun, F. Rademakers |
  | Built for linuxarm64 on Feb 07 2024, 00:33:26                    |
  | From heads/master@tags/v6-30-04                                  |
  | With                                                             |
  | Try '.help'/'.?', '.demo', '.license', '.credits', '.quit'/'.q'  |
   ------------------------------------------------------------------

root [0] 
Processing plot.C...
Info in <TCanvas::Print>: ps file Pendulum Histogram of theta and theta' has been created
root [1] .x plot.C 
Info in <TCanvas::Print>: file Pendulum Histogram of theta and theta'.png has been created
root [2] .q
```
