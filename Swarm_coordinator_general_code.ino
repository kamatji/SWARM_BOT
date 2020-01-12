//char t;
#include<SoftwareSerial.h>
SoftwareSerial portONE(5,6);//Rx,Tx
SoftwareSerial portTWO(8,9);//Rx,Tx
void setup() {
pinMode(13,OUTPUT);   //left motors forward
pinMode(12,OUTPUT);   //left motors reverse
pinMode(11,OUTPUT);   //right motors forward
pinMode(10,OUTPUT);   //right motors reverse
Serial.begin(9600);
while(!Serial)
{
  ;
}
//portONE.begin(9600);
portTWO.begin(9600);
 
}

 
void loop() 
{
  char t='F';
 // portONE.listen();
//if(Serial.available())
//{
//  t = Serial.read();
////  t = Serial.read();
////  Serial.println(t);
//}
//t='F';
 
if(t == 'F'){ 
  portTWO.listen();         
   portTWO.print('<');  //Starting symbol
  portTWO.print('1');//Value from 0 to 255
  portTWO.println('>');//Ending symbol//move forward(all motors rotate in forward direction)
  digitalWrite(13,HIGH);
  digitalWrite(11,HIGH);
   digitalWrite(12,LOW);
    digitalWrite(10,LOW);
}
 
else if(t == 'B'){  
  portTWO.listen();
   portTWO.print('<');  //Starting symbol
  portTWO.print('2');//Value from 0 to 255
  portTWO.println('>');//Ending symbol//move reverse (all motors rotate in reverse direction)
  digitalWrite(12,HIGH);
  digitalWrite(10,HIGH);
   digitalWrite(11,LOW);
    digitalWrite(13,LOW);
}
 
else if(t == 'L'){    
  portTWO.listen();
   portTWO.print('<');  //Starting symbol
  portTWO.print('3');//Value from 0 to 255
  portTWO.println('>');//Ending symbol//turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(11,HIGH);
   digitalWrite(12,LOW);
    digitalWrite(10,LOW);
     digitalWrite(13,LOW);
}
 
else if(t == 'R'){  
  portTWO.listen();
   portTWO.print('<');  //Starting symbol
  portTWO.print('4');//Value from 0 to 255
 portTWO.println('>');//Ending symbol//turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(13,HIGH);
   digitalWrite(12,LOW);
    digitalWrite(11,LOW);
     digitalWrite(10,LOW);
}
else if(t == 'S'){    
  portTWO.listen();
  portTWO.print('<');  //Starting symbol
  portTWO.print(5);//Value from 0 to 255
 portTWO.println('>');//Ending symbol//STOP (all motors stop)
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW); 
}
else
{
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}

delay(100);
}
