const int trigger_pin = 53;
const int echo_pin = 51;
long wave_travel_time;
int distance;

const long baudRate = 9600;
const int BTstate_pin = 31;
const int BTenable_pin = 35;
char c = ' ';
boolean BTconnected = false;


void setup() {

  pinMode(trigger_pin, OUTPUT);
  pinMode(echo_pin, INPUT);

  pinMode(BTstate_pin, INPUT);
  pinMode(BTenable_pin, OUTPUT);

//  digitalWrite(BTenable_pin, HIGH);

  Serial.begin(9600);

//  Serial1.begin(baudRate);


}

void loop() {

  digitalWrite(trigger_pin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin, LOW);

  wave_travel_time = pulseIn(echo_pin, HIGH);

  distance = wave_travel_time * 0.034 / 2;
  

  Serial.println(distance);
}
