#pragma once
#include "types.h"

/**
 * Returns the error message of the last error using the errno variable.
 * @return The error message.
 */
const char *get_errno_error();

/**
 * Prints an error message on stderr.
 * @param context The context of the error.
 * @param message The error message. If NULL, the last error from errno is used.
 * @return Always 1.
 */
int print_error(const char *context, const char *message);

/**
 * Parse a string to a floating point number.
 * @param str The string to parse.
 * @param f The pointer to the floating point number.
 * @return 0 if the string is a number, -1 otherwise (errno is set).
 */
int stof64(const char *str, f64 *f);

/**
 * Parse a string to an unsigned integer in base 10.
 * @param str The string to parse.
 * @param u The pointer to the unsigned integer.
 * @return 0 if the string is a valid number, -1 otherwise (errno is set).
 */
int stou32(const char *str, u32 *u);
