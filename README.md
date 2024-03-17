This is a program that estimates the value of PI using the Monte Carlo method using the MPI library written in C++. 

Results when running on the University HPC environment: 

![image](https://github.com/johnathanmitri/HPC-Monte-Carlo-using-MPI/assets/28831749/e3e6ea14-2a6c-4470-9dc6-2217d4a48f6d)

![image](https://github.com/johnathanmitri/HPC-Monte-Carlo-using-MPI/assets/28831749/4a88ad5a-98a1-4c12-b0bd-75e6c20875ca)

<br>

When a circle is inscribed in a square, the area of the circle is $`πr^2`$, and the area of the square is $`2r*2r`$. If we use a radius of r = 1, the ratio of the circle's area to the square's area is $\frac{π}{4}$.

The ratio of the circle's area to the square's area can be approximated by generating points with random X and Y values between 0 and 1, and tracking how many of these points land within the circle using the Pythagorean theorem. 

![image](https://github.com/johnathanmitri/HPC-Monte-Carlo-using-MPI/assets/28831749/205cce76-2588-40a3-a64f-e1d7711384a1)

If  $`x^2+y^2≤1`$, then the point is in the circle. If not, then it is only inside the square. 

The ratio of points within the circle to those within both the circle and the square is equal to the ratio of the circle's area to the square's ratio. 

In other words, this ratio equals $\frac{π}{4}$.

So, by multiplying the ratio we calculate by 4, we are able to solve for PI to approximate its values. 


