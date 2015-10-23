struct Event {
  int minute;
  int state;
}

class Sensor {
  public :

  private :
    Event index = new Event[7][24][];
    int id;
    int uptime;
}
