#include <iostream>

using namespace std;

int main()
{
    int testScore1 = 75;
    int testScore2 = 95;
    int testScore3 = 85;
    int testScore4 = 65;

    double weightTestScore1 = 0.20;
    double weightTestScore2 = 0.35;
    double weightTestScore3 = 0.15;
    double weightTestScore4 = 0.30;

    double totalAverage = ((testScore1 * weightTestScore1) + (testScore2 * weightTestScore2)+ (testScore3 * weightTestScore3)+ (testScore4 * weightTestScore4)) /4;

    cout << "Total weighted average of four test scores are " << totalAverage << endl;

    return 0;
}