/* prime_lockless.c: brute-force prime finder (lockless) */

#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>

/* Macros */

#define max(a, b)   ((a) > (b) ? (a) : (b))

/* Constants */

const size_t NUM_THREADS = 8;
const size_t PRIME_MAX   = 400000;

/* Structure */

typedef struct {
    size_t start;
    size_t stop;
} PrimeArgs;

/* Functions */

size_t is_prime(size_t n) {
    for (size_t i = 2; i < n; i++) {
    	if (n % i == 0)
    	    return 0;
    }
    return 1;
}

/* Threads */

void * count_primes(void *arg) {
    PrimeArgs *pa = (PrimeArgs *)arg;
    size_t  count = 0;
    printf("start=%lu, stop=%lu\n", pa->start, pa->stop);
    for (size_t n = pa->start; n < pa->stop; n++) {
    	count += is_prime(n);
    }
    return (void *)count;
}

int main(int argc, char *argv[]) {
    pthread_t threads[NUM_THREADS];		    // Array of threads
    PrimeArgs args[NUM_THREADS];		    // Array of arguments
    size_t count = 0;

    for (size_t t = 0; t < NUM_THREADS; t++) {	    // Division of work
    	args[t].start = max(2, t*PRIME_MAX/NUM_THREADS);
    	args[t].stop  = (t+1)*PRIME_MAX/NUM_THREADS;
    	pthread_create(&threads[t], NULL, count_primes, &args[t]);
    }

    size_t thread_count = 0;
    for (size_t t = 0; t < NUM_THREADS; t++) {	    // Wait for threads
    	pthread_join(threads[t], (void **)&thread_count);
    	count += thread_count;
    }

    printf("There are %lu primes less than %ld\n", count, PRIME_MAX);
    return 0;
}
