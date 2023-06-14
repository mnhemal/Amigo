#include <NewPing.h>
#include <Servo.h>
#include <AFMotor.h>
#define RIGHT A2
#define LEFT A3
#define TRIGGER_PIN A1
#define ECHO_PIN A0
#define MAX_DISTANCE 100
String readString = "";

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);


AF_DCMotor Motor1(1, MOTOR12_1KHZ);
AF_DCMotor Motor2(2, MOTOR12_1KHZ);
AF_DCMotor Motor3(3, MOTOR34_1KHZ);
AF_DCMotor Motor4(4, MOTOR34_1KHZ);

Servo head;
Servo right;
Servo left;




int pos = 0;

void setup() {
  Serial.begin(9600);
  right.attach(10);
  left.attach(9);
  head.attach(12);
  {
    for (pos = 70; pos <= 180; pos += 1) {
      head.write(pos);
      delay(15);
    }
    for (pos = 180; pos >= 0; pos -= 1) {
      head.write(pos);
      delay(15);
    }
    for (pos = 0; pos <= 70; pos += 1) {
      head.write(pos);
      delay(15);
    }
  }
  pinMode(RIGHT, INPUT);
  pinMode(LEFT, INPUT);
}

void loop() {

  while (Serial.available()) {

    char c = (char)Serial.read();
    readString += c;
  }
  //Serial.println(readString);
  if (readString.length() > 0) {

    if (readString == "forward") {
      {
        Motor1.setSpeed(160);
        Motor1.run(FORWARD);
        Motor2.setSpeed(160);
        Motor2.run(FORWARD);
        Motor3.setSpeed(160);
        Motor3.run(FORWARD);
        Motor4.setSpeed(160);
        Motor4.run(FORWARD);
      }
      delay(1000);

      Serial.print("forward");
    }

    else if (readString == "back") {
      Motor1.setSpeed(160);
      Motor1.run(BACKWARD);
      Motor2.setSpeed(160);
      Motor2.run(BACKWARD);
      Motor3.setSpeed(160);
      Motor3.run(BACKWARD);
      Motor4.setSpeed(160);
      Motor4.run(BACKWARD);
      delay(1000);
      Serial.print("back");
    }


    else if (readString == "stop") {
      Motor1.setSpeed(0);
      Motor1.run(RELEASE);
      Motor2.setSpeed(0);
      Motor2.run(RELEASE);
      Motor3.setSpeed(0);
      Motor3.run(RELEASE);
      Motor4.setSpeed(0);
      Motor4.run(RELEASE);
      delay(1000);
      Serial.print("Stoped");
    } else if (readString == "Stop") {
      Motor1.setSpeed(0);
      Motor1.run(RELEASE);
      Motor2.setSpeed(0);
      Motor2.run(RELEASE);
      Motor3.setSpeed(0);
      Motor3.run(RELEASE);
      Motor4.setSpeed(0);
      Motor4.run(RELEASE);
      delay(1000);
      Serial.print("Stoped");
    } else if (readString == "left") {
      Motor1.setSpeed(150);
      Motor1.run(BACKWARD);
      Motor2.setSpeed(150);
      Motor2.run(BACKWARD);
      Motor3.setSpeed(250);
      Motor3.run(FORWARD);
      Motor4.setSpeed(250);
      Motor4.run(FORWARD);
      delay(500);
      Serial.print("left");
    } else if (readString == "right") {
      Motor1.setSpeed(250);
      Motor1.run(FORWARD);
      Motor2.setSpeed(250);
      Motor2.run(FORWARD);
      Motor3.setSpeed(150);
      Motor3.run(BACKWARD);
      Motor4.setSpeed(150);
      Motor4.run(BACKWARD);
      delay(500);
      Serial.print("right");
    }
else if (readString == "turn around") {
      Motor1.setSpeed(250);
      Motor1.run(FORWARD);
      Motor2.setSpeed(250);
      Motor2.run(FORWARD);
      Motor3.setSpeed(150);
      Motor3.run(BACKWARD);
      Motor4.setSpeed(150);
      Motor4.run(BACKWARD);
      delay(1000);
      Serial.print("turn around");
    }
else if (readString == "Turn around") {
      Motor1.setSpeed(250);
      Motor1.run(FORWARD);
      Motor2.setSpeed(250);
      Motor2.run(FORWARD);
      Motor3.setSpeed(150);
      Motor3.run(BACKWARD);
      Motor4.setSpeed(150);
      Motor4.run(BACKWARD);
      delay(1000);
      Serial.print("left");
    }

    else if (readString == "look") {
      Head();
    } else if (readString == "Look") {
      Head();
    } else if (readString == "Raise your left hand") {
      Left();
    } else if (readString == "raise your left hand") {
      Left();
    } else if (readString == "Raise your right hand") {
      Right();
    } else if (readString == "raise your right hand") {
      Right();
    } 

    else if (readString == "Hi") {
      Serial.println("Hello");

    } else if (readString == "hi") {
      Serial.println("Hello");

    } else if (readString == "Introduce yourself") {
      Serial.println("I am human assistant robot. Made by team penta Circuit Breakers");

    } else if (readString == "introduce yourself") {
      Serial.println("I am human assistant robot. Made by team penta Circuit Breakers");

    } else if (readString == "Tell me about team penta circuit breakers") {
      Serial.println("Penta Circuit Breakers is a robomaker team. Hemel, Sadik, Abdul Halim, Atiq and Shoha are the members of this team");

    } else if (readString == "tell me about team penta circuit breakers") {
      Serial.println("Penta Circuit Breakers is a robomaker team. Hemel, Sadik, Abdul Halim, Atiq and Shoha are the members of this team");

    } else if (readString == "What can you do") {
      Serial.println("I can listen speak and follow you");

    }

    else if (readString == "what can you do") {
      Serial.println("I can listen speak and follow you");

    } else if (readString == "Do you have any knowledge about BDU") {

      Serial.println("Yes I have Bangabandhu Sheikh Mujibur Rahman Digital University Bangladesh is the first specialized government digital university in Bangladesh. The university is situated in Kaliakair Gazipur District adjacent to Bangabandhu Hi-Tech Park");
    }
    else if (readString == "Do you have any knowledge about bdu") {

      Serial.println("Yes I have Bangabandhu Sheikh Mujibur Rahman Digital University Bangladesh is the first specialized government digital university in Bangladesh. The university is situated in Kaliakair Gazipur District adjacent to Bangabandhu Hi-Tech Park");
    } else if (readString == "who is the vice chancellor of BDU") {
      Serial.println("Professor Doctor MOHAMMAD MAHFUZUL ISLAM");
    }
    else if (readString == "who is the vice chancellor of bdu") {
      Serial.println("Professor Doctor MOHAMMAD MAHFUZUL ISLAM");
    }
     else if (readString == "Who is the vice chancellor of BDU") {

      Serial.println("Professor Doctor MOHAMMAD MAHFUZUL ISLAM");
    } 
    else if (readString == "Who is the vice chancellor of bdu") {

      Serial.println("Professor Doctor MOHAMMAD MAHFUZUL ISLAM");
    }
    else if (readString == "do you have any knowledge about BDU") {

      Serial.println("Yes I have Bangabandhu Sheikh Mujibur Rahman Digital University Bangladesh is the first specialized government digital university in Bangladesh. The university is situated in Kaliakair Gazipur District adjacent to Bangabandhu Hi-Tech Park");
    }
else if (readString == "do you have any knowledge about bdu") {

      Serial.println("Yes I have Bangabandhu Sheikh Mujibur Rahman Digital University Bangladesh is the first specialized government digital university in Bangladesh. The university is situated in Kaliakair Gazipur District adjacent to Bangabandhu Hi-Tech Park");
    }
    else if (readString == "Tell me about Bangladesh") {

      Serial.println("Bangladesh is a developing country of south asia. Bangladesh gained independence in 1971. The father of the nation of Bangladesh is Bangabandhu Sheikh Mujibur Rahman");
    }

    else if (readString == "tell me about Bangladesh") {

      Serial.println("Bangladesh is a developing country of south asia. Bangladesh gained independence in 1971. The father of the nation of Bangladesh is Bangabandhu Sheikh Mujibur Rahman");
    }

    else if (readString == "What is your name") {

      Serial.println("I am   Amigo");
    } else if (readString == "what is your name") {

      Serial.println("I am   Amigo");
    }
    readString = "";
  }
  delay(100);
dection();

}


void dection() {
  delay(50);
  unsigned int distance = sonar.ping_cm();
  // Serial.print("distance");
  // Serial.println(distance);


  int Right_Value = digitalRead(RIGHT);
  int Left_Value = digitalRead(LEFT);

  //Serial.print("RIGHT");
  // Serial.println(Right_Value);
  // Serial.print("LEFT");
  // Serial.println(Left_Value);

  if ((Right_Value == 1) && (distance >= 10 && distance <= 35) && (Left_Value == 1)) {
    Motor1.setSpeed(160);
    Motor1.run(FORWARD);
    Motor2.setSpeed(160);
    Motor2.run(FORWARD);
    Motor3.setSpeed(160);
    Motor3.run(FORWARD);
    Motor4.setSpeed(160);
    Motor4.run(FORWARD);
  } else if ((Right_Value == 0) && (Left_Value == 1)) {
    Motor1.setSpeed(250);
    Motor1.run(FORWARD);
    Motor2.setSpeed(250);
    Motor2.run(FORWARD);
    Motor3.setSpeed(150);
    Motor3.run(BACKWARD);
    Motor4.setSpeed(150);
    Motor4.run(BACKWARD);
  } else if ((Right_Value == 1) && (Left_Value == 0)) {
    Motor1.setSpeed(150);
    Motor1.run(BACKWARD);
    Motor2.setSpeed(150);
    Motor2.run(BACKWARD);
    Motor3.setSpeed(250);
    Motor3.run(FORWARD);
    Motor4.setSpeed(250);
    Motor4.run(FORWARD);
  } else if ((Right_Value == 1) && (Left_Value == 1)) {
    Motor1.setSpeed(0);
    Motor1.run(RELEASE);
    Motor2.setSpeed(0);
    Motor2.run(RELEASE);
    Motor3.setSpeed(0);
    Motor3.run(RELEASE);
    Motor4.setSpeed(0);
    Motor4.run(RELEASE);
  } else if (distance > 1 && distance < 10) {
    Motor1.setSpeed(0);
    Motor1.run(RELEASE);
    Motor2.setSpeed(0);
    Motor2.run(RELEASE);
    Motor3.setSpeed(0);
    Motor3.run(RELEASE);
    Motor4.setSpeed(0);
    Motor4.run(RELEASE);
  }
}


void Right() {
  for (pos = 20; pos <= 90; pos += 1) {
    right.write(pos);
    delay(15);
  }
  for (pos = 90; pos >= 20; pos -= 1) {
    right.write(pos);
    delay(15);
  }
}
void Left() {
  for (pos = 180; pos >= 90; pos -= 1) {
    left.write(pos);
    delay(15);
  }
  for (pos = 90; pos <= 180; pos += 1) {
    left.write(pos);
    delay(15);
  }
}
void Head() {
  for (pos = 70; pos <= 180; pos += 1) {
    head.write(pos);
    delay(15);
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    head.write(pos);
    delay(15);
  }
  for (pos = 0; pos <= 70; pos += 1) {
      head.write(pos);
      delay(15);
    }
}