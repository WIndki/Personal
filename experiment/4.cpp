#include <iostream>
#include <iomanip>

using namespace std;
float getTotal(float scores[]) {
    float total = 0.0;
    for (int i = 0; i < 5; i++) {
        total += scores[i];
    }
    return total;
}

float getAverage(float scores[]) {
    float total = getTotal(scores);
    float average = total / 5;
    return average;
}

float getMax(float scores[]) {
    float max = scores[0];
    for (int i = 1; i < 5; i++) {
        if (scores[i] > max) {
            max = scores[i];
        }
    }
    return max;
}

float getMin(float scores[]) {
    float min = scores[0];
    for (int i = 1; i < 5; i++) {
        if (scores[i] < min) {
            min = scores[i];
        }
    }
    return min;
}

int main() {
    float scores[5];

    cout << "Enter scores of 5 subject" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "subject" << i + 1 << ": ";
        cin >> scores[i];
    }

    cout << fixed << setprecision(2);
    cout << "Total scores: " << getTotal(scores) << endl;
    cout << "Average scores: " << getAverage(scores) << endl;
    cout << "Highest scores" << getMax(scores) << endl;
    cout << "Lowest scores: " << getMin(scores) << endl;

    return 0;
}
