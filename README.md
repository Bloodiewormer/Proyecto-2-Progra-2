# Proyecto-2-Progra-2

## Overview

**Proyecto-2-Progra-2** is a simulation project written in C++ that models an ecosystem containing various types of creatures (Herbivores, Carnivores, Omnivores) and resources (such as Grass). The simulation allows users to observe interactions such as movement, feeding, reproduction, and death among entities in a grid-based environment.

## Features

- **Creature Types**:  
  - **Herbivores**: Feed on resources (like Grass), use evasive movements, and reproduce via mating.
  - **Carnivores**: Hunt other creatures, use random/targeted movements, and reproduce via mating.
  - **Omnivores**: Can switch feeding strategies between herbivore and carnivore, use random movement, and reproduce via mating.

- **Ecosystem Simulation**:
  - Run the simulation for a customizable number of ticks (turns).
  - Visualize all current creatures, their positions, energy, age, and feeding strategy.
  - Save and load simulation states.
  - Log the deaths of creatures for review.

- **User Interaction**:
  - Menu-based control for running the simulation, saving/loading, and visualizing the ecosystem.
  - Option to set a random seed for reproducibility.

## Getting Started

### Prerequisites

- A C++ compiler supporting C++11 or later.
- Windows OS (uses `<Windows.h>`).
- Basic console (terminal) for input/output interaction.

### How to Run

1. **Clone the repository**:
   ```bash
   git clone https://github.com/Bloodiewormer/Proyecto-2-Progra-2.git
   cd Proyecto-2-Progra-2
   ```

2. **Compile the project**:
   Compile all `.cpp` files in the main directory. Example using g++:
   ```bash
   g++ -o ecosystem Proyecto-2-Progra-2/*.cpp
   ```

3. **Run the simulation**:
   ```bash
   ./ecosystem
   ```
   Follow the on-screen menu for simulation controls.

## Project Structure

- `Controller.cpp/h`: Handles simulation flow, main menu, and user interactions.
- `Ecosystem.cpp/h`: Manages the ecosystem state, entities, and simulation progression.
- `Creature.cpp/h`: Base class for all living entities.
- `Herbivore.cpp/h`, `Carnivore.cpp/h`, `Omnivore.cpp/h`: Specialized creature behaviors.
- `HerbivoreFeeding.cpp/h`, `CarnivoreFeeding.cpp/h`: Feeding strategy implementations.
- `Utils.cpp/h`: Utility functions (screen clearing, input handling, random number generation, etc.).
- `Files.cpp/h`: Handles saving/loading and logging.

## How It Works

- On starting, you may load a previous simulation or start fresh (with a new/random seed).
- Initial entities (herbivores, carnivores, omnivores, grass) are created and placed on the grid.
- Each simulation tick lets creatures move, feed, reproduce, and potentially die (energy management).
- You can visualize creature stats or save/load the simulation at any time.
- Dead creatures are logged for review.

## Example Menu Actions

- Run simulation for X ticks
- Visualize current creatures
- Save simulation state
- Read log of dead creatures

## Contributing

Contributions, bug reports, and feature requests are welcome! Please fork the repository and submit a pull request.

## License

This project is for educational purposes. Please check with the repository owner about licensing for external use.

## Author

BloodieWormer
Marysol

Bloodiewormer
