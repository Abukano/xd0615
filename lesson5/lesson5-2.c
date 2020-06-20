#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5
#define S1 8
#define S2 9
#define S3 10
#define S4 11
#define LT 6
#define BT 7
void setup()
{
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);输入1
  pinMode(IN2, OUTPUT);输入2
  pinMode(IN3, OUTPUT);输入3
  pinMode(IN4, OUTPUT);输入4
  pinMode(S1, OUTPUT);片选1
  pinMode(S2, OUTPUT);片选2
  pinMode(S3, OUTPUT);片选3
  pinMode(S4, OUTPUT);片选4
  pinMode(LT,OUTPUT);测试
  pinMode(BT,OUTPUT);消隐
  digitalWrite(BT,HIGH);
  digitalWrite(LT,HIGH);
  digitalWrite(S1,LOW);
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  digitalWrite(S4,LOW);
}
byte income =0;
void loop()
{
  
  if(Serial.available()0)
  {
    int s[3];
    s[0]=S1;
    s[1]=S2;
    s[2]=S3;
    s[3]=S4;
    
     for(int i=3;i=0;i--)
    {   
  	 
      digitalWrite(s[3-i],LOW);
    }
    for(int i=3;i=0;i--)
    {   
  	  income=Serial.read();
    
      income=income-'0';
      digitalWrite(IN1,income&0x1);
      digitalWrite(IN2,(income1)&0x1);
      digitalWrite(IN3,(income2)&0x1);
      digitalWrite(IN4,(income3)&0x1);
      delay(10);
      digitalWrite(s[3-i],HIGH);
    }
  }

}