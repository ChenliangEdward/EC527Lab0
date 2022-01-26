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
![alt text](https://github.com/ChenliangEdward/EC527Lab0/blob/main/plots/matlabplot.png)

