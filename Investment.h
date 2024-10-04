#ifndef AIRGEAD_BANKING_INVESTMENT_H_
#define AIRGEAD_BANKING_INVESTMENT_H_

#include <vector>
#include <iostream>
#include <iomanip>

class Investment {
public:
    Investment(double initial, double monthlyDeposit, double annualRate, int years);

    // Method to calculate investment growth
    void calculateGrowth();

    // Method to display results
    void displayResults() const;

private:
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterestRate;
    int m_numberOfYears;
    std::vector<double> m_withoutDeposits;
    std::vector<double> m_withDeposits;
};

#endif // AIRGEAD_BANKING_INVESTMENT_H_
