//This sequence is not following the sequence needed for inputs and for outputs, i'm just practiced it and paste here
// So, you can take help only for understanding logic to solve this question, don't follow the whole sequence, actual sequence is some how different



#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main() {
    // Taking input
    int n;
    cout << "Enter the number of buttons (n): ";
    cin >> n;

    string value;
    cout << "Enter the initial state (binary string): ";
    cin >> value;

    vector<char> buttons(value.begin(), value.end()); // Convert string to vector for mutability

    int pressed;
    cout << "Enter the number of pressed buttons: ";
    cin >> pressed;

    vector<int> presSeq(pressed);
    cout << "Enter the pressed sequence (space-separated integers): ";
    for (int i = 0; i < pressed; i++) {
        cin >> presSeq[i];
    }

    cout << "Initial state: " << string(buttons.begin(), buttons.end()) << endl;
    cout << "Number of pressed buttons: " << pressed << endl;

    // Processing the button presses
    for (int i = 0; i < pressed; i++) {
        int ind = presSeq[i] - 1; // Convert to zero-based index

        // Toggle the pressed button
        buttons[ind] = (buttons[ind] == '0') ? '1' : '0';

        // Toggle every presSeq[i]-th button starting from the next one
        for (int j = ind + 1; j < n; j += presSeq[i]) {
            buttons[j] = (buttons[j] == '0') ? '1' : '0';
        }
    }

    cout << "State after pressed buttons: " << string(buttons.begin(), buttons.end()) << endl;

    // Checking for all buttons being the same and counting toggles
    int ind = 0, count = 0;
    while (set<char>(buttons.begin(), buttons.end()).size() != 1 && ind < n) {
        if (buttons[ind] == '1') {
            count++;
            buttons[ind] = '0';
            for (int j = ind + 1; j < n; j += ind + 1) {
                if (j == ind) continue;
                buttons[j] = (buttons[j] == '1') ? '0' : '1';
            }
        }
        ind++;
    }

    cout << "Final state: " << string(buttons.begin(), buttons.end()) << endl;
    cout << "Count of toggles made: " << count << endl;

    return 0;
}
