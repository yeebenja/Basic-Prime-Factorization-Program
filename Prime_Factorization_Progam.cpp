// Basic Prime Factorization Program
// By: Benjamin Yee
// Email: yeebenja@umich.edu
// LinkedIn: https://www.linkedin.com/in/bay02

/*
Purpose of this program is to find the
prime factorization of a positive integer.
*/
#include <iostream>
#include <vector>

// This program will return an integer a user inputs
// only if that integer is positive.
size_t check_if_integer_is_positive() {
    // If integer is positive, return it
    // else, ask user again until integer is positive


    // --------------------- I should use an exception here instead. I'll fix this later
    size_t integer;
    while (1) {
        std::cout << "Enter a positive integer: ";
        std::cin >> integer;
        if (integer > 0) {
            return integer;
        }
        else {
            std::cout << "Error, try again" << std::endl;
        }
    }
    // ---------------------
}

// Function for computing prime factorization
std::vector<size_t> prime_factorization(size_t x) {
    // This function will output a vector containing
    // all of the prime numbers whose overall product
    // equals number
    std::vector<size_t> temp_vect;
    // Edge case: x = 1
    if (x == 1) {
        return { 1 };
    }
    else {
        size_t a = 2;
        while (a <= x) {
            if (x % a == 0) {
                temp_vect.push_back(a);
                x = x / a;
                continue;
            }
            else {
                a++;
                continue;
            }
        }
        return temp_vect;
    }
    return { 0 };
};

// Purpose of this function is to make the output more
// readable to the user.
void pretty_print_vector(std::vector <size_t> vect) {
    size_t exponent = 1;
    for (size_t idx = 0; idx < vect.size() - 1; idx++) {
        if (vect[idx] == vect[idx + 1]) {
            exponent++;
            continue;
        }
        else {
            //std::cout << vect[idx] << "^" << exponent << " ";
            if (exponent == 1) {
                std::cout << vect[idx] << " ";
            }
            else {
                std::cout << vect[idx] << "^" << exponent << " ";
            }
            exponent = 1;
            continue;
        }
    }
    // Compare last two elements
    if (vect[vect.size() - 1] == vect[vect.size() - 2]) {
        std::cout << vect[vect.size() - 1] << "^" << exponent;
    }
    else {
        std::cout << vect[vect.size() - 1];
    }
}


int main() {

    size_t number = check_if_integer_is_positive();

    std::vector <size_t> prime_factorization_vector = prime_factorization(number);

    pretty_print_vector(prime_factorization_vector);

    return 0;
}