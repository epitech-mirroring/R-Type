# Benchmark Report: 2D Graphic Libraries in C++

## Overview

This benchmark report compares the performance of three popular **2D Graphic Libraries** in C++: **SFML**, **SDL2**, and **Allegro**. The goal is to assess their suitability for building a 2D game engine and game.

### Libraries Tested

- **SFML (Simple and Fast Multimedia Library):** Known for its simplicity and ease of use.
- **SDL2 (Simple DirectMedia Layer):** Highly portable and widely used in game development.
- **Allegro:** A mature and robust library, with a long history in 2D game development.

### Environment Setup


| **Component**              | **Details**                                       |
|----------------------------|---------------------------------------------------|
| **CPU**                    | 11th Gen Intel(R) Core(TM) i5-11400H @ 2.70GHz    |
| **RAM**                    | 	16 GB DDR4                                       |
| **GPU**                    | NVIDIA GeForce RTX 3060 Laptop GPU                |
| **Operating System**       | 5.15.146.1-microsoft-standard-WSL2, x86_64 GNU/Linux |
| **Compiler**               | g++ 10.3.0                                        |
| **Libraries Versions**     | SFML 2.5.1, SDL2 2.26.5, Allegro 5.2.8            |

### Benchmark Parameters

| **Parameter**               | **Details**                                                                                                                    |
|-----------------------------|--------------------------------------------------------------------------------------------------------------------------------|
| **Resolution**               | 800x600                                                                                                                        |
| **FPS Target**               | 60 FPS                                                                                                                         |
| **Test Scenarios**           | 1. Rendering 1000 sprites<br>2. Scrolling background<br> |
| **Number of Iterations**     | 2                                                                                                                              |

---

## Test Results

### 1. **Test Case 1: Rendering 1000 Sprites**

This test evaluates how each library handles rendering a large number of sprites on the screen.

| **Metric**          | **SFML** | **SDL2** | **Allegro** |
|---------------------|---------|----------|---------|
| CPU Utilization (%) | 5       | 40       | 11      |
| Memory Usage (MB)   | 1.5     | 1        | 1.5     |
| Frame time (avg MS) | 23-25   | 1-2      | 1-2     |


### 2. **Test Case 2: Scrolling Background**

This test measures performance while rendering a smooth scrolling background (parallax or tile-based scrolling).

| **Metric**              | **SFML** | **SDL2** | **Allegro** |
|-------------------------|----------|----------|-------------|
| CPU Utilization (%)     | 22       | 18       | 4           |
| Memory Usage (MB)       | 1.5      | 1.7      | 1.5         |
| Frame time (avg MS)     | 2-5      | 2-3      | 500-7000    |

## Summary of Findings

### Performance Comparison

- **Rendering 1000 Sprites:**
  - SFML shows the lowest CPU utilization and moderate frame time, making it efficient for rendering numerous sprites.
  - SDL2 has higher CPU usage but manages to have excellent frame times, reflecting its choice between performance and resource consumption.
  - Allegro demonstrates excellent frame times and really low CPU usage, but with comparable memory usage to SFML.
- **Scrolling Background:** 
  - SFML and SDL2 have similar frame times and are capable of handling scrolling backgrounds smoothly.
  - Allegro exhibits a significant range in frame time, which can be attributed to its rendering method. While it has the lowest CPU usage, its performance is less consistent.
### Pros and Cons

| **Library**   | **Pros**                                   | **Cons**                                   |
|---------------|--------------------------------------------|--------------------------------------------|
| **SFML**      | Easy to use, good documentation            | Less optimized for low-end hardware        |
| **SDL2**      | Highly portable, strong community support  | API complexity for beginners               |
| **Allegro**   | Mature, great performance in some cases    | Less active development than others        |

---

## Conclusion

**Based on the benchmark results,**

SDL2 is recommended for 2D game engine development. It balances performance and resource usage effectively across both tests that have been done.

Additionally, SDL2’s strong community support and availability of external libraries, such as those for complex particle systems, make it a compelling choice for more advanced features and customizations.

SFML is also a strong contender, particularly for projects requiring ease of use and simpler setup.

However, Allegro, despite its efficient performance in some areas, shows less consistent results in scrolling scenarios and is less actively developed compared to SDL2.

#### In conclusion, **SDL2**'s performance and the ecosystem of external libraries make it the preferred choice for developing a robust 2D game engine with complex features as we need it.

---

## Appendix

### Test Scripts

Include the test scripts and commands used to run the benchmarks.

```bash
# Example command to run a benchmark for SFML
g++ tests/sfml_1000_sprites.cpp -o benchmark_sfml -lsfml-graphics -lsfml-window -lsfml-system
./benchmark_sfml

# Example command to run a benchmark for SDL2
g++ tests/sdl_1000_sprites.cpp -o sdl_benchmark -lSDL2 -lSDL2_image
./sdl_benchmark

# Example command to run a benchmark for Allegro
g++ tests/allegro_1000_sprites.cpp -o allegro_benchmark `pkg-config --libs allegro-5 allegro_image-5`
./allegro_benchmark
