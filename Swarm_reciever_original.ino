

//Constants
const int ledPin = 3; //Led to Arduino pin 3 (PWM)

//Variables
bool started= false;//True: Message is strated
bool ended  = false;//True: Message is finished 
char incomingByte ; //Variable to store the incoming byte                                                   
char msg[3];    //Message - array from 0 to 2 (3 values - PWM - e.g. 240)
byte index;     //Index of array

void setup() {
  //Start the serial communication
  Serial.begin(9600); //Baud rate must be the same as is on xBee module
  pinMode(13,OUTPUT);   //left motors forward
  pinMode(12,OUTPUT);   //left motors reverse
  pinMode(11,OUTPUT);   //right motors forward
  pinMode(10,OUTPUT);   //right motors reverse
  pinMode(9,OUTPUT);  
}

void loop() {
  
  int t=0;
//  if(t==0)
//  else
// {
//    digitalWrite(13,LOW);
//  digitalWrite(12,LOW);
//  digitalWrite(11,LOW);
//  digitalWrite(10,LOW);
// }
  
  while (Serial.available()>0)
  {
    //Read the incoming byte
    incomingByte = Serial.read();
    //Start the message when the '<' symbol is received
    if(incomingByte == '<')
    {
     started = true;
     index = 0;
     msg[index] = '\0'; // Throw away any incomplete packet
   }
   //End the message when the '>' symbol is received
   else if(incomingByte == '>')
   {
     ended = true;
     break; // Done reading - exit from while loop!
   }
   //Read the message!
   else
   {
     if(index < 4) // Make sure there is room
     {
       msg[index] = incomingByte; // Add char to array
       index++;
       msg[index] = '\0'; // Add NULL to end
     }
   }
 }
 
 if(started && ended)
 {
   t = atoi(msg);
   Serial.print(msg);
   Serial.print("   ");
//   analogWrite(ledPin, value);
 //  Serial.println(value);
   //Serial.println(value); //Only for debugging
   index = 0;
   msg[index] = '\0';
   started = false;
   ended = false;
   
if(t ==1){          
  //Ending symbol//move forward(all motors rotate in forward direction)
  digitalWrite(13,HIGH);
  digitalWrite(11,HIGH);
   digitalWrite(12,LOW);
    digitalWrite(10,LOW);
    //t=0;
  }
 
else if(t ==2){  
  //Ending symbol//move reverse (all motors rotate in reverse direction)
  digitalWrite(12,HIGH);
  digitalWrite(10,HIGH);
   digitalWrite(11,LOW);
    digitalWrite(13,LOW);
    //t=0;
  }
 
else if(t ==3)
  {    
   //Ending symbol//turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(11,HIGH);
   digitalWrite(12,LOW);
    digitalWrite(10,LOW);
     digitalWrite(13,LOW);
  //   t=0;
  }
 
else if(t ==4)
  {  
  //Ending symbol//turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(13,HIGH);
   digitalWrite(12,LOW);
    digitalWrite(11,LOW);
     digitalWrite(10,LOW);
  //   t=0;
  }
else if(t ==5)
  {    
   //Ending symbol//STOP (all motors stop)
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
//  t=0;
 }
 }
 else if(t==0)
 {
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
  }
delay(200);
}
