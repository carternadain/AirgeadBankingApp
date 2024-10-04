#include <iostream>
#include "Investment.h"

int main() {
    double initialInvestment, monthlyDeposit, annualInterestRate;
    int numberOfYears;

    // Get user input
    std::cout << "Welcome to the Airgead Banking Investment App!\n";
    std::cout << "Initial Investment Amount: ";
    std::cin >> initialInvestment;

    std::cout << "Monthly Deposit: ";
    std::cin >> monthlyDeposit;

    std::cout << "Annual Interest (%): ";
    std::cin >> annualInterestRate;

    std::cout << "Number of Years: ";
    std::cin >> numberOfYears;

    // Create an Investment object
    Investment investment(initialInvestment, monthlyDeposit, annualInterestRate, numberOfYears);

    // Calculate growth
    investment.calculateGrowth();

    // Display results
    investment.displayResults();

    // End program
    std::cout << "Press any key to continue...\n";
    std::cin.ignore();
    std::cin.get(); // Wait for user input to exit

    return 0;
}
