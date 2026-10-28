#include <Stepper.h>
#include <IRremote.h>

const int stepsPerRevolution = 2048;
const int stepsPerCM = 100;

int btn1 = 5;
int btn2 = 6;
int btn3 = 7;

int irPin = 12; //kumanda
String buton1 = "BA45FF00";
String buton2 = "B946FF00";
String buton3 = "B847FF00";
String kod, sonkod;

Stepper motor1(stepsPerRevolution, 1, 2, 3, 4); // SAĞ motor
Stepper motor2(stepsPerRevolution, 8, 9, 10, 11);   // SOL motor

int currentX = 50;
int currentY = 25;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(irPin, 0); //kumanda- 0 değeri led durumu
  pinMode(13, OUTPUT);//buzzer
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(btn3, INPUT_PULLUP);

  motor1.setSpeed(10); //motor hızları 
  motor2.setSpeed(10); //motor hızları
}

void loop() {
  if (IrReceiver.decode()) {//kumandadan sinyal geliyor mu
    kod = String(IrReceiver.decodedIRData.decodedRawData, HEX);//kod elde ediliyor
    //sinyalin eksik geldiği durumlarda robotun düzgün çalışmasını sağlamak için
    if (kod != "0") {//geçerli bir kod mu
      sonkod = kod;
    } else {
      kod = sonkod;
    }
    kod.toUpperCase();//kodu büyük harfe çeviriyor

    if (digitalRead(btn1) == LOW || kod == buton1) {
      tone(13, 440,200);
      noTone(13);
      moveVertical(50);    // Y: 25 → 50 (yukarı)
      moveHorizontal(100); // X: 50 → 100 (sağa)

      moveHorizontal(0);   // İlk satır: sağdan sola

      for (int newY = currentY - 10; newY >= 0; newY -= 10) {
        moveVertical(newY);
        if (currentX == 0) {
          moveHorizontal(100); // soldan sağa
        } else {
          moveHorizontal(0);   // sağdan sola
        }
      }

      moveVertical(25);
      moveHorizontal(50);

      delay(1000);
    }
    else if (digitalRead(btn2) == LOW || kod == buton2) {
      tone(13, 523,200);
      noTone(13);
      moveVertical(25);
      moveHorizontal(0);
      delay(500);
    }
    else if (digitalRead(btn3) == LOW || kod == buton3) {
      tone(13, 659,200);
      noTone(13);
      moveVertical(0);
      moveHorizontal(50);
      delay(500);
    }

    IrReceiver.resume();
  }
}

// YATAY hareket: SAĞ–SOL doğrultusunda
void moveHorizontal(int targetX) {
  if (targetX == currentX) return;
  int stepCount = abs(targetX - currentX) * stepsPerCM; // ne kadar sarılacığını veya salınacağını ifade eder

  if (targetX > currentX) {
    // Sağa giderken:
    // Sağ motor ip sarar (+)
    // Sol motor ip bırakır (–)
    for (int i = 0; i < stepCount; i++) {
      motor1.step(1);  // sağ motor ileri (sarar)
      motor2.step(-1); // sol motor geri (sal)
    }
  } else {
    // Sola giderken:
    // Sol motor sarar (+)
    // Sağ motor bırakır (–)
    for (int i = 0; i < stepCount; i++) {
      motor1.step(-1); // sağ motor geri (sal)
      motor2.step(1);  // sol motor ileri (sarar)
    }
  }

  currentX = targetX;
}

// DİKEY hareket: YUKARI–AŞAĞI doğrultusunda
void moveVertical(int targetY) {
  if (targetY == currentY) return;
  int stepCount = abs(targetY - currentY) * stepsPerCM;

  if (targetY > currentY) {
    // Yukarı çıkarken: İkisi de sarar
    for (int i = 0; i < stepCount; i++) {
      motor1.step(1);
      motor2.step(1);
    }
  } else {
    // Aşağı inerken: İkisi de bırakır
    for (int i = 0; i < stepCount; i++) {
      motor1.step(-1);
      motor2.step(-1);
    }
  }

  currentY = targetY;
}
