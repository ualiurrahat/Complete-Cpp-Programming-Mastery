/**
 * @file 01_SumHeader.cpp
 * @brief Header – declares the function and **global variables**.
 *
 * @note `extern int visibile_anywere;` – one definition in `sum.cpp`.
 * @note `static int st_gl_per_include = 0;` – **separate copy** for *every* translation unit that includes this header.
 */

#ifndef SUM_H_
#define SUM_H_

/** @brief Global counter shared across all translation units. */
extern int visibile_anywere;

/**
 * @brief Static variable created **per translation unit** that includes this header.
 *
 * @warning Each .cpp file gets its own copy – usually **not what you want**.
 */
static int st_gl_per_include = 0;

/**
 * @brief Sums 0 … (n-1) and updates all counters.
 *
 * @param n Upper bound (exclusive).
 * @return int The sum.
 */
int sum_1_n(int n);

#endif /* SUM_H_ */