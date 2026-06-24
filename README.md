# CS300
Projects and Assignments I completed from my CS300 class

# CS 300 Portfolio Reflection

## CS 300 Portfolio Artifacts

* **Project One:** Data Structure Analysis (Run-Time and Memory Comparison)
* **Project Two:** ABCU Advising Assistance Program (C++)

### What was the problem you were solving in the projects for this course?

The goal of these projects was to design a program that could efficiently organize, store, and retrieve course information for ABC University. The system needed to load course data from a file, validate the information, display all courses in alphanumeric order, and allow users to search for a specific course along with its prerequisites. The project also required analyzing different data structures to determine which one would provide the best balance of speed, memory usage, and maintainability.

### How did you approach the problem? Consider why data structures are important to understand.

I began by comparing vectors, hash tables, and binary search trees to understand the advantages and disadvantages of each. This analysis helped me understand how different data structures affect searching, inserting, sorting, and memory usage. For my implementation, I used a map, which automatically keeps the course numbers sorted while providing efficient searches. Understanding data structures allowed me to choose an approach that was both simple to implement and effective for the project's requirements.

### How did you overcome any roadblocks you encountered while going through the activities or project?

One of the biggest challenges was correctly reading and validating the course data from the CSV file. I had to ensure that blank records, invalid input, and missing prerequisites were handled without causing the program to fail. I solved these issues by breaking the program into smaller functions, testing each function separately, and adding validation checks and error messages throughout the program. This made debugging much easier and improved the overall reliability of the application.

### How has your work on this project expanded your approach to designing software and developing programs?

This project taught me that good software design begins with selecting the appropriate data structure before writing code. Instead of immediately focusing on implementation, I now spend more time planning how information will be stored, accessed, and maintained. I also learned the value of modular programming by separating the program into functions that each perform a single responsibility, making the overall design easier to understand and expand.

### How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?

Throughout this course, I developed better programming habits by writing descriptive comments, using meaningful variable and function names, and organizing my code into reusable functions. I also added input validation and error handling to make the program more dependable. These practices make the code easier to read, debug, and modify in the future if additional features or different data structures need to be implemented. Overall, this project strengthened my understanding of how thoughtful design and clean code contribute to software that is easier to maintain and adapt over time.
