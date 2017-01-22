
int IN9 = 6;
int IN10 = 7;
int estado = 'p';
const int trigPin = 4;
const int echoPin = 5;

void setup()
{
  Serial.begin(9600);
  pinMode (IN9, OUTPUT);    // Input4 conectada al pin 4
  pinMode (IN10, OUTPUT);    // Input3 conectada al pin 5
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}
void loop()
{
   if(Serial.available()>0){        // lee el bluetooth y almacena en estado
         estado = Serial.read();
     }
   if (estado=='a'){
      long distancia = distance();
      comprueba(distancia);
      if (estado!='p'){
         digitalWrite (IN9, HIGH);
         digitalWrite (IN10, LOW);
      }
   }
   if (estado=='f'){
      digitalWrite (IN9, LOW);
      digitalWrite (IN10, HIGH);
   }
   if (estado=='p'){
      digitalWrite (IN9, LOW);
      digitalWrite (IN10, LOW);
   }

}

void comprueba(long distancia){
   if (distancia<=6){
      digitalWrite (IN9, LOW);
      digitalWrite (IN10, LOW);
      estado='p';
   }
}

long distance(){

   long duration;
   long distance;

   digitalWrite(trigPin, LOW);
   delayMicroseconds(2);

   digitalWrite(trigPin,HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin,LOW);

   duration = pulseIn(echoPin, HIGH);
   distance = duration*0.034/2;
   //delay(200);
   return distance;
}
