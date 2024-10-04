#include "Investment.h"

// Constructor
Investment::Investment(double initial, double monthlyDeposit, double annualRate, int years)
    : m_initialInvestment(initial),
      m_monthlyDeposit(monthlyDeposit),
      m_annualInterestRate(annualRate),
      m_numberOfYears(years) {}

// Method to calculate investment growth
void Investment::calculateGrowth() {
    double interestRate = m_annualInterestRate / 100;
    double yearEndBalanceWithout = m_initialInvestment;
    double yearEndBalanceWith = m_initialInvestment;
    double earnedInterestWithout, earnedInterestWith;

    for (int year = 1; year <= m_numberOfYears; ++year) {
        earnedInterestWithout = yearEndBalanceWithout * interestRate;
        yearEndBalanceWithout += earnedInterestWithout;

        // Store results for without deposits
        m_withoutDeposits.push_back(yearEndBalanceWithout);

        // Monthly calculations with additional deposits
        for (int month = 1; month <= 12; ++month) {
            yearEndBalanceWith += m_monthlyDeposit;
            earnedInterestWith = yearEndBalanceWith * (interestRate / 12);
            yearEndBalanceWith += earnedInterestWith;
        }

        // Store results for with deposits
        m_withDeposits.push_back(yearEndBalanceWith);
    }
}

// Method to display results
void Investment::displayResults() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Balance and Interest Without Additional Monthly Deposits\n";
    std::cout << "Year\tYear End Balance\tYear End Earned Interest\n";

    for (int year = 1; year <= m_numberOfYears; ++year) {
        double earnedInterest = m_withoutDeposits[year - 1] - (year == 1 ? m_initialInvestment : m_withoutDeposits[year - 2]);
        std::cout << year << "\t$" << m_withoutDeposits[year - 1] << "\t\t$" << earnedInterest << "\n";
    }

    std::cout << "\nBalance and Interest With Additional Monthly Deposits\n";
    std::cout << "Year\tYear End Balance\tYear End Earned Interest\n";

    for (int year = 1; year <= m_numberOfYears; ++year) {
        double earnedInterest = m_withDeposits[year - 1] - (year == 1 ? m_initialInvestment : m_withDeposits[year - 2]);
        std::cout << year << "\t$" << m_withDeposits[year - 1] << "\t\t$" << earnedInterest << "\n";
    }
}
