/**
 * \file mbedtls/config_psa.h
 * \brief PSA crypto configuration options (set of defines)
 *
 *  This set of compile-time options takes settings defined in
 *  include/mbedtls/mbedtls_config.h and include/psa/crypto_config.h and uses
 *  those definitions to define symbols used in the library code.
 *
 *  Users and integrators should not edit this file, please edit
 *  include/mbedtls/mbedtls_config.h for MBEDTLS_XXX settings or
 *  include/psa/crypto_config.h for PSA_WANT_XXX settings.
 */
/*
 *  Copyright The Mbed TLS Contributors
 *  SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later
 */

#ifndef MBEDTLS_CONFIG_PSA_H
#define MBEDTLS_CONFIG_PSA_H

#include "psa/crypto_legacy.h"

#include "psa/crypto_adjust_config_synonyms.h"

#include "mbedtls/config_adjust_psa_superset_legacy.h"



/****************************************************************/
/* De facto synonyms */
/****************************************************************/

#if defined(PSA_WANT_ALG_ECDSA_ANY) && !defined(PSA_WANT_ALG_ECDSA)
#define PSA_WANT_ALG_ECDSA PSA_WANT_ALG_ECDSA_ANY
#elif !defined(PSA_WANT_ALG_ECDSA_ANY) && defined(PSA_WANT_ALG_ECDSA)
#define PSA_WANT_ALG_ECDSA_ANY PSA_WANT_ALG_ECDSA
#endif

#if defined(PSA_WANT_ALG_RSA_PKCS1V15_SIGN_RAW) && !defined(PSA_WANT_ALG_RSA_PKCS1V15_SIGN)
#define PSA_WANT_ALG_RSA_PKCS1V15_SIGN PSA_WANT_ALG_RSA_PKCS1V15_SIGN_RAW
#elif !defined(PSA_WANT_ALG_RSA_PKCS1V15_SIGN_RAW) && defined(PSA_WANT_ALG_RSA_PKCS1V15_SIGN)
#define PSA_WANT_ALG_RSA_PKCS1V15_SIGN_RAW PSA_WANT_ALG_RSA_PKCS1V15_SIGN
#endif

#if defined(PSA_WANT_ALG_RSA_PSS_ANY_SALT) && !defined(PSA_WANT_ALG_RSA_PSS)
#define PSA_WANT_ALG_RSA_PSS PSA_WANT_ALG_RSA_PSS_ANY_SALT
#elif !defined(PSA_WANT_ALG_RSA_PSS_ANY_SALT) && defined(PSA_WANT_ALG_RSA_PSS)
#define PSA_WANT_ALG_RSA_PSS_ANY_SALT PSA_WANT_ALG_RSA_PSS
#endif



/****************************************************************/
/* Require built-in implementations based on PSA requirements */
/****************************************************************/

#if defined(MBEDTLS_PSA_CRYPTO_CONFIG)

/* Require built-in implementations based on PSA requirements */

/* We need this to have a complete list of requirements
 * before we deduce what built-ins are required. */
#include "psa/crypto_adjust_config_key_pair_types.h"

#include "mbedtls/config_adjust_legacy_from_psa.h"



/****************************************************************/
/* Infer PSA requirements from Mbed TLS capabilities */
/****************************************************************/

#else /* MBEDTLS_PSA_CRYPTO_CONFIG */

/* Infer PSA requirements from Mbed TLS capabilities */

#include "mbedtls/config_adjust_psa_from_legacy.h"

/* Hopefully the file above will have enabled keypair symbols in a consistent
 * way, but including this here fixes them if that wasn't the case. */
#include "psa/crypto_adjust_config_key_pair_types.h"

#endif /* MBEDTLS_PSA_CRYPTO_CONFIG */

#if defined(PSA_WANT_ALG_JPAKE)
#define PSA_WANT_ALG_SOME_PAKE 1
#endif

#include "psa/crypto_adjust_auto_enabled.h"

#endif /* MBEDTLS_CONFIG_PSA_H */
