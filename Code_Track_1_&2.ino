
const int sfar_left = A0;
const int sleft = A1;
const int smid = A2;
const int sright = A3;
const int sfar_right = A4;

const int leftRev = 3;
const int leftFor = 4;
const int rightFor = 5;
const int rightRev = 6;

const int speedL = 10;
const int speedR = 11;

 int maxspeed = 70; 

 int min_lim = 400; 

 int left2;
  int left1;
  int mid;
  int right1;
  int right2;


void forward(){
  digitalWrite(leftRev, LOW); 
  digitalWrite(leftFor, HIGH);
  digitalWrite(rightRev, LOW); 
  digitalWrite(rightFor, HIGH);
  analogWrite(speedL, maxspeed);
  analogWrite(speedR, maxspeed);
  
  
}

void turn_left(){ 
  digitalWrite(leftRev, HIGH); 
  digitalWrite(leftFor, LOW);
  digitalWrite(rightRev, LOW); 
  digitalWrite(rightFor, HIGH);
  analogWrite(speedL, 0.8 * maxspeed);
  analogWrite(speedR, maxspeed);
}


void turn_farleft(){
  digitalWrite(leftRev, HIGH); 
  digitalWrite(leftFor, LOW);
  digitalWrite(rightRev, LOW); 
  digitalWrite(rightFor, HIGH);
  analogWrite(speedL, 0.6 * maxspeed);
  analogWrite(speedR,  maxspeed);
}

void turn_right(){ 
  digitalWrite(leftRev, LOW); 
  digitalWrite(leftFor, HIGH);
  digitalWrite(rightRev, HIGH); 
  digitalWrite(rightFor, LOW);
  analogWrite(speedL, maxspeed);
  analogWrite(speedR, 0.8 * maxspeed);
}


void turn_farright(){
  digitalWrite(leftRev, LOW); 
  digitalWrite(leftFor, HIGH);
  digitalWrite(rightRev, HIGH); 
  digitalWrite(rightFor, LOW);
  analogWrite(speedL,  maxspeed);
  analogWrite(speedR, 0.6 * maxspeed);
}

void setup() {
 Serial.begin(115200);
    Serial.println("Starting");


 pinMode(leftRev, OUTPUT);
 pinMode(leftFor, OUTPUT);
 pinMode(rightRev, OUTPUT);
 pinMode(rightFor, OUTPUT);

 pinMode(speedL, OUTPUT); 
 pinMode(speedR, OUTPUT);

 analogWrite(speedL, 0);
 analogWrite(speedR, 0);

 
TCCR2B = TCCR2B & B11111000 | B00000111;
TCCR1B = TCCR1B & B11111000 | B00000101;
  
}

void loop() {
    //delay(50);
 //   Serial.println("decidin");

    

  left2 = analogRead(sfar_left);
  left1 = analogRead(sleft);
  mid =  analogRead(smid);
  right1 = analogRead(sright);
  right2 = analogRead(sfar_right);

Serial.println(analogRead(sleft));
Serial.println(left1);
Serial.println(mid);
Serial.println(right1);
Serial.println(right2);


 



  if ( mid > min_lim){
        //if( left2 < min_lim && left1 < min_lim && right1 < min_lim && right2 < min_lim){
      forward();
      Serial.print("forward");
    //}
  }

  //else if ((left1 > min_lim && mid > min_lim) || (right1 > min_lim && mid > min_lim)){
      //Serial.print("FORWARD");
  //}

  else if ( left2 < min_lim && left1 > min_lim && mid < min_lim && right1< min_lim && right2 < min_lim){
    turn_left();
    Serial.print("left"); 
  }

   else if ( left2 > min_lim && left1 < min_lim && mid < min_lim && right1< min_lim && right2 < min_lim){
    turn_farleft();
    Serial.print("LEFT");
  }

   else if ( left2 < min_lim && left1 < min_lim && mid < min_lim && right1 >  min_lim && right2 < min_lim){
    turn_right();
    Serial.print("right");
  }

   else if ( left2 < min_lim && left1 < min_lim && mid < min_lim && right1< min_lim && right2 > min_lim){
    turn_farright();
    Serial.print("RIGHT");
  }

  else if ( left2 < min_lim && left1 < min_lim && mid < min_lim && right1< min_lim && right2 < min_lim){
      maxspeed = 40;
      turn_left();
      Serial.print("circle");
      maxspeed = 70;
    
  }
}
