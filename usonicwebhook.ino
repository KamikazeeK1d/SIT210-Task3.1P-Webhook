
// trig pin on the sensor is connected to D4 pin on argon
const int trigPin = D4;
// echo pin on the sensor is connected to D5 pin on argon
const int echoPin = D5;

// duration is used for the echo pin
long duration;
// distance uses the duration variable to find the range for the sensor
int distance;
// to allow for the data to go to thingspeak, particle.publish requires a string so that is what string data is for
String data;

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loop() {
    // turns D4 pin off
    digitalWrite(trigPin, LOW);
    // Waits 10 microseconds
    delayMicroseconds(10);
    
    // Turns D4 pin on
    digitalWrite(trigPin, HIGH);
    // Waits 10 microseconds
    delayMicroseconds(10);
    // Turns D4 pin off
    digitalWrite(trigPin, LOW);
    
    // Turns D5 pin on and reads the echo pin, waits for pulse, returns it then turns echo pin to low
    duration = pulseIn(echoPin, HIGH);
    
    // This is to get the distance of what has been detected through duration
    distance = duration*0.034/2;
    
    // Turns distance into a string to be able to publish the data through the webhook
    data = String(distance);
    // Publishes the data through the webhook
    Particle.publish("cm", data, PRIVATE);
    // Waits 30 seconds
    delay(30000);
}