/**
 * @file 01_SumHeader.cpp
 * @brief Header – declaration of function and **extern** global variable.
 *
 * @note `extern int total_calls;` promises a definition elsewhere.
 * @note Include guards prevent multiple inclusion.
 */

#ifndef SUM_H_
#define SUM_H_

/** @brief Global counter for how many times `sum_1_n` is called. */
extern int total_calls;

/**
 * @brief Sums integers from 0 to n-1 and increments `total_calls`.
 *
 * @param n Upper bound (exclusive).
 * @return int Sum of 0 … (n-1).
 */
int sum_1_n(int n);

#endif /* SUM_H_ */