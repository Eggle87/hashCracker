#ifndef CRYPTOGRAPHY_H
#define CRYPTOGRAPHY_H

#include <openssl/evp.h>

/**
 * @brief Compute SHA-256 digest of a message
 * @param message Pointer to the message to hash
 * @param message_len Length of the message in bytes
 * @param digest Pointer to store the computed digest (allocated by function)
 * @param digest_len Pointer to store the length of the digest
 */
void digest_message(const unsigned char *message, size_t message_len, unsigned char **digest, unsigned int *digest_len);

/**
 * @brief Handle OpenSSL errors
 */
void handleErrors();

#endif // CRYPTOGRAPHY_H
