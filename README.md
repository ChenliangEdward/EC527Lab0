# EC527 Lab0
Chenliang Wang\
edwangd@bu.edu\
Yuxuan Luo\
luoyx@bu.edu

## Part 1

### 1a.

- **What CPU are you using?** 
Intel(R) Core(TM) i7-9700 CPU @ 3.00GHz
- **What is the operating frequency of the cores?**
3.00GHz.
- **How many cores are there?**
8 cores.

### 1b.

- **How many levels of cache are there and what are the characteristics of each one?**
3 Levels of Cache, all have different capacities. L1 is the smallest and the fastest, integrated with the CPU
L2 and L3 are bigger in capacity and may be built between CPU and RAM. Their performance are slightly slower than L1 typically.
- **What is the microarchitecture of the processor cores?**
Coffee Lake. 
- **Are all of the cores real?**
Yes, there are 8 sibilings on each core and 8 cores total, so there is 1 processor per core, also all core ids are different so there is no virtual cores.
- **Can you find information online related to the machine's memory bandwidth? If so, what did
you find?**
The maximum bandwith of this processor is 41.6GB/s.
- **What is this processor's "Base Frequency" and "Turbo Frequency" in GHz?**
Base: 3GHz, Turbo: 4.7GHz

## Part2

### 2a.**How can you tell whether the timer is accurate?**

Scientists determine accuracy through comparing the experiment results with the correct theoretical value. The closer two values are, the more accurate the result would be. To determine the accuracy of a time measurement method, we need to start from the theoretical value of the processor. For example we can determine by getting the number of instructions during the runtime and multiply it with the time that a single instruction is processed. 
Since it's theoretical value, its accuracy should be very high.

### 2b.**The timer that uses RDTSC has some basic problems. Do an internet search to find out what they are.**

Given the fact that RDTSC counts the number of clock cycles, there are some problems converting that to time elapsed. First, the frequency of a CPU varies depend on the temprature. It might throttle or turbo based on the situation so counting the cycle might not be an actual reflection of time. 
it can be useful for benchmarking if it is used to average multiple attempts that take a non-trivial amount of time.

### 2c. **Each timer requires some calibration which may or may not have been done correctly in the source file.**

1. **For each timer, what (potentially) needs to be done?**
The `rdtsc()`'s constant needs to be changed, since its conversion (1.69s) is far different from other result (1.0s).
2. **As necessary, adjust the constants to give correct timing. (Note that all are trying to print values in units of seconds.)**
3. **Describe how you did this and the modification (if any) you made to test_timers.c**
Modified `CLK_RATE` from 2.0e9 to 3.0e9

### 2d 2e 2f. Please see code.

## Part3

### 3a.

Plot with SOffice

![P3catterPlot1](https://github.com/ChenliangEdward/EC527Lab0/blob/main/plots/plot1.png)
![P3ScatterPlot2](https://github.com/ChenliangEdward/EC527Lab0/blob/main/plots/plot2.png)
![P3ScatterPlot2_lines](https://github.com/ChenliangEdward/EC527Lab0/blob/main/plots/plot2_lines.png)
![P3ScatterPlot3](https://github.com/ChenliangEdward/EC527Lab0/blob/main/plots/plot3.png)
![P3ScatterPlot3_lines](https://github.com/ChenliangEdward/EC527Lab0/blob/main/plots/plot3_lines.png)

Matlab plot

![P3MatlabPlot](https://github.com/ChenliangEdward/EC527Lab0/blob/main/plots/matlabplot.png)

## Part4

### 4a. Reading

### 4b.**Add timing using clock_gettime() and diff() as in test_clock_gettime.c;and plot your results as discussed in the previous sections**

![P4Plot1](https://github.com/ChenliangEdward/EC527Lab0/blob/main/plots/part4plot.png)
![P4Plot2](https://github.com/ChenliangEdward/EC527Lab0/blob/main/plots/part4plot2.png)

### 4c.**You may notice some anomalies (making it impossible to draw a straight line through all the data points). What's a good way to get rid of them?**

A good way to avoid it is to make sure the CPU is running at a constant temperature so that the machine does not boost or restrict its  frequency.

### 4d.**How many cycles per element does it take on your computer for psum1 and psum2? Is it the same as in B&O’s Figure 5.2? If not, why might it be different?**


## Part5

### 5a. **Compile and run test_O_level.c as follows:**

Here is what's printed:

```
 Starting a loop
 done
real    0 m 0.563s
user    0 m 0.560s
sys     0 m 0.003s
```

### 5b. **Now generate the assembly language code of test_O_level.c with basic optimization:**

Here is what's printed:

```
 Starting a loop

 done

real    0m0.052s
user    0m0.048s
sys     0m0.002s
```

### 5c. **This time compile test_O_level.c as follows to generate the assembly language code:**

please see `test_O_levelO0.s`

### 5d. **Now generate the assembly language code of test_O_level.c with basic optimization:**

First, the code is significantly shorter than O0 assembly. Second, it seems that the loop is subtracting 200001 instead of adding like O0 assembly. Also, in the O1 assembly it is not modifying the value of quasi_random. 

### 5e. **You should have found something strange. Perhaps using the variable "quasi_random" will solve the problem (how?).**

```
 Starting a loop
-1.559369

 done

real    0m0.350s
user    0m0.346s
sys     0m0.003s
```

The code is taking 0.346s which is significantly larger than what was before but still less than the O0 Optimization.The code is optimized by replacing `jmp .L2` and improve the modification of `%rbp`.

## Part6

### 6a **Read the section in the textbook called "The Roofline Model" (Patterson & Hennesey section 6.10, probably in "PH_6_p2.pdf").**

Kernel2 has 8 times of arithmetic intensity than Kernel1. But kernel1 has a limited Memory BW. Kernel 2 has a limited computational power. 

### 6b **Read the stream.c code.**

### 6c **Compile and run. What is the memory bandwidth?**

The bandwidth varies from 11521 MB/s to 11673 MB/s, it is significantly smaller than the theoretical bandwidth.  

### 6d **Adjust the Arithmetic Intensity by modifying all of the lines marked “//Modify”, then recompile and rerun.**

### 6e

### 6f

## Part7

## 7a **Are you missing skills needed to carry out this assignment?**

It is hard for me to read and understand assemble.

## 7b **How long did this take (hours)?**

15Hours

## 7c **Did any part take an “unreasonable” amount of time for what it is trying to accomplish?**

Not really.

## 7d **Are there problems with the lab?**

Yes, the variable names are not consistent in part6.
