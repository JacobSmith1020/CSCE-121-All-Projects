#include <iostream>
#include <string>
using namespace std;

int main() {
    float exam1;
    float exam2;
    float examAvg;
    float finalExam;
    float zybooksPar;
    float zybooksCha;
    float zybooksAvg;
    float participationAvg;
    float finalGrade;
    float homeworkInput = 0;
    int i = 1;
    float labworkInput = 0;
    int j = 1;
    string syllabusQuiz;
    float extraCredit;
    float homeworkSum = 0.0;
    float labworkSum = 0.0;
    float homeworkAvg;
    float labworkAvg;
    float homeworkZeroCounter;
    cout << "did you get 100% on the syllabus quiz [y/n]? ";
    cin >> syllabusQuiz;
    if ((syllabusQuiz == "y") || (syllabusQuiz == "Y")) {
        cout << "exam 1 grade [0-100]: ";
        cin >> exam1;
        cout << "exam 2 grade [0-100]: ";
        cin >> exam2;
        cout << "final exam grade [0-100, -1 to skip]: ";
        cin >> finalExam;
        cout << "zybook participation (%): ";
        cin >> zybooksPar;
        cout << "zybook challenge (%): ";
        cin >> zybooksCha;
        cout << "class participation (%): ";
        cin >> participationAvg;
        // Homework input
        while (homeworkInput != -1) {
            cout << "homework " << i << " [0-100, -1 to end]: ";
            cin >> homeworkInput;
            if (homeworkInput == 0) {
                homeworkZeroCounter += 1.0;
            }
            if (homeworkInput == -1) {
                break;
            }
            else {
                homeworkSum += homeworkInput;
                ++ i;
            } 
        }
        // Labwork input
        while (labworkInput != -1) {
            cout << "labwork " << j << " [0-100, -1 to end]: ";
            cin >> labworkInput;
            if (labworkInput == -1) {
                break;
            }
            else {
                labworkSum += labworkInput;
                ++ j;
            }
        }
        cout << "extra credit points [0-1]: ";
        cin >> extraCredit;

        // Exam average calculations
        if (finalExam == -1) {
            examAvg = (.4 * exam1) + (.6 * exam2);
        }
        else {
            if (((exam1 + exam2 + finalExam) / 3.0) > finalExam) {
                examAvg = ((exam1 + exam2 + finalExam) / 3.0);
            }
            else {
                examAvg = finalExam;
            }
        }

        // Zybook calculations
        // Zybook participation
        if ((zybooksPar < 85) && (zybooksPar > 0)) {
            zybooksPar += 15;
        }
        else if (zybooksPar == 0) {
            zybooksPar = 0;
        }
        else {
            zybooksPar = 100;
        }
        // Zybook challenge
        if ((zybooksCha < 85) && (zybooksCha > 0)) {
            zybooksCha += 15;
        }
        else if (zybooksCha == 0) {
            zybooksCha = 0;
        }
        else {
            zybooksCha = 100;
        }
        zybooksAvg = (((4.0 / 7.0) * zybooksPar) + ((3.0 / 7.0) * zybooksCha));

        // Homework calculations
        if (i == 1) {
            homeworkAvg = 0.0;
        }
        else {
            homeworkAvg = homeworkSum / (i - 1);
        }

        // Labwork calculations
        if (j == 1) {
            labworkAvg = 0.0;
        }
        else {
            if (((labworkSum / (j - 1)) < 85) && ((labworkSum / (j - 1)) > 0)) {
                labworkAvg = ((labworkSum / (j - 1)) + 15);
            }
            else if ((labworkSum / (j - 1)) == 0) {
                labworkAvg = 0;
            }
            else {
                labworkAvg = 100;
            }
        }

        // Participation calculations
        if ((participationAvg < 85) && (participationAvg > 0)) {
            participationAvg += 15;
        }
        else if (participationAvg == 0) {
            participationAvg = 0;
        }
        else {
            participationAvg = 100;
        }

        // Final grade calculation
        cout << "exams:               " << examAvg << endl;
        cout << "zybook activities:   " << zybooksAvg << endl;
        cout << "class participation: " << participationAvg << endl;
        cout << "homework:            " << homeworkAvg << endl;
        cout << "labwork:             " << labworkAvg << endl;
        cout << "extra credit:        " << extraCredit << endl;
        finalGrade = (examAvg * .5) + (zybooksAvg * .07) + (participationAvg * .03) + (homeworkAvg * .35) + (labworkAvg * .05) + extraCredit;
        cout << "numeric grade: " << finalGrade << endl;
        // Output letter grades
        if (homeworkZeroCounter > 2) {
            cout << "letter grade: F" << endl;
        }
        else if (examAvg < 60) {
            if (finalGrade >= 60) {
                cout << "letter grade: D" << endl;
            }
            else if (finalGrade < 60) {
                cout << "letter grade: F" << endl;
            }
        }
        else {
            if (finalGrade >= 90) {
                cout << "letter grade: A" << endl;
            }
            else if ((finalGrade >= 80) && (finalGrade < 90)) {
                cout << "letter grade: B" << endl;
            }
            else if ((finalGrade >= 70) && (finalGrade < 80)) {
                cout << "letter grade: C" << endl;
            }
            else if ((finalGrade >= 60) && (finalGrade < 70)) {
                cout << "letter grade: D" << endl;
            }
            else if (finalGrade < 60) {
                cout << "letter grade: F" << endl;
            }
        }
    }
    else {
        cout << "letter grade: F" << endl;
    }

    return 0;
}