
#include <math.h>
int capteurPinTemperature = A5;
const int B = 4275;               // B value of the thermistor
const int R0 = 100000;            // R0 = 100k

int capteurPinSon = A1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
    temperature();
   // son();
    delay(1000);
}


void temperature(){
    int a = analogRead(capteurPinTemperature);
    float R = 1023.0/a-1.0;
    R = R0*R;
    int8_t temperature = 1.0/(log(R/R0)/B+1/298.15)-300.15; // convert to temperature via datasheet
    //Serial.print("temperature=");
    Serial.println(temperature);
}

void son(){
  long sum = 0;
    for(int i=0; i<32; i++)
    {
        sum += analogRead(capteurPinSon);
    }

    sum >>= 5;
    Serial.print("intensite=");
    Serial.println(sum);
}

