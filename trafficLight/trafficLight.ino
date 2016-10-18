int L1_red = 13;
int L1_yellow = 12;
int L1_green = 11;
int L2_red = 10;
int L2_yellow = 9;
int L2_green = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(L1_red, OUTPUT);
  pinMode(L1_yellow, OUTPUT);
  pinMode(L1_green, OUTPUT);
  pinMode(L2_red, OUTPUT);
  pinMode(L2_yellow, OUTPUT);
  pinMode(L2_green, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  int i;
  static int onoff = 0;
  static int offon = 1;

  digitalWrite(L1_yellow, LOW);
  digitalWrite(L2_yellow, LOW); 
  //-----------------------------------------------
  // Stage 1
  digitalWrite(L1_red, onoff);
  digitalWrite(L1_green, offon);
  digitalWrite(L2_red, offon);
  digitalWrite(L2_green, onoff);
  delay(5000);
  
  //-----------------------------------------------
  // Stage 2
  for(i = 0; i < 5; i++)
  {
    digitalWrite(L1_red, (onoff==1)?HIGH:LOW);
    digitalWrite(L1_green, (offon==1)?HIGH:LOW);
    digitalWrite(L2_red, (offon==1)?HIGH:LOW);
    digitalWrite(L2_green, (onoff==1)?HIGH:LOW);
    delay(500);

    digitalWrite(L1_red, LOW);
    digitalWrite(L1_green, LOW);
    digitalWrite(L2_red, LOW);
    digitalWrite(L2_green, LOW);
    delay(500);
  }
  
  //-----------------------------------------------
  // Stage 3
  digitalWrite(L1_yellow, HIGH);
  digitalWrite(L2_yellow, HIGH);
  digitalWrite(L1_red, LOW);
  digitalWrite(L1_green, LOW);
  digitalWrite(L2_red, LOW);
  digitalWrite(L2_green, LOW);
  
  delay(1000); 
  //-----------------------------------------------
  // switch
  if(onoff == 0)
  {
    onoff = 1;
    offon = 0;
  }
  else
  {
    onoff = 0;
    offon = 1;
  }

}
