# Lab 5: Generic Programming in C++

This lab focuses on **generic programming in C++** using templates, STL containers, iterators, and STL algorithms.

You will practice the following concepts:

- function templates
- multiple template parameters
- non-type template parameters
- template specialization
- STL containers
- iterators
- STL algorithms

Generische Programmierung means writing code once and using it for many data types. In C++, this is mainly achieved through **templates**. The STL extends this idea with reusable containers, iterators, and algorithms.

All the following sections of this lab are based on the following levels of dificulty:

🟢 __Simple__: A simple coding task that usually guides you step by step through the process and focuses on learning the basics. It should not take more than 15min to finish it. 

🟡 __Moderate__: A coding task that usually states a moderate problem to test your understanding and transfer skills from syntax to real-world applications. These tasks can be solved in about 30mins depending on your knowledge.

🔴 __Complex__: Quite a difficult or lengthy coding task that requires you to use the acquired knowledge of the previous tasks in a broader context or project. Such tasks might take up to a few hours to solve them.

---

## 🟢 Section I: First Steps with Generic Functions

The goal of this section is to build intuition for **type-independent functions**.

### Task 1: Emergency Payload Switch

A drone test bench can load payload values of different types during simulation.

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

### Task 2: Sensor Frame Printer

Write a **generic function** that prints all elements of an array.

#### Requirements

- The function shall take:
  - an array
  - its size
- Output format example:
  - `[12, 15, 18, 21]`
- Test with:
  - integer array
  - double array
  - character array

---

### Task 3: Weakest Signal Detector

Write a **generic function** that returns the smallest element in an array.

#### Requirements

- Work for:
  - `int`
  - `double`
- Do not use STL algorithms
- Use a loop

---

### Task 4: Telemetry Tag Composer

Write a **generic function with two type parameters** that outputs two values.

#### Requirements

- Accept two values of different types
- Output example:
  - `Channel: motor_temp | Priority: 2`

---

## 🟢 Section II: Generic Buffers and Fixed Dimensions

### Task 5: Fixed-Size Packet Buffer

Implement a **generic fixed-size buffer**.

#### Requirements

- Use a type parameter and a compile-time size parameter
- Support:
  - write by index
  - read by index
  - print all elements
- Test with:
  - integers
  - doubles

---

## 🟡 Section III: Technical STL Scenario – Flight Recorder Analysis

### Task 6: Sort and Inspect Recorded Samples

Use values:
`42, 17, 42, 5, 99, 17, 63, 12`

#### Requirements

- Store in `std::vector`
- Sort using STL
- Print sorted vector
- Search for value `63`
- Print result

---

### Task 7: Noise Cleanup Pipeline

Use values:
`7, -1, 13, -1, 21, 21, 8, -1, 8`

#### Requirements

- Replace `-1` with `0`
- Count occurrences of `8`
- Reverse vector
- Print after each step

---

## 🟡 Section IV: Iterator Thinking

### Task 8: Manual Iterator Walk

#### Requirements

- Use explicit iterator
- No range-based loop
- Output all elements
- Explain `*it` and `++it`

---

## 🔴 Section V: Generic Mission Analyzer

### Task 9: Build a Generic Analysis Toolkit

#### Part A

Implement functions for:

- sum
- max
- average

Use STL where appropriate.

---

#### Part B

Specialize behavior for `bool`.

Rule:

Return `true` if more than half values are `true`.

---

#### Part C

Test with:

- int
- double
- bool

Print results clearly.

---

## Reflection Questions

1. Why are templates useful?
2. Why do STL algorithms not depend on container type?
3. Why do some algorithms not work with all containers?
4. When is specialization useful?
5. What disadvantages did you notice?

---

## Learning Outcomes

- Use templates
- Work with STL
- Understand iterators
- Apply algorithms
- Use specialization
