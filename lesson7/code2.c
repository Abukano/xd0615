#include <MsTimer2.h>
#define in1 7
#define in2 4
#define in3 5
#define in4 6
int pinInterrupt= 2;
int num =0;
void onChange()
{
  num =0;
}
void light(int n)
{
  int a[3]={0};
  for(int i=0;i<=3;i++)
  {
    a[i]=n%2;
    n=n/2;
  }
  digitalWrite(in1,a[0]);
  digitalWrite(in2,a[1]);
  digitalWrite(in3,a[2]);
  digitalWrite(in4,a[3]);
  
}
void onTimer()
{
  light (num++);
}
void setup()
{
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(2, INPUT);
  MsTimer2::set(1000, onTimer);
  MsTimer2::start(); 
}

void loop()
{
  attachInterrupt( digitalPinToInterrupt(pinInterrupt), onChange, CHANGE);
}