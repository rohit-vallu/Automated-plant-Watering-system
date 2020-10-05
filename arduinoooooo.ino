//Libraries
#include <DHT.h>
//DHT
#define DHTPIN 7    // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino


//Variables
int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value

//Soilmoisture
int sensor_pin = A0;
int ACWATERPUMP = 13;

int moisture_value ;



int sensor = 8;
int val;
const int sensorMin = 0;    
const int sensorMax = 1024;  
void setup() {
  Serial.begin(9600);

  pinMode(8,INPUT);
  pinMode(7,INPUT);
  pinMode(A0,INPUT);
    pinMode(13,OUTPUT); //Set pin 13 as OUTPUT pin, to send signal to relay

    dht.begin();

}

void loop() {


////////////////////////////////////////////////////////////////////////////
    //Read data and store it to variables hum and temp
    hum = dht.readHumidity();
    temp= dht.readTemperature();
    //Print temp and humidity values to serial monitor
    //Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" ");
    //Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.print(" ");
    //Serial.println(" Celsius");

  ////////////////////////////////////////////////////////////////////////
  /*Serial.println("rain digi");
  Serial.println(digitalRead(7));
  Serial.println("rain analog");
  Serial.println(analogRead(A0));*/
  ///////////////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////////

    ////////////
//moisture_value= analogRead(sensor_pin);

  // moisture_value = map(moisture_value,550,0,0,100);

   //Serial.print("Mositure : ");

   //Serial.print(moisture_value);

   //Serial.println("%");


 val = digitalRead(8);  //Read data from soil moisture sensor  
 
    Serial.println("soil moisture");

      Serial.println(val);

  if(val == LOW)
  {
    Serial.println("offffffffffffffffffffffffffffffffffffffffffffffffff");
  digitalWrite(13,LOW); //if soil moisture sensor provides LOW value send LOW value to relay
  }
  else
  {
    Serial.println("onnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn");
  digitalWrite(13,HIGH); //if soil moisture sensor provides HIGH value send HIGH value to relay
  }
 
  ///////////
 
 
   

  delay(10000);
}
