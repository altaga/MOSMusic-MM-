int analog1=0;
int analogm=0;
double basemean=0;
int base=0;
int gain=-5;
unsigned int sensibility=5;
int counter=0;

void setup() 
{
pinMode(LED_BUILTIN,OUTPUT);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
digitalWrite(2,LOW);
digitalWrite(3,LOW);
digitalWrite(4,LOW);
digitalWrite(5,LOW);
Serial.begin(115200);
for(int i=0;i<100;i++)
{
basemean+=analogRead(A0);
}
base=(basemean/100)+gain;
analogm=analogRead(A0);
digitalWrite(LED_BUILTIN,LOW);
}

void loop() 
{
  analog1=analogRead(A0);

    if(abs(analog1-analogm)<sensibility && counter>=10)
  {
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
  }
   else if (abs(analog1-analogm)<sensibility && counter<10)
  {
    counter+=1;
  }
  else
  {
    counter=0;
    if(analog1>=(base-30) && analog1<(base-10))
  {
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
  }
    else if(analog1>=(base-10) && analog1<(base))
  {
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
  }
    else if(analog1>=(base) && analog1<(base+10))
  {
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
  }
    else if(analog1>=(base+10) && analog1<(base+20))
  {
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
  }
    else if(analog1>=(base+20) && analog1<(base+50))
  {
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
  }  
  }
  analogm=analog1;
  delay(50);
}
