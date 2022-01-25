compile:
	gcc -O0 test_timers.c -lm -o test_timers
	gcc -O0 test_clock_gettime.c -lm -lrt -o test_clock_gettime

