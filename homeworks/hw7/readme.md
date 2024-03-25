## Homework 7

### 1. Matrix Manipulation

Use the GSL manual to read up how to define and manipulate matrices.

Calculate the determinate and the inverse of the test matrix:

```math
\begin{pmatrix}
  1 & 3 & 3\\
  1 & 4 & 3\\
  1 & 3 & 4\\
\end{pmatrix}
```
### 2. The Pendulum

Implement/solve the pendulum with GSL and compare to the small angle approximation. Play around and make and estimate how small “small” needs to be, assume a meter pendulum L=1.

```math
\begin{align*}
  \frac{d^2\theta}{dt^2} + \frac{g}{l} \sin \theta &= 0\\
  \frac{d^2\theta}{dt^2} + \frac{g}{l} \theta &= 0\\
  \text{as for, }\theta << 1 \text{, } \quad \sin \theta &\approx \theta
\end{align*}
```
