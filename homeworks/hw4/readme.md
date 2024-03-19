## Homework 4

### Complex Number Class

Class implementation of complex number

#### Members:
- a: real value
- b: imaginary value

#### Member Functions:
- Print: show the complex number in its ideal form and its real and imaginary parts
- abs_value: return the absolute value (i.e. the magnitude) of the complex numbers

#### Operators:
- **+** complex number addition $(a+bi) + (c+di) = (a+b) + (c+d)i$
- **+=** complex number addition (in place)
- **-** complex number subtraction $(a+bi) - (c+di) = (a-b) + (c-d)i$
- **-=** complex number subtraction (in place)
- $\textbf{*}$ complex number multiplication $(a+bi) \cdot (c+di) = (ac-bd) + (ad+bc)i$
- $\textbf{*=}$ complex number multiplication (in place)
- **/** complex number division $\frac{a+bi}{c+di} = \frac{ac+bd}{c^2+d^2} + \frac{bc-ad}{c^2+d^2}i$
- **/=** complex number division (in place)
