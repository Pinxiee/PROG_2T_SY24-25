#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    string name;
    int age;
    double annual_income;
    int credit_score;
    double loan_amount;
    int loan_term;
    char has_existing_loan;
    char evaluate_again;

    do {
        cout << "Enter your name: ";
        getline(cin, name);

        cout << "Enter your age: ";
        cin >> age;

        cout << "Enter your annual income (in php): ";
        cin >> annual_income;

        cout << "Enter your loan amount (in php): ";
        cin >> loan_amount;

        cout << "Enter loan term (in years): ";
        cin >> loan_term;

        bool is_eligible = true;
        string rejection;

        if (age < 21 || age > 60){
            is_eligible = false;
            rejection += "- Applicant must have age between 21 and 60.\n";
        }

        if ((loan_amount < 50000 && annual_income < 30000) || (loan_amount >= 50000 && loan_amount <= 100000 && annual_income < 50000) || (loan_amount > 100000 && annual_income < 80000)){
            is_eligible = false;
            rejection += "- Applicant does not meet th required income for the loan amount.\n";
        }

        if (credit_score < 700){
            is_eligible = false;
            rejection += "- Applicant must have the credit score of 700 or higher.\n";
        }

        if  (loan_term < 1 || loan_term > 20){
            is_eligible = false;
            rejection += "- Loan term must be between 1 and 20 years.\n";
        }

        if (has_existing_loan == 'Y' || has_existing_loan == 'y'){
            is_eligible = false;
            rejection += "- Applicant must not have existing loan with the bank.\n";
        }

        if (is_eligible){
            double annual_interest = 4.0;
            if (annual_income > 100000){
                annual_interest += 1.0;
            } else if (loan_amount < 50000){
                annual_interest -= 1.0;
            }
            double monthly_interest = annual_interest/12;
            int total_months = loan_term * 12;

            double monthly_amortization = (loan_amount * monthly_interest) / (1 - pow (1 + monthly_interest, -total_months));
            
            cout << fixed << setprecision(2);
            cout << "Loan Application Result for " << name << ":" << endl;
            cout << "Status: Approved\n";
            cout << "Interest Rate: " << annual_interest << "%\n";
            cout << "Loan Term: " << loan_term << " years\n";
            cout << "Monthly Amortization: Php " << monthly_amortization << endl; 
            } else {
                cout << "Loan Application Result for " << name << ":" << endl;
                cout << "Status: Rejected\n";
                cout << "Reason/s: " << endl << rejection;
            }

            cout << "Do you want to evaluate another loan? (Y/N): ";
            cin >> evaluate_again;
            cin.ignore();

    } while (evaluate_again == 'Y' || evaluate_again == 'y');
}
