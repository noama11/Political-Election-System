# Political-Election-System

## Overview

This project, developed in **C++** within a **Linux environment**, implements a political election system designed to demonstrate my skills in object-oriented programming, algorithm optimization, and system design. Using the **Observer Pattern**, the system simulates elections with dynamic interactions between parties and politicians, offering a scalable solution that efficiently handles real-time updates and election mechanics.

## Key Technical Highlights

- **Advanced C++ Proficiency**: This project showcases my ability to write efficient, optimized code with strong attention to memory management and data structures.
- **Observer Design Pattern**: I used the **Observer Pattern** to decouple components and ensure real-time updates, a key element in scalable, maintainable software systems.
- **Election Algorithms**: The system efficiently calculates party strength and handles leadership elections, demonstrating strong algorithmic thinking and problem-solving abilities.
- **Scalability**: The architecture allows dynamic addition/removal of politicians and parties, highlighting my focus on building flexible, scalable systems.

## Program Description

The system manages two political blocs: **Republicans** and **Democrats**. Politicians are categorized into two types:

- **Leader-type**: Can become party chairmen in the primaries.
- **Social-type**: Their strength is doubled during elections.

### How It Works:

- **Primaries**: In each party, the strongest leader-type politician is selected as chairman. If there are multiple candidates with the same strength, the most senior politician is chosen.

- **Elections**: The strength of each party is calculated based on the sum of their politicians' strength, with social-type politicians doubling their strength. The party with the highest total strength wins, and its chairman becomes the Prime Minister.

- **Observer Pattern**: Used to notify party members of leadership changes after primaries, ensuring real-time communication within each party.

- **Dynamic Politician Behavior**: Politicians can move between parties based on their compatibility with the party’s political bloc (Republican or Democrat).
  Minister.

### Code Structure:

- **include/**: Contains all class definitions.
  - `Party.h`, `Politician.h`, `Republican_Party.h`, `Democratic_Party.h`
- **src/**: Contains all class implementations.
  - `Party.cpp`, `Politician.cpp`, `Republican_Party.cpp`, `Democratic_Party.cpp`
- **Makefile**: Used for building the project.

### Setup and Run:

1. **Clone the repo**:

   ```bash
   git clone https://github.com/your-repo-url/political-election-system.git
   ```

2. **Build the project**:

   ```bash
   make
   ```

3. **Run the program**:
   ```bash
   ./electionSystem
   ```

## Summary

This project demonstrates my skills in **C++**, with a focus on object-oriented programming, memory management, and using design patterns like the Observer Pattern. It’s designed to handle dynamic, real-time updates efficiently and simulate a full election system.
