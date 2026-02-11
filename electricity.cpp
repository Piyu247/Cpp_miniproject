#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Appliance {
public:
    string name;
    double power;   // watts
    double hours;   // hours per day

    double dailyEnergy() {
        return (power * hours) / 1000.0; // kWh
    }
};

int main() {
    int n;
    double costPerUnit;
    vector<Appliance> appliances;

    cout << "Enter number of appliances: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Appliance a;

        cout << "\nAppliance " << i + 1 << " name: ";
        cin >> ws;
        getline(cin, a.name);

        cout << "Power (in watts): ";
        cin >> a.power;

        cout << "Usage per day (in hours): ";
        cin >> a.hours;

        appliances.push_back(a);
    }

    cout << "\nEnter electricity cost per unit (per kWh): ";
    cin >> costPerUnit;

    double totalEnergy = 0;

    cout << "\n--- Daily Usage Report ---\n";
    for (int i = 0; i < appliances.size(); i++) {
        double energy = appliances[i].dailyEnergy();
        totalEnergy += energy;
        cout << appliances[i].name << ": " << energy << " kWh\n";
    }

    double totalCost = totalEnergy * costPerUnit;

    cout << "\nTotal Daily Consumption: " << totalEnergy << " kWh";
    cout << "\nEstimated Daily Cost: Rs. " << totalCost;

    return 0;
}