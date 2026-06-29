# System Design LLD

Started my Low-Level Design (LLD) journey today! 🚀

This repository contains my System Design LLD practice, focusing on Object-Oriented Design, SOLID principles, design patterns, UML diagrams, class relationships, and real-world LLD problems. The goal is to build strong fundamentals in creating scalable, maintainable, and production-ready software.

## What is LLD?

LLD means designing the internal structure of a software system before writing the actual code. It focuses on how the system will be built at the class, object, and module level.

**LLD focuses mainly on:**

- **SCALABILITY**
- **MAINTAINABILITY**
- **REUSABILITY**

On the other hand, HLD defines the architecture and infrastructure decisions such as the tech stack, database, servers, and scaling strategy.

## Day 1 Overview

The `day1` folder introduces core OOP concepts as part of the LLD journey.

- `intro.txt` explains the basics of LLD and the difference between LLD and HLD.
- `oops1.cpp` demonstrates OOP pillars with working examples:
  - abstraction: `car` interface and `sportcar` implementation
  - encapsulation: `Bank` class with private account balance storage and public methods for account operations
  - inheritance and polymorphism: `Animal` base class and `Dog` derived class overriding behavior

## Day 2 Overview

The day2 folder introduces UML concepts that are useful in low-level design and object-oriented modeling.

- `uml.txt` covers:
  - structural vs. behavioral diagrams
  - class diagrams and sequence diagrams
  - associations between classes
  - aggregation and composition as special types of relationships
  - the difference between weak and strong "has-a" relationships
- `uml.cpp` demonstrates composition in C++ with a `House` object containing a `Room` object.

## Repository Structure

- **day1/** - Introduction to LLD concepts and OOP fundamentals
  - `intro.txt` - LLD definition and comparison with HLD
  - `oops1.cpp` - C++ examples showing abstraction, encapsulation, inheritance, and polymorphism
- **day2/** - UML basics and class relationship modeling
  - `uml.txt` - Notes on structural and behavioral diagrams, associations, aggregation, composition, and sequence diagrams
  - `uml.cpp` - C++ example showing composition with `House` and `Room`

## Notes

The current `main()` in `day1/oops1.cpp` creates a `Dog` instance and calls its `eat` method. Other examples for `sportcar` and `Bank` usage are included but commented out for easy experimentation.
