#include<stdio.h>
#define in3 6
#define in4 5
#define in1 8
#define in2 9
char ch = ' ';
#include <IRremote.h>  
int RECV_PIN = 11;  
IRrecv irrecv(RECV_PIN);   
decode_results results; 

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
      /*
      if (irrecv.decode(&results))//解码成功，收到一组红外讯号   
	  {  
	    Serial.println(results.value);//以16进制换行输出接收代码  
	    irrecv.resume(); // 接收下一个值  
	  }  
	  delay(100);
      */
  
    if(irrecv.decode(&results))
  	{
      if(results.value == 16615543)
      {
        digitalWrite(in1,HIGH);
        digitalWrite(in2,LOW);
        digitalWrite(in3,HIGH);
        digitalWrite(in4,LOW);
      }
      else if(results.value == 16619623)
      {
        digitalWrite(in1,LOW);
        digitalWrite(in2,HIGH);
        digitalWrite(in3,LOW);
        digitalWrite(in4,HIGH);
      }  
      else if(results.value == 16607383)
      {
        digitalWrite(in1,HIGH);
        digitalWrite(in2,LOW);
        digitalWrite(in3,LOW);
        digitalWrite(in4,LOW);
      }
      else if(results.value == 16591063)
      {
        digitalWrite(in1,LOW);
        digitalWrite(in2,LOW);
        digitalWrite(in3,HIGH);
        digitalWrite(in4,LOW);
      }
      else if(results.value == 16623703)
      {
        digitalWrite(in1,LOW);
        digitalWrite(in2,LOW);
        digitalWrite(in3,LOW);
        digitalWrite(in4,LOW);
      }
      irrecv.resume();
      delay(50);
  	}
  /*
  if(Serial.available()>0)
  {
    ch = Serial.read();
    if(ch == 'f')
    {
      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);
      digitalWrite(in3,HIGH);
      digitalWrite(in4,LOW);
    }
    else if(ch == 'b')
    {
      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
    }  
    else if(ch== 'r')
    {
      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);
      digitalWrite(in3,LOW);
      digitalWrite(in4,LOW);
    }
    else if(ch== 'l')
    {
      digitalWrite(in1,LOW);
      digitalWrite(in2,LOW);
      digitalWrite(in3,HIGH);
      digitalWrite(in4,LOW);
    }
    else if(ch== 's')
    {
      digitalWrite(in1,LOW);
      digitalWrite(in2,LOW);
      digitalWrite(in3,LOW);
      digitalWrite(in4,LOW);
    }
  }
  */
}