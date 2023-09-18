/*
 * Name: Nanabanyin Abbiw
 * Course: CS 250
 * Last Update: 09/17/2023
 * Program: Programming Assignment 1
 *
 * Description:
 * This is a C++ program that calculates an estimated population
 * over a projected number of years using birth and death rates,
 * current population, and years projected.
 *
 */

#include <iostream>
using namespace std;

int GrowthRate(int, int);                           // function for growth rate
int estPopulation(int, int, int);                   // function for estimated population

int main()
{
    int birthRate, deathRate, population, years, finalPopulation, growthRate;                // variables for birth and death rates, population and final population,
                                                                                             // years and growth rate

    cout << "Enter birth rate: ";           // takes input for birth rate
    cin >> birthRate;

    while (birthRate < 0)               // loop continues until positive birth rate is entered
    {
        cout << "Please enter a positive birth rate: ";
        cin >> birthRate;
    }

    cout << "Enter death rate: ";           // takes input for death rate
    cin >> deathRate;

    while (deathRate < 0)               // loop continues until positive death rate is entered
    {
        cout << "Please enter a positive death rate: ";
        cin >> deathRate;
    }

    cout << "Enter current population: ";       // takes input for population
    cin >> population;

    while (population < 2)              // loop continues until population greater than 2 is entered
    {
        cout << "Please enter a population greater than 2: ";
        cin >> population;
    }

    cout << "Enter number of years to project: ";       // takes input for projected years
    cin >> years;


    for (int year = 0; year < years; year++)                        // loop displays calculations for said projected number of years
    {
        finalPopulation = estPopulation(birthRate, deathRate, population);          // calls the estimated population function
        growthRate = GrowthRate(birthRate, deathRate);                      // calls the growth rate function
        cout << "The growth rate " << growthRate << "% for year " << year + 1 << " has an estimated population of " << finalPopulation << endl;     // display message
        population = finalPopulation;
    }

    return 0;
}

int GrowthRate(int birthRate, int deathRate)
{
    return birthRate - deathRate;               // formula for growth rate
}

int estPopulation(int birthRate, int deathRate, int population)
{
    int endPopulation = population + (birthRate * population) / 100 - (deathRate * population) / 100;           // formula for estimated population
    return endPopulation;
}


