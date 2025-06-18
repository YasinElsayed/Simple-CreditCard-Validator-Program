#include <iostream> // Includes the standard input/output stream library for console operations

int GETDIGIT(const int number); // Function prototype for GETDIGIT, which processes doubled digits
int SUMODD(const std::string cardNumber); // Function prototype for SUMODD, sums odd-positioned digits
int SUMEVEN(const std::string cardNumber); // Function prototype for SUMEVEN, sums even-positioned digits

int main() { // Program entry point
    std::string cardNumber; // Variable to store the user's card number input

    do { // Start of a loop that continues until the user enters 'x'
        std::cout << "Give me Your card Number to check or 'x' to exit: "; // Prompt the user for input
        std::cin >> cardNumber; // Read the user's input into cardNumber

        if (cardNumber == "x") // If the user entered 'x', exit the loop
            break; // Exit the loop immediately

        int result = SUMODD(cardNumber) + SUMEVEN(cardNumber); // Calculate the Luhn sum by adding odd and even position sums

        if(result % 10 == 0) { // If the result is divisible by 10, the card is valid
            std::cout << "Your card is good :)" << std::endl; // Inform the user the card is valid
        } else { // Otherwise, the card is invalid
            std::cout << "Your card is broken :(" << std::endl; // Inform the user the card is invalid
        }
    } while (true); // Repeat the loop until 'break' is called

    std::cout << "Thank you for using the card checker!" << std::endl; // Print a goodbye message after exiting the loop
}

int GETDIGIT(const int number){ // Function to sum the digits of a number (for Luhn algorithm)
    return (number < 10) ? number : (number / 10) + (number % 10); // If number < 10, return it; else, return sum of its digits
}

int SUMODD(const std::string cardNumber){ // Function to sum digits in odd positions (from the right)
    int sum = 0; // Initialize sum to zero
    for(int i = cardNumber.size() - 1; i >= 0; i -= 2) // Loop from the last digit to the start, skipping every other digit
        sum += (cardNumber[i] - '0'); // Convert character to integer and add to sum
    return sum; // Return the total sum
}

int SUMEVEN(const std::string cardNumber){ // Function to sum processed digits in even positions (from the right)
    int sum = 0; // Initialize sum to zero
    for(int i = cardNumber.size() - 2; i >= 0; i -= 2) // Loop from the second-to-last digit to the start, skipping every other digit
        sum += GETDIGIT((cardNumber[i] - '0') * 2); // Double the digit, process with GETDIGIT, and add to sum
    return sum; // Return the total
}