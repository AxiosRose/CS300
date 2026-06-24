/*
 * Project Two
 * ABCU Advising Assistance Program
 * CS-300
 * Author: Spencer Rosenberry
 *
 * This program loads course data from a CSV file,
 * stores the courses in a map data structure,
 * prints a sorted course list,
 * and displays detailed information for a selected course.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Structure used to store course information
struct Course {
    string courseNumber;
    string courseTitle;
    vector<string> prerequisites;
};

// Convert string to uppercase for case-insensitive searches
string toUpperCase(string text) {
    transform(text.begin(), text.end(), text.begin(), ::toupper);
    return text;
}

// Remove whitespace from beginning and end of string
string trim(const string& text) {
    size_t start = text.find_first_not_of(" \t\r\n");
    size_t end = text.find_last_not_of(" \t\r\n");

    if (start == string::npos) {
        return "";
    }

    return text.substr(start, end - start + 1);
}

// Split a CSV line into individual fields
vector<string> splitLine(const string& line) {
    vector<string> tokens;
    string token;
    stringstream ss(line);

    while (getline(ss, token, ',')) {
        tokens.push_back(trim(token));
    }

    return tokens;
}

// Load course data from file into the map
bool loadCourses(const string& fileName, map<string, Course>& courses) {

    ifstream file(fileName);

    // Verify file opened successfully
    if (!file.is_open()) {
        cout << "Error: Unable to open file." << endl;
        return false;
    }

    courses.clear();

    string line;

    // Read one line at a time
    while (getline(file, line)) {

        if (line.empty()) {
            continue;
        }

        vector<string> tokens = splitLine(line);

        // Course number and title are required
        if (tokens.size() < 2) {
            cout << "Invalid record skipped." << endl;
            continue;
        }

        Course course;

        course.courseNumber = toUpperCase(tokens[0]);
        course.courseTitle = tokens[1];

        // Store prerequisites if they exist
        for (size_t i = 2; i < tokens.size(); i++) {
            course.prerequisites.push_back(toUpperCase(tokens[i]));
        }

        // Insert course into map
        courses[course.courseNumber] = course;
    }

    file.close();

    // Validate prerequisite references
    for (const auto& coursePair : courses) {

        const Course& course = coursePair.second;

        for (const string& prerequisite : course.prerequisites) {

            // Ignore blank prerequisite entries
            if (prerequisite.empty()) {
                continue;
            }

            if (courses.find(prerequisite) == courses.end()) {

                cout << "Warning: Prerequisite "
                    << prerequisite
                    << " referenced by "
                    << course.courseNumber
                    << " does not exist."
                    << endl;
            }
        }
    }

    cout << "Course data loaded successfully." << endl;
    return true;
}

// Print all courses in alphanumeric order
void printCourseList(const map<string, Course>& courses) {

    if (courses.empty()) {
        cout << "Please load the course data first." << endl;
        return;
    }

    cout << endl;
    cout << "Here is a sample schedule:" << endl;

    // Map automatically keeps keys sorted
    for (const auto& coursePair : courses) {

        cout << coursePair.second.courseNumber
            << ", "
            << coursePair.second.courseTitle
            << endl;
    }
}

// Print detailed information for one course
void printCourse(const map<string, Course>& courses) {

    if (courses.empty()) {
        cout << "Please load the course data first." << endl;
        return;
    }

    string courseNumber;

    cout << "What course do you want to know about? ";
    cin >> courseNumber;

    courseNumber = toUpperCase(courseNumber);

    auto courseIterator = courses.find(courseNumber);

    // Verify course exists
    if (courseIterator == courses.end()) {
        cout << "Course not found." << endl;
        return;
    }

    const Course& course = courseIterator->second;

    cout << endl;
    cout << course.courseNumber
        << ", "
        << course.courseTitle
        << endl;

    cout << "Prerequisites: ";

    if (course.prerequisites.empty()) {
        cout << "None" << endl;
        return;
    }

    // Print prerequisite course numbers and titles
    for (size_t i = 0; i < course.prerequisites.size(); i++) {

        string prerequisiteNumber = course.prerequisites[i];

        auto prerequisiteIterator = courses.find(prerequisiteNumber);

        if (prerequisiteIterator != courses.end()) {

            cout << prerequisiteNumber
                << " ("
                << prerequisiteIterator->second.courseTitle
                << ")";
        }
        else {

            cout << prerequisiteNumber;
        }

        if (i < course.prerequisites.size() - 1) {
            cout << ", ";
        }
    }

    cout << endl;
}

// Display menu options
void displayMenu() {

    cout << endl;
    cout << "1. Load Data Structure." << endl;
    cout << "2. Print Course List." << endl;
    cout << "3. Print Course." << endl;
    cout << "9. Exit" << endl;
    cout << "What would you like to do? ";
}

int main() {

    map<string, Course> courses;

    int choice = 0;
    string fileName;

    cout << "Welcome to the course planner." << endl;

    // Continue until user selects Exit
    while (choice != 9) {

        displayMenu();

        // Validate numeric menu input
        if (!(cin >> choice)) {

            cout << "Invalid input." << endl;

            cin.clear();
            cin.ignore(1000, '\n');

            continue;
        }

        switch (choice) {

        case 1:

            cout << "Enter the file name: ";

            cin.ignore();
            getline(cin, fileName);

            loadCourses(fileName, courses);

            break;

        case 2:

            printCourseList(courses);

            break;

        case 3:

            printCourse(courses);

            break;

        case 9:

            cout << "Thank you for using the course planner!" << endl;

            break;

        default:

            cout << choice
                << " is not a valid option."
                << endl;

            break;
        }
    }

    return 0;
}
