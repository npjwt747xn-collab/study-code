# Lab 5: Drone Test Bench & Data Diagnostics Toolkit

This lab focuses on **generic programming in C++** using templates, STL containers, iterators, and STL algorithms.

You will practice the following concepts:

- function templates
- multiple template parameters
- non-type template parameters
- template specialization
- STL containers
- iterators
- STL algorithms

Core idea: **write algorithms once and reuse them for many types**.

All the following sections of this lab are based on the following levels of dificulty:

🟢 __Simple__: A simple coding task that usually guides you step by step through the process and focuses on learning the basics. It should not take more than 15min to finish it. 

🟡 __Moderate__: A coding task that usually states a moderate problem to test your understanding and transfer skills from syntax to real-world applications. These tasks can be solved in about 30mins depending on your knowledge.

🔴 __Complex__: Quite a difficult or lengthy coding task that requires you to use the acquired knowledge of the previous tasks in a broader context or project. Such tasks might take up to a few hours to solve them.

---

In this lab, you will build parts of a **drone test bench software**.

Modern drones continuously generate data such as:
- sensor values (temperature, vibration, voltage)
- system states (active / inactive)
- configuration parameters

Your task is to build a **generic data processing toolkit** that can handle different data types efficiently.

## Section I: First Steps with Generic Functions

In this section, you implement **basic reusable tools** used in a drone test environment.
For that, you provide various generic functions to process the corresponding data.

### 🟢 Task 1: Emergency Payload Switch

During testing, payload parameters must sometimes be swapped quickly (e.g. switching between calibration values).

Write a **generic function** that swaps two values.

#### Requirements

- The function must work for at least:
  - `int`
  - `double`
  - `std::string`
- Use references so that the original values are actually changed
- Print the values before and after the swap
- Briefly describe in a code comment why a template is better here than writing three separate functions

---

### 🟢 Task 2: Sensor Frame Printer

A drone continuously receives **sensor frames** (small arrays of values).
Write a **generic function** that prints all elements of such a frame.

#### Requirements

- The function shall take:
  - an array
  - its size (assume always size > 0)
- Output format example:
  - `[12, 15, 18, 21]`
- Test with:
  - integer array
  - double array
  - character array

---

### 🟢 Task 3: Weakest Signal Detector

To detect signal issues, the system must identify the **weakest measurement** in a frame.

Write a **generic function** that returns the smallest value in a frame.

#### Requirements

- Work for:
  - `int`
  - `double`
- Do not use STL algorithms
- assume always size > 0

---

### 🟢 Task 4: Telemetry Tag Composer

Drone data is often labeled with metadata (e.g. sensor name + priority).

Write a **generic function with two type parameters** to print such pairs.

#### Requirements

- Accept two values of different types
- Accept two string parameters as labels
- Output syntax and example:
  - label1: value1 | label2: value2
  - `Channel: motor_temp | Priority: 2`

---

### 🟢 Task 5: Fixed-Size Packet Buffer

In Section I, you implemented a function that prints arrays using a size parameter.

In embedded drone systems, sensor frames often have a fixed size known at compile time.
This means:
- the size is part of the type (e.g. `int[4]`)
- it does not need to be passed as a function argument

In this task, you will **improve your existing functions** to support this concept.

#### Requirements

- Adapt your existing array-based functions so that:
  - the size is NOT passed as a parameter anymore
  - the function automatically determines the size
- Apply this idea to:
  - your print function (from Task 2)
  - your minimum function (from Task 3)

#### Test your solution with:

- an integer array of size 4
- a double array of size 6

#### Questions

Write the answers as comments:

- Why is the size no longer needed as a parameter?
- What advantage does this have compared to the previous version?

#### Important

- Do NOT create a class or container
- Work directly with arrays
- Reuse and adapt your previous functions instead of rewriting everything

---

## 🟡 Section II: Flight Recorder Data Analysis

The drone stores raw measurement data during test flights.

You now process this data using **STL containers and algorithms**.

---

### Task 6: Sort and Inspect Recorded Samples

A flight recorder captured the following data:

`42, 17, 42, 5, 99, 17, 63, 12`

#### Requirements

- Store the data in a `std::vector`
- Print the original data
- Sort the data using a STL algorithm
- Print the sorted data
- Search for value `63`
- Output whether it exists

#### Note

- Add this task to your existing `main()` function 
- Organize your code into logical sections using comments

---

### Task 7: Noise Cleanup Pipeline

Sensor errors sometimes produce invalid values (`-1`).

Recorded data:

`7, -1, 13, -1, 21, 21, 8, -1, 8`

#### Requirements

- Replace all `-1` with `0`
- Count occurrences of value `8`
- Reverse the dataset
- Print results after each step
- Use STL algorithms

#### Note

- Add this task to your existing `main()` function 
- Organize your code into logical sections using comments

---

## 🟡 Section III: Iterator-Based Processing

To understand how STL works internally, you now operate directly on iterators.

---

### Task 8: Manual Iterator Walk

#### Requirements

- Create a `std::vector<int>` with some values of your choice
- Loop over each element of the vector one by one using:
   1. an explicit iterator 
   2. a for-each loop
- Print all elements

#### Questions

Answer as comments:

- What does `*it` do?
- What does `++it` do?

#### Note

- Add this task to your existing `main()` function 
- Organize your code into logical sections using comments

---

## 🔴 Section IV: Drone Black Box Analyzer

In this final task, you will combine the ideas from all previous sections into one larger program.

A drone test bench stores different kinds of recorded black box data:

- numeric sensor values such as temperature, voltage, and vibration
- boolean status streams such as motor active / inactive or GPS lock / no GPS lock
- fixed-size sensor frames captured at specific moments

Your task is to build a **generic black box analyzer** that can process such data in a reusable way.

The goal is not just to write another isolated template function, but to combine:

- generic functions
- fixed-size arrays
- `std::vector`
- iterators
- STL algorithms
- template specialization

---

### Task 9: Build a Generic Black Box Analyzer

Write a program that analyzes several kinds of drone test data.

---

### Part A: Reusable Analysis Functions

Implement generic functions that can analyze a dataset stored in a `std::vector`.

Your analyzer must be able to determine:

- the sum of all values
- the largest value
- the average value
- the number of occurrences of a specific value
- whether a specific value exists in the dataset

#### Requirements

- Use STL algorithms wherever appropriate
- Do not write separate versions for `int` and `double`
- Test your functions with at least:
  - one `std::vector<int>`
  - one `std::vector<double>`

#### Context

The drone test bench should use the same analysis logic for different numeric measurement types.

---

### Part B: Frame Import from Fixed-Size Sensor Data

The drone firmware delivers some measurements as fixed-size sensor frames.

Reuse your work from the previous sections to process such frames.

#### Requirements

- Create at least two fixed-size arrays that represent sensor frames
- Print the frames using your existing generic array logic
- Transfer the frame data into `std::vector`s
- Analyze the resulting vectors with your functions from Part A

#### Context

This simulates how embedded drone firmware hands over fixed-size measurement blocks to a more flexible analysis tool.

---

### Part C: Status Stream Specialization

The drone also records boolean status streams such as:

- motor active / inactive
- obstacle sensor ready / not ready
- GPS lock / no GPS lock

For such data, the generic numeric analysis is not meaningful.

Implement a **template specialization** for one of your generic analysis functions so that boolean status streams are evaluated differently.

#### Required rule

For `bool`, your specialized function shall return:

- `true`, if more than half of the recorded states are `true`
- `false`, otherwise

#### Additional requirement

In your program output, clearly explain what the boolean result means, for example:

- `Motor was active for most of the test run: true`

#### Context

This is the key place where template specialization is necessary:
boolean state data must be interpreted differently from numeric sensor data.

---

### Part D: Black Box Report

Create a final report for all datasets.

Your program must process at least:

- one integer dataset
- one double dataset
- one boolean dataset
- one fixed-size sensor frame that is converted into a vector

For each dataset, print:

- a title
- the raw data
- the processed / analyzed results
- a short interpretation of the result

#### Example ideas for dataset names

- Motor temperature log
- Battery voltage log
- GPS lock state log
- Vibration frame A

---

### Part E: Integration Requirements

Your final solution must clearly reuse ideas from earlier tasks.

#### Requirements

- Reuse or adapt your earlier generic print logic
- Reuse or adapt your fixed-size array logic
- Use `std::vector` for flexible analysis
- Use iterators or STL algorithms explicitly
- Use template specialization for boolean data
- Keep the program modular with multiple functions

---