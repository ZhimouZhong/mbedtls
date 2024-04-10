/*
 *  Query Mbed TLS compile time configurations from mbedtls_config.h
 *
 *  Copyright The Mbed TLS Contributors
 *  SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later
 */

#ifndef MBEDTLS_PROGRAMS_TEST_QUERY_CONFIG_H
#define MBEDTLS_PROGRAMS_TEST_QUERY_CONFIG_H

#include "mbedtls/build_info.h"

/** Check whether a given configuration symbol is enabled.
 *
 * \param config    The symbol to query (e.g. "MBEDTLS_RSA_C").
 * \return          \c 0 if the symbol was defined at compile time
 *                  (in MBEDTLS_CONFIG_FILE or mbedtls_config.h),
 *                  \c 1 otherwise.
 *
 * \note            This function is defined in `programs/test/query_config.c`
 *                  which is automatically generated by
 *                  `scripts/generate_query_config.pl`.
 */
int query_config(const char *config);

/** List all enabled configuration symbols
 *
 * \note            This function is defined in `programs/test/query_config.c`
 *                  which is automatically generated by
 *                  `scripts/generate_query_config.pl`.
 */
void list_config(void);

/** List all enabled configuration symbols
 *
 * \note            This function is defined in `programs/test/query_config.c`
 *                  which is automatically generated by
 *                  `scripts/generate_query_config.pl`.
 */
void list_config( void );

#endif /* MBEDTLS_PROGRAMS_TEST_QUERY_CONFIG_H */
