const int trigPin = D4;
const int echoPin = D5;

long duration;
int distance;
String data;

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loop() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(10);
    
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    duration = pulseIn(echoPin, HIGH);
    
    distance = duration*0.034/2;
    
    data = String(distance);
    Particle.publish("cm", data, PRIVATE);
    delay(30000);
}