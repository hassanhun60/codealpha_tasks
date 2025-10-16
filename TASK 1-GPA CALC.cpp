#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of courses: ";
    cin >> n;

    float grade, credit, totalGradePoints = 0, totalCredits = 0;

    for (int i = 1; i <= n; i++) {
        cout << "\nCourse " << i << " grade: ";
        cin >> grade;
        cout << "Course " << i << " credit hours: ";
        cin >> credit;

        totalGradePoints += grade * credit;
        totalCredits += credit;
    }

    float gpa = totalGradePoints / totalCredits;

    cout << "\nSemester GPA = " << gpa << endl;

    char more;
    cout << "\nDo you have previous CGPA? (y/n): ";
    cin >> more;

    if (more == 'y' || more == 'Y') {
        float prevCgpa, prevCredits;
        cout << "Enter previous CGPA: ";
        cin >> prevCgpa;
        cout << "Enter previous total credit hours: ";
        cin >> prevCredits;

        float cgpa = ((prevCgpa * prevCredits) + totalGradePoints) / (prevCredits + totalCredits);
        cout << "Overall CGPA = " << cgpa << endl;
    } else {
        cout << "Overall CGPA = " << gpa << endl;
    }

    return 0;
}
