#include <stdio.h>


// Function to perform modular exponentiation
// Computes (B^N) % M efficiently
long long modularExponentiation(long long B, long long N, long long M) {
    long long result = 1;  // Initialize result to 1
    B = B % M;  // Reduce base B modulo M to handle large values of B

    // Loop until the exponent N becomes 0
    while (N > 0) {
        // If the current exponent is odd, multiply the base with the result
        if (N % 2 == 1) {
            result = (result * B) % M;
        }

        // Update base to its square modulo M
        B = (B * B) % M;

        // Halve the exponent (equivalent to N = N / 2)
        N = N / 2;
    }

    return result;  
}

int main() {
    long long B, N, M;  // Variables to store base, exponent, and modulus
    int error = 0;  // Flag to track if an error occurs during input validation

    // Input for base B
    printf("Enter the base (B): ");
    if (scanf("%lld", &B) != 1 || B <= 0) {
        printf("Base must be a positive integer.\n");
        error = 1;  // Set error flag
    }

    // Input for exponent N
    printf("Enter the exponent (N): ");
    if (!error && (scanf("%lld", &N) != 1 || N < 0)) {
        printf("Exponent must be a non-negative integer.\n");
        error = 1;  // Set error flag
    }

    // Input for modulus M
    printf("Enter the modulus (M): ");
    if (!error && (scanf("%lld", &M) != 1 || M <= 1)) {
        printf("Modulus must be greater than 1.\n");
        error = 1;  // Set error flag
    }

    // Only proceed with computation if no error occurred
    if (!error) {
        long long result = modularExponentiation(B, N, M);  
        printf("Result: %lld\n", result);  
    }

    return 0;  
}
