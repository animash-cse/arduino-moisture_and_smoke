 char inchar; //Will hold the incoming character from the Serial Port.
 int led = 8;          
 int motor =9;
 int motor1=10;
  
int triggerPin=7;
int echoPin =6;
long duration,level;

//const int analogInPin = A0;
//int sensorValue = 0; 
//int sensorPin = A1;    // select the input pin for the potentiometer
//int sensorValue1 = 0;  // variable to store the value coming from the sensor

void setup()
{
  // prepare the digital output pins
 
 pinMode(led, OUTPUT);
 pinMode(motor, OUTPUT);
  pinMode(motor1, OUTPUT);
 digitalWrite(led, LOW);
 digitalWrite(motor, LOW);
  digitalWrite(motor1, LOW);

  pinMode(echoPin,INPUT); 
  pinMode(triggerPin,OUTPUT);
   
  Serial.begin(9600);
  //Serial.print("pin state low\n");
  delay(3000); // give time for GSM module to register on network.

  Serial.println("AT+CMGF=1"); // set SMS mode to text
  delay(200);
  Serial.println("AT+CNMI=2,2,0,0,0"); 
  // blurt out contents of new SMS upon receipt to the GSM shield's serial out
  // set module to send SMS data to serial out upon receipt
  delay(200);
}
void loop()
{
 
     
  long x =getSonar4pin();
  
   moisture();
   smoke();
   
}

void moisture ()
{ 
         int sensorValue1 = analogRead(A1);
         // print out the value you read:
         Serial.print("moisture Value:");
         Serial.println(sensorValue1);
         delay(1000);
         
   /*  if (sensorValue1<250)
         
         {
           digitalWrite(motor1, HIGH);
             delay(1000);
          Serial.println("AT+CMGS=\"+8801765570226\"");//Change the receiver phone number
          // Serial.println("ATD=\"+8801799402497\"");
          delay(500);
          Serial.println("water the plant, .....  ");    //the message you want to send
          delay(500);
          Serial.write(26);
          delay(500);
         
         } */
    if (sensorValue1>600)
          {
          digitalWrite(motor1, LOW);
          delay(1000);
          Serial.println("AT+CMGS=\"+8801763235521\"");//Change the receiver phone number
          // Serial.println("ATD=\"+8801763235521\"");
          delay(500);
          Serial.println("highly moisture: water full");    //the message you want to send
          delay(500);
          Serial.write(26);
          delay(500);
          }

  
}
  
  void smoke() 
  {
   int sensorValue = analogRead(A0);
   //sensorValue = analogRead(analogInPin);
   Serial.print("smoke Value:");
   Serial.println(sensorValue);
   Serial.print("\n");
   delay(1000);
   if(sensorValue>400 && sensorValue<600)
   {
          
          digitalWrite(led, HIGH);
          delay(1000);
          Serial.println("AT+CMGF=1");
          delay(500);
          Serial.println("AT+CMGS=\"+8801763235521\"");//Change the receiver phone number
           //Serial.println("ATD=\"+8801763235521\"");
          delay(500);
          Serial.println("Fire breakout at location: Longitude: 89.501254 and lattitude: 22.898328. water source: 50m north and 100m west");
            //the message you want to send
          delay(500);
          Serial.write(26);
          delay(10000);   
          Serial.println("AT+CMGF=1");
          delay(500);
          Serial.println("AT+CMGS=\"+8801763235521\"");//Change the receiver phone number
           //Serial.println("ATD=\"+8801763235521\"");
          delay(500);
          Serial.println("Hello sir, fire breakout in your home,I have already informed fire brigade");   //the message you want to send
          delay(500);
          Serial.write(26);
          delay(10000);
          Serial.println("ATD+8801763235521;");
          delay(10000);
          //tmrpcm.play("music.wav");
         delay(44000);
         Serial.println("ATD+8801763235521;;");
          delay(10000);
          // tmrpcm.play("music.wav");  
          delay(1000);
         
        }
        
        if(sensorValue>700)
        {
          digitalWrite(led, HIGH);
          delay(1000);
          Serial.println("AT+CMGF=1");
          delay(500);
          Serial.println("AT+CMGS=\"+8801763235521\"");//Change the receiver phone number
           //Serial.println("ATD=\"+8801799402497\"");
          delay(500);
          Serial.println("gas leakage in your home");
            //the message you want to send
          delay(500);
          Serial.write(26);
          
        }
        
        
        
  }
  
  
int getSonar4pin()
{
    digitalWrite(triggerPin,LOW);
    delayMicroseconds(2);

    digitalWrite(triggerPin,HIGH);
    delayMicroseconds(2);

    digitalWrite(triggerPin,LOW);
    duration=pulseIn(echoPin,HIGH);
    level=duration/58.2;
   //Serial.print("sonar value");
    Serial.print("sonar value:");
    Serial.println(level);
    delay(1000);

  if(level<5)
   {
          digitalWrite(motor, LOW);   
          Serial.println("AT+CMGS=\"+8801763235521\"");//Change the receiver phone number
          // Serial.println("ATD=\"+8801763235521\"");
          delay(500);
          Serial.println("Tank is full, should to OFF the motor and i already OFF the motor");    //the message you want to send
          delay(500);
          Serial.write(26);
          delay(500);
   }
   
  if(level>18)
   {
          digitalWrite(motor, HIGH);
          Serial.println("AT+CMGS=\"+8801763235521\"");//Change the receiver phone number
         //  Serial.println("ATD=\"+8801763235521\"");
          delay(500);
          Serial.println("Tank is empty, should to ON the motor and i already ON the motor");    //the message you want to send
          delay(500);
          Serial.write(26);
          delay(500);
   }
}

 
