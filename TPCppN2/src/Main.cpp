#include <iostream>
#include "Sensor.h"

using namespace std;

int main() {
  Sensor *sensor1 = new Sensor(19783);
  sensor1->AddEvent(1, 12, 32, 'V');

  sensor1->AddEvent(1, 12, 32, 'J');
  sensor1->AddEvent(1, 12, 33, 'J');

  sensor1->AddEvent(1, 12, 32, 'R');
  sensor1->AddEvent(1, 13, 32, 'R');
  sensor1->AddEvent(1, 14, 32, 'R');

  sensor1->AddEvent(1, 12, 32, 'N');
  sensor1->AddEvent(2, 12, 32, 'N');
  sensor1->AddEvent(3, 12, 32, 'N');
  sensor1->AddEvent(4, 12, 32, 'N');

  cout << "------------By Min-------------\n";
  // Expected : [25, 25, 25 ,25]

  cout << "V " << (int)(sensor1->GetStatsByMin(1,12,32)->v*100) << "%\n";
  cout << "J " << (int)(sensor1->GetStatsByMin(1,12,32)->j*100) << "%\n";
  cout << "R " << (int)(sensor1->GetStatsByMin(1,12,32)->r*100) << "%\n";
  cout << "N " << (int)(sensor1->GetStatsByMin(1,12,32)->n*100) << "%\n";

  cout << "------------By Hour-------------\n";
  // Expected : [20, 40, 20 ,20]

  cout << "V " << (int)(sensor1->GetStatsByHour(1,12)->v*100) << "%\n";
  cout << "J " << (int)(sensor1->GetStatsByHour(1,12)->j*100) << "%\n";
  cout << "R " << (int)(sensor1->GetStatsByHour(1,12)->r*100) << "%\n";
  cout << "N " << (int)(sensor1->GetStatsByHour(1,12)->n*100) << "%\n";

  cout << "------------By Day-------------\n";
  // Expected : [14, 28, 42 ,14]

  cout << "V " << (int)(sensor1->GetStatsByDay(1)->v*100) << "%\n";
  cout << "J " << (int)(sensor1->GetStatsByDay(1)->j*100) << "%\n";
  cout << "R " << (int)(sensor1->GetStatsByDay(1)->r*100) << "%\n";
  cout << "N " << (int)(sensor1->GetStatsByDay(1)->n*100) << "%\n";

  cout << "------------By Sensor-------------\n";
  // Expected : [10, 20, 30 ,40]

  cout << "V " << (int)(sensor1->GetStatsBySensor()->v*100) << "%\n";
  cout << "J " << (int)(sensor1->GetStatsBySensor()->j*100) << "%\n";
  cout << "R " << (int)(sensor1->GetStatsBySensor()->r*100) << "%\n";
  cout << "N " << (int)(sensor1->GetStatsBySensor()->n*100) << "%\n";

  return 0;
}
