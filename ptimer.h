#ifndef PTIMER_H
#define PTIMER_H

#include <stdio.h>
#include <time.h>

struct ptimer_interval {
    struct timespec start;
    struct timespec end;
};

static int ptimer_start(struct ptimer_interval *pti)
{
    return clock_gettime(CLOCK_MONOTONIC, &pti->start);
}

static int ptimer_end(struct ptimer_interval *pti)
{
    return clock_gettime(CLOCK_MONOTONIC, &pti->end);
}

static inline unsigned long long ptimer_timespec_to_nsec(struct timespec ts)
{
    return ts.tv_sec * 1000000000ULL + ts.tv_nsec;
}

static unsigned long long ptimer_get_nsec(struct ptimer_interval *pti)
{
    unsigned long long start = ptimer_timespec_to_nsec(pti->start);
    unsigned long long end = ptimer_timespec_to_nsec(pti->end);
    return end - start;
}

static int ptimer_fprint(FILE *fp, const char *msg, struct ptimer_interval *pti)
{
    return fprintf(fp, "%s%g s\n", msg, ptimer_get_nsec(pti) * 1e-9);
}

#endif
