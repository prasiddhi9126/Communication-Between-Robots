#include <VirtualWire.h> 
//to send short messages, retransmit using ASK (amplitude Shift Keying)

void setup()
{
  
  pinMode(5,OUTPUT);   //left motors forward
pinMode(6,OUTPUT);   //left motors reverse
pinMode(9,OUTPUT);   //right motors forward
pinMode(11,OUTPUT);   //right motors reverse 
Serial.begin(9600);
    vw_set_rx_pin(3); //Receiving pin 3 is RX pin
    vw_setup(2000); // initialise virtual wires software to operate at spped bits per second, here we 2000 bits per second
    pinMode(3, INPUT);
    vw_rx_start(); //Starts receiving signals
}

void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];// pointer to location to save the read data //pointer to data to transmit
    uint8_t buflen = VW_MAX_MESSAGE_LEN; //len is the available space in buf // number of octetes to transmit
 
    if (vw_get_message(buf, &buflen)) // check to see if anything has been received
    {
      if(buf[0]=='f')
      {  
    digitalWrite(9,HIGH);
      digitalWrite(5,HIGH);
      }  
      else if(buf[0]=='b')
      {
    digitalWrite(6,HIGH);
    digitalWrite(11,HIGH);
      }
      
      else if(buf[0]=='l')
      {
        
  digitalWrite(5,HIGH);
      }
      
      else if(buf[0]=='r')
      {
          digitalWrite(9,HIGH);
      }
      
      else if(buf[0]=='s')
      {
          digitalWrite(9,LOW);
  digitalWrite(6,LOW);
  digitalWrite(5,LOW);
  digitalWrite(11,LOW);
      }
      }

    }
   
