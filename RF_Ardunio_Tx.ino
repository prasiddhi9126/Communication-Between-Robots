#include <VirtualWire.h>
char t;

void setup() 
{
  pinMode(5,OUTPUT);   //left motors forward
pinMode(6,OUTPUT);   //left motors reverse
pinMode(9,OUTPUT);   //right motors forward
pinMode(11,OUTPUT);   //right motors reverse
Serial.begin(9600);

  vw_set_tx_pin(3); //transmitting pin 3 is Tx pin
  vw_setup(2000);
  pinMode (5, LOW);
  pinMode (6, LOW);
  pinMode (9, LOW);
  pinMode (11, LOW); 

 
}
void loop()
{
   if(Serial.available()){ 
  t = Serial.read();
  Serial.println(t);
}
  if(t == 'F')
  {
    vw_wait_tx();    
    digitalWrite(9,HIGH);
    digitalWrite(5,HIGH);
  }
  else if(t =='B')
  {
    vw_wait_tx();
    digitalWrite(6,HIGH);
    digitalWrite(11,HIGH);

  }
  else if(t == 'L'){
    
    vw_wait_tx();      
  digitalWrite(9,HIGH);//turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
}
 
else if(t == 'R'){
  
    vw_wait_tx();//turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(5,HIGH);
}


 
else if(t == 'S'){
  
    vw_wait_tx();//STOP (all motors stop)
  digitalWrite(9,LOW);
  digitalWrite(6,LOW);
  digitalWrite(5,LOW);
  digitalWrite(11,LOW);
}
}
