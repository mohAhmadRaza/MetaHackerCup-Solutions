#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void mainFunction() {
    // Input and output file paths
    string input_file = "C:/Users/LENOVO/Documents/MyReactJourney/DSA/Meta Hacker Cup Question/CheeseBurgers-II/Inputs.txt";
    string output_file = "C:/Users/LENOVO/Documents/MyReactJourney/DSA/Meta Hacker Cup Question/CheeseBurgers-II/Outputs.txt";

    // File streams
    ifstream infile(input_file);  // Input file stream to read
    ofstream outfile(output_file); // Output file stream to write

    // Checking if the input file is open
    if (!infile.is_open()) {
        cerr << "Unable to open the input file" << endl;
        return;
    }

    // Variable to store the number of test cases
    int T;
    infile >> T;  // Reading number of test cases

    vector<string> results;  // To store results

    // Process each test case
    for (int i = 1; i <= T; i++) {
        int A, B, C;
        infile >> A >> B >> C;  // Reading the three inputs

        if (C < A && C < B) {
            results.push_back("Case #" + to_string(i) + ": 0");
        } else if (C > A && C > B) {
            int S = C / A, D = (C % A) / B;
            int buns1 = (S + D) * 2;
            int petties1 = S + (D * 2);

            D = C / B;
            S = (C % B) / A;
            int buns2 = (S + D) * 2;
            int petties2 = S + (D * 2);

            if (petties1 > petties2) {
                results.push_back("Case #" + to_string(i) + ": " + to_string(petties1));
            } else {
                if (buns2 > petties2) {
                    results.push_back("Case #" + to_string(i) + ": " + to_string(petties2));
                } else {
                    results.push_back("Case #" + to_string(i) + ": " + to_string(petties2 - 1));
                }
            }
        } else if (C < A && C == B) {
            results.push_back("Case #" + to_string(i) + ": 1");
        } else if (C < B && C == A) {
            results.push_back("Case #" + to_string(i) + ": 1");
        }
    }

    // Writing the results to the output file
    if (outfile.is_open()) {
        for (const auto &result : results) {
            outfile << result << endl;
        }
    } else {
        cerr << "Unable to open the output file" << endl;
    }

    // Close the file streams
    infile.close();
    outfile.close();
}

int main() {
    mainFunction();  // Call the function
    return 0;
}
