#include <iostream>
using namespace std;

double GrowthRate(double birthRate, double deathRate);
double EstimatedPopulation(double currentPopulation, double birthRate, double deathRate);

int main()
{
    double startingPopulation, birthRate, deathRate;
    int numYears;

    // Input validation for starting population, birth rate, and death rate
    do
    {
        cout << "Enter starting population (must be >= 2): ";
        cin >> startingPopulation;
    } while (startingPopulation < 2);

    do
    {
        cout << "Enter birth rate (must be >= 0): ";
        cin >> birthRate;
    } while (birthRate < 0);

    do
    {
        cout << "Enter death rate (must be >= 0): ";
        cin >> deathRate;
    } while (deathRate < 0);

    cout << "Enter the number of years to project: ";
    cin >> numYears;

    cout << "Year\tGrowth Rate\tEstimated Population" << endl;

    for (int year = 1; year <= numYears; year++)
    {
        double growthRate = GrowthRate(birthRate, deathRate);
        double estimatedPopulation = EstimatedPopulation(startingPopulation, birthRate, deathRate);

        cout << year << "\t" << growthRate << "%\t\t" << estimatedPopulation << endl;

        startingPopulation = estimatedPopulation; // Update the current population for the next year
    }

    return 0;
}

double GrowthRate(double birthRate, double deathRate)
{
    return birthRate - deathRate;
}

double EstimatedPopulation(double currentPopulation, double birthRate, double deathRate)
{
    double estimatedPopulation = currentPopulation + (birthRate * currentPopulation) / 100 - (deathRate * currentPopulation) / 100;

    if (estimatedPopulation < 2)
    {
        cout << "Population estimate has fallen below 2. Program terminated." << endl;
        exit(1); // Exit the program if estimated population falls below 2
    }

    return estimatedPopulation;
}
