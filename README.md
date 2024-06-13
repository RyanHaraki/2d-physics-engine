# 2D Physics Engine

I wanted to simulate galaxy collisions, didn't really like any physics engines, so I'm making my own now. This is a simple 2d physics engine that uses the Verlet method to calculate position. The goal is that I'll eventually be able to simulate a galaxy collision with it.

#### Dependencies:

- Install [SFML](https://www.sfml-dev.org/)

#### To compile and run:

Run this to compile (assuming you've SFML on Mac with Homebrew, or just configure a makefile)

```
g++ -std=c++14 main.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include -o prog -L/opt/homebrew/Cellar/sfml/2.6.1/lib/ -lsfml-graphics -lsfml-window -lsfml-system
```

Run with ```./prog```

### Verlet method

The [Verlet method](https://en.wikipedia.org/wiki/Verlet_integration#:~:text=Verlet%20integration%20\(French%20pronunciation%3A%20%5B,dynamics%20simulations%20and%20computer%20graphics.) is a method used to integrate Newton's equations of motion where the velocity is deduced from the last step. My inspiration for using this method and the description below comes from [this video](https://www.youtube.com/watch?v=lS_qeBy3aQI) and I do not take credit for it.

$$x_{n+1} = 2x_{n} - x_{n-1} + a_n \Delta t^2$$

Where $x_n$ is the position at step $n$ and $a_n$ is the acceleration at step $n$.

This is similar to Euler's method ($x_{n+1} = x_n + v_n \Delta t$), except that, as stated above, the velocity is deduced from the last step.
