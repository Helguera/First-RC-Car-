
int IN3 = 5;
int IN4 = 4;
int estado = 'p';

void setup()
{
  pinMode (IN4, OUTPUT);    // Input4 conectada al pin 4
  pinMode (IN3, OUTPUT);    // Input3 conectada al pin 5
  Serial.begin(9600);

}
void loop()
{
   if(Serial.available()>0){        // lee el bluetooth y almacena en estado
         estado = Serial.read();
     }
   if (estado=='a'){
      digitalWrite (IN4, HIGH);
      digitalWrite (IN3, LOW);
   }
   if (estado=='f'){
      digitalWrite (IN4, LOW);
      digitalWrite (IN3, HIGH);
   }if (estado=='p'){
      digitalWrite (IN4, LOW);
      digitalWrite (IN3, LOW);
   }

}
