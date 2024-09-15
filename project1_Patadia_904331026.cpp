/**
 * Vandan Patadia
 * Auburn Software Engineering Student
 * File-Name: project1_Patadia.cpp
 * 
 * How to run the code: 
 * {IN TERMINAL}
 * a. Type "cd (path to the folder where the source code(.cpp) file is located) NOTE-do not path to the .cpp file but to the folder it is located in.
 * b. Then once in the correct folder, type "cl /EHsc (.cpp file name)" NOTE-THIS WILL COMPILE THE .CPP FILE INTO A .EXE FILE.
 * c. Once the .exe file has been created [NOTE-the .exe file will have the same file-name as the .cpp file.] Type in the name of the file and swith the extension to .exe.
 * d. Now you will be able to enter the inputs. NOTE-please press enter after every input.
 * 
 * {On AU Server}
 * a. Upload file to AU Server
 * b. Then type "g++ (.cpp File_Name) -o (name of executable file [NOTE-you can name it whatever you want])" NOTE-THIS WILL COMPILE THE .CPP FILE INTO A .EXE FILE.
 * c. Then type "./(name of .exe file)" This will run the code.
 * d. Now you will be able to enter the inputs. NOTE-please press enter after every input
 * 
 * Credits:  
 * 1. I used google for syntax and other formatting issues
 * 2. I consulted a fellow classmates for issues realted to the some of the logic
 */  

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//this method is where all the calculations are done
void calculations(double loanAmount, double annualInR, double monthlyPay) {
  //initiate variables
    int month = 0;
    double totalInterest = 0;
    double monthlyInR = annualInR / 12 / 100;

    //printing the the top desgin and title lines
    cout << fixed << setprecision(2);
    cout << string(70, '*') << endl;
    cout << "\tAmortization Table" << endl;
    cout << string(70, '*') << endl;
    cout << left << setw(10) << "Month" 
         << setw(12) << "Balance" 
         << setw(12) << "Payment" 
         << setw(10) << "Rate" 
         << setw(12) << "Interest" 
         << setw(12) << "Principal" << endl;
    cout << setw(10) << 0 
         << "$" << setw(11) << loanAmount 
         << setw(12) << "N/A" 
         << setw(10) << "N/A" 
         << setw(12) << "N/A" 
         << setw(12) << "N/A" << endl;
    
    //the while loop continues until loanamount is 0
    //it prints line by line calculating based on the previous amounts
    while (loanAmount > 0) {
        month++;
        double interestAmount = loanAmount * monthlyInR;
        double principal = monthlyPay - interestAmount;
        
        if (loanAmount < monthlyPay) {
            principal = loanAmount;
            monthlyPay = loanAmount + interestAmount;
        }
        
        //also stores data such as total interest paid, princial, and number of months
        loanAmount -= principal;
        totalInterest += interestAmount;
        
        cout << setw(10) << month 
             << "$" << setw(11) << loanAmount 
             << "$" << setw(11) << monthlyPay 
             << setw(10) << monthlyInR * 100 
             << "$" << setw(11) << interestAmount 
             << "$" << setw(11) << principal << endl;
    }
    
    //printing the bottom lines whcih show the number of months and the total interest paid
    cout << string(70, '*') << endl;
    cout << "\n";
    cout << "It takes " << month << " months to pay off the loan." << endl;
    cout << "Total interest paid is: $" << totalInterest << endl;
}


int main() {
  //initiating variables
    double loanAmount, annualInR, monthlyPay;
    
    //printing the input lines
    cout << "Loan Amount: ";
    cin >> loanAmount;
    while (loanAmount <= 0) {
      //returns error and prints the following and then allows the user to insert a valid input
      //same goes for the other 3 inputs
        cout << "Please enter a Loan Amount that is greater than 0: ";
        cin >> loanAmount;
    }
    
    cout << "Interest Rate (% per year): ";
    cin >> annualInR;
    while (annualInR <= 0) {
        cout << "Please enter an interest rate that is greater than 0: ";
        cin >> annualInR;
    }
    
    cout << "Monthly Payments: ";
    cin >> monthlyPay;
    while (monthlyPay <= 0) {
        cout << "Please enter monthly payment that is greater than 0: ";
        cin >> monthlyPay;
    }
    
    //here is where we call the calculations method which then prints the rest of the table and performs the neccessary calculations
    calculations(loanAmount, annualInR, monthlyPay);
    return 0;
}
