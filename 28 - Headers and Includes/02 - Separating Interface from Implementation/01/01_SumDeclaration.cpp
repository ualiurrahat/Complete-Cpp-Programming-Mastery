/**
 * @file 01_SumDeclaration.cpp
 * @brief Header file – **declaration only** (what, not how).
 *
 * @note This file is included by both the implementation and the client.
 * @note Include guards (`#ifndef … #define … #endif`) prevent multiple inclusion.
 */

#ifndef SUM_H_
#define SUM_H_

/**
 * @brief Calculates the sum of integers from 0 to n-1.
 *
 * @param n Upper bound (exclusive).
 * @return int Sum of 0 … (n-1).
 */
int sum_1_n(int n);

#endif /* SUM_H_ */