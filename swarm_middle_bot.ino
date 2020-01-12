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
portONE.begin(9600);
portTWO.begin(9600);
 
}

void movement(int s)
{
  if(s ==1){          
  //Ending symbol//move forward(all motors rotate in forward direction)
  digitalWrite(13,HIGH);
  digitalWrite(11,HIGH);
   digitalWrite(12,LOW);
    digitalWrite(10,LOW);
    //t=0;
  }
 
else if(s ==2){  
  //Ending symbol//move reverse (all motors rotate in reverse direction)
  digitalWrite(12,HIGH);
  digitalWrite(10,HIGH);
   digitalWrite(11,LOW);
    digitalWrite(13,LOW);
    //t=0;
  }
 
else if(s ==3)
  {    
   //Ending symbol//turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(11,HIGH);
   digitalWrite(12,LOW);
    digitalWrite(10,LOW);
     digitalWrite(13,LOW);
  //   t=0;
  }
 
else if(s ==4)
  {  
  //Ending symbol//turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(13,HIGH);
   digitalWrite(12,LOW);
    digitalWrite(11,LOW);
     digitalWrite(10,LOW);
  //   t=0;
  }
else if(s ==5)
  {    
   //Ending symbol//STOP (all motors stop)
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
//  t=0;
 }
 
 else if(s==0)
 {
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
  }
  
} 
char t="";
void loop() 
{
//  char t="";
 // portONE.listen();
if(Serial.available())
{
  t = Serial.read();
  Serial.println(t);
}
//t='F';
 
if(t == 'F'){ 
  portTWO.listen();         
   portTWO.print('<');  //Starting symbol
  portTWO.print('1');//Value from 0 to 255
  portTWO.println('>');//Ending symbol//move forward(all motors rotate in forward direction)
    movement(1);//forward
    delay(5000);
    movement(0);//stop the bot
    delay(10000);
    movement(2);//backward
    delay(5000);
    movement(0);//stop
}
 
else if(t == 'B'){  
  portTWO.listen();
   portTWO.print('<');  //Starting symbol
  portTWO.print('2');//Value from 0 to 255
  portTWO.println('>');//Ending symbol//move reverse (all motors rotate in reverse direction)
  movement(0);
}
 
else if(t == 'L'){    
  portTWO.listen();
   portTWO.print('<');  //Starting symbol
  portTWO.print('3');//Value from 0 to 255
  portTWO.println('>');//Ending symbol//turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  movement(1);
  delay(5000);
  movement(0);
  delay(10000);
  movement(2);
  delay(5000);
  movement(0);
}
 
else if(t == 'R'){  
  portTWO.listen();
   portTWO.print('<');  //Starting symbol
  portTWO.print('4');//Value from 0 to 255
 portTWO.println('>');//Ending symbol//turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
movement(0);
}
else if(t == 'S'){    
  portTWO.listen();
  portTWO.print('<');  //Starting symbol
  portTWO.print(5);//Value from 0 to 255
 portTWO.println('>');//Ending symbol//STOP (all motors stop)
  movement(0);
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
