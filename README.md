<h1 align=center>
  42 Cursus
 </h1>
<h2 align=center>
  philosophers
</h2>
<h2 align=center>

  ![philosophers](https://github.com/beatrizdile/beatrizdile-utils/blob/master/philosophersm.png)
</h2>

The philosophers project is designed to explore parallel computing and synchronization techniques. In this project, it was implemented the dining philosophers problem, a classic synchronization problem in computer science.

## Description

The philosophers project challenges you to simulate the dining philosophers problem using parallel threads. The problem involves a group of philosophers sitting around a dining table, each thinking and eating. However, to eat, a philosopher must use two forks, one on their left and one on their right. The goal is to design a solution that avoids deadlock and ensures that each philosopher gets a chance to eat without causing conflicts.

## Installation

To get started with the Philosophers project, follow these steps:

1. Clone the repository:
```bash
git clone git@github.com:beatrizdile/42sp-philosophers.git
```
2. Change into the project directory:
```bash
cd philo
```
3. Build the project:
```bash
make
```

## Philosophers problem
The dining philosophers problem is a classic example of a concurrent programming and synchronization problem. It explores challenges related to resource sharing, deadlock prevention, and avoiding race conditions. Each philosopher represents a concurrent thread, and the forks represent shared resources.

To run the simulation, execute the compiled philosophers program with the appropriate command-line arguments. Adjust the number of philosophers and timing parameters as needed.
```bash
./philosophers [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [optional: number_of_times_each_philosopher_must_eat]
```
