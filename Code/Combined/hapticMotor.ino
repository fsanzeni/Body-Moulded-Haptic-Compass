bool playSingleWaveform(int effectNumber, int coolDown) {
  unsigned long time_now = 0;
  time_now = millis();

  // set the effect to play
  drv.setWaveform(0, effectNumber);                                         // play effect
  drv.setWaveform(1, 0);                                                    // end waveform

  // play the effect
  drv.go();
  Serial.println("Playing effect");

  while (millis() < time_now + coolDown) {
    // wait for cooldown period
  }

  return true;
}

void playTwoWaveforms(int firstEffect, int secondEffect, int coolDown) {
  unsigned long time_now = 0;
  time_now = millis();

  // set the effect to play
  drv.setWaveform(0, firstEffect);                                          // first haptic pattern
  drv.setWaveform(1, secondEffect);                                                    // second haptic pattern
  drv.setWaveform(2, 0);                                                    // end of waveforms

  // play effect
  drv.go();

  while (millis() < time_now + coolDown) {
    // wait for cooldown period
  }
}

int selectWaveform(int effect) {
  switch (effect) {
    case 1:
      Serial.println(F("1 − Strong Click - 100%"));
      return effect;
      break;

    case 2:
      Serial.println(F("2 − Strong Click - 60%"));
      return effect;
      break;

    case 3:
      Serial.println(F("3 − Strong Click - 30%"));
      return effect;
      break;

    case 4:
      Serial.println(F("4 − Sharp Click - 100%"));
      return effect;
      break;

    case 5:
      Serial.println(F("5 − Sharp Click - 60%"));
      return effect;
      break;

    case 6:
      Serial.println(F("6 − Sharp Click - 30%"));
      return effect;
      break;

    case 7:
      Serial.println(F("7 − Soft Bump - 100%"));
      return effect;
      break;

    case 8:
      Serial.println(F("8 − Soft Bump - 60%"));
      return effect;
      break;

    case 9:
      Serial.println(F("9 − Soft Bump - 30%"));
      return effect;
      break;

    case 10:
      Serial.println(F("10 − Double Click - 100%"));
      return effect;
      break;

    case 11:
      Serial.println(F("11 − Double Click - 60%"));
      return effect;
      break;

    case 12:
      Serial.println(F("12 − Triple Click - 100%"));
      return effect;
      break;

    case 13:
      Serial.println(F("13 − Soft Fuzz - 60%"));
      return effect;
      break;

    case 14:
      Serial.println(F("14 − Strong Buzz - 100%"));
      return effect;
      break;

    case 15:
      Serial.println(F("15 − 750 ms Alert 100%"));
      return effect;
      break;

    case 16:
      Serial.println(F("16 − 1000 ms Alert 100%"));
      return effect;
      break;

    case 17:
      Serial.println(F("17 − Strong Click 1 - 100%"));
      return effect;
      break;

    case 18:
      Serial.println(F("18 − Strong Click 2 - 80%"));
      return effect;
      break;

    case 19:
      Serial.println(F("19 − Strong Click 3 - 60%"));
      return effect;
      break;

    case 20:
      Serial.println(F("20 − Strong Click 4 - 30%"));
      return effect;
      break;

    case 21:
      Serial.println(F("21 − Medium Click 1 - 100%"));
      return effect;
      break;

    case 22:
      Serial.println(F("22 − Medium Click 2 - 80%"));
      return effect;
      break;

    case 23:
      Serial.println(F("23 − Medium Click 3 - 60%"));
      return effect;
      break;

    case 24:
      Serial.println(F("24 − Sharp Tick 1 - 100%"));
      return effect;
      break;

    case 25:
      Serial.println(F("25 − Sharp Tick 2 - 80%"));
      return effect;
      break;

    case 26:
      Serial.println(F("26 − Sharp Tick 3 – 60%"));
      return effect;
      break;

    case 27:
      Serial.println(F("27 − Short Double Click Strong 1 – 100%"));
      return effect;
      break;

    case 28:
      Serial.println(F("28 − Short Double Click Strong 2 – 80%"));
      return effect;
      break;

    case 29:
      Serial.println(F("29 − Short Double Click Strong 3 – 60%"));
      return effect;
      break;

    case 30:
      Serial.println(F("30 − Short Double Click Strong 4 – 30%"));
      return effect;
      break;

    case 31:
      Serial.println(F("31 − Short Double Click Medium 1 – 100%"));
      return effect;
      break;

    case 32:
      Serial.println(F("32 − Short Double Click Medium 2 – 80%"));
      return effect;
      break;

    case 33:
      Serial.println(F("33 − Short Double Click Medium 3 – 60%"));
      return effect;
      break;

    case 34:
      Serial.println(F("34 − Short Double Sharp Tick 1 – 100%"));
      return effect;
      break;

    case 35:
      Serial.println(F("35 − Short Double Sharp Tick 2 – 80%"));
      return effect;
      break;

    case 36:
      Serial.println(F("36 − Short Double Sharp Tick 3 – 60%"));
      return effect;
      break;

    case 37:
      Serial.println(F("37 − Long Double Sharp Click Strong 1 – 100%"));
      return effect;
      break;

    case 38:
      Serial.println(F("38 − Long Double Sharp Click Strong 2 – 80%"));
      return effect;
      break;

    case 39:
      Serial.println(F("39 − Long Double Sharp Click Strong 3 – 60%"));
      return effect;
      break;

    case 40:
      Serial.println(F("40 − Long Double Sharp Click Strong 4 – 30%"));
      return effect;
      break;

    case 41:
      Serial.println(F("41 − Long Double Sharp Click Medium 1 – 100%"));
      return effect;
      break;

    case 42:
      Serial.println(F("42 − Long Double Sharp Click Medium 2 – 80%"));
      return effect;
      break;

    case 43:
      Serial.println(F("43 − Long Double Sharp Click Medium 3 – 60%"));
      return effect;
      break;

    case 44:
      Serial.println(F("44 − Long Double Sharp Tick 1 – 100%"));
      return effect;
      break;

    case 45:
      Serial.println(F("45 − Long Double Sharp Tick 2 – 80%"));
      return effect;
      break;

    case 46:
      Serial.println(F("46 − Long Double Sharp Tick 3 – 60%"));
      return effect;
      break;

    case 47:
      Serial.println(F("47 − Buzz 1 – 100%"));
      return effect;
      break;

    case 48:
      Serial.println(F("48 − Buzz 2 – 80%"));
      return effect;
      break;

    case 49:
      Serial.println(F("49 − Buzz 3 – 60%"));
      return effect;
      break;

    case 50:
      Serial.println(F("50 − Buzz 4 – 40%"));
      return effect;
      break;

    case 51:
      Serial.println(F("51 − Buzz 5 – 20%"));
      return effect;
      break;

    case 52:
      Serial.println(F("52 − Pulsing Strong 1 – 100%"));
      return effect;
      break;

    case 53:
      Serial.println(F("53 − Pulsing Strong 2 – 60%"));
      return effect;
      break;

    case 54:
      Serial.println(F("54 − Pulsing Medium 1 – 100%"));
      return effect;
      break;

    case 55:
      Serial.println(F("55 − Pulsing Medium 2 – 60%"));
      return effect;
      break;

    case 56:
      Serial.println(F("56 − Pulsing Sharp 1 – 100%"));
      return effect;
      break;

    case 57:
      Serial.println(F("57 − Pulsing Sharp 2 – 60%"));
      return effect;
      break;

    case 58:
      Serial.println(F("58 − Transition Click 1 – 100%"));
      return effect;
      break;

    case 59:
      Serial.println(F("59 − Transition Click 2 – 80%"));
      return effect;
      break;

    case 60:
      Serial.println(F("60 − Transition Click 3 – 60%"));
      return effect;
      break;

    case 61:
      Serial.println(F("61 − Transition Click 4 – 40%"));
      return effect;
      break;

    case 62:
      Serial.println(F("62 − Transition Click 5 – 20%"));
      return effect;
      break;

    case 63:
      Serial.println(F("63 − Transition Click 6 – 10%"));
      return effect;
      break;

    case 64:
      Serial.println(F("64 − Transition Hum 1 – 100%"));
      return effect;
      break;

    case 65:
      Serial.println(F("65 − Transition Hum 2 – 80%"));
      return effect;
      break;

    case 66:
      Serial.println(F("66 − Transition Hum 3 – 60%"));
      return effect;
      break;

    case 67:
      Serial.println(F("67 − Transition Hum 4 – 40%"));
      return effect;
      break;

    case 68:
      Serial.println(F("68 − Transition Hum 5 – 20%"));
      return effect;
      break;

    case 69:
      Serial.println(F("69 − Transition Hum 6 – 10%"));
      return effect;
      break;

    case 70:
      Serial.println(F("70 − Transition Ramp Down Long Smooth 1 – 100 to 0%"));
      return effect;
      break;

    case 71:
      Serial.println(F("71 − Transition Ramp Down Long Smooth 2 – 100 to 0%"));
      return effect;
      break;

    case 72:
      Serial.println(F("72 − Transition Ramp Down Medium Smooth 1 – 100 to 0%"));
      return effect;
      break;

    case 73:
      Serial.println(F("73 − Transition Ramp Down Medium Smooth 2 – 100 to 0%"));
      return effect;
      break;

    case 74:
      Serial.println(F("74 − Transition Ramp Down Short Smooth 1 – 100 to 0%"));
      return effect;
      break;

    case 75:
      Serial.println(F("75 − Transition Ramp Down Short Smooth 2 – 100 to 0%"));
      return effect;
      break;

    case 76:
      Serial.println(F("76 − Transition Ramp Down Long Sharp 1 – 100 to 0%"));
      return effect;
      break;

    case 77:
      Serial.println(F("77 − Transition Ramp Down Long Sharp 2 – 100 to 0%"));
      return effect;
      break;

    case 78:
      Serial.println(F("78 − Transition Ramp Down Medium Sharp 1 – 100 to 0%"));
      return effect;
      break;

    case 79:
      Serial.println(F("79 − Transition Ramp Down Medium Sharp 2 – 100 to 0%"));
      return effect;
      break;

    case 80:
      Serial.println(F("80 − Transition Ramp Down Short Sharp 1 – 100 to 0%"));
      return effect;
      break;

    case 81:
      Serial.println(F("81 − Transition Ramp Down Short Sharp 2 – 100 to 0%"));
      return effect;
      break;

    case 82:
      Serial.println(F("82 − Transition Ramp Up Long Smooth 1 – 0 to 100%"));
      return effect;
      break;

    case 83:
      Serial.println(F("83 − Transition Ramp Up Long Smooth 2 – 0 to 100%"));
      return effect;
      break;

    case 84:
      Serial.println(F("84 − Transition Ramp Up Medium Smooth 1 – 0 to 100%"));
      return effect;
      break;

    case 85:
      Serial.println(F("85 − Transition Ramp Up Medium Smooth 2 – 0 to 100%"));
      return effect;
      break;

    case 86:
      Serial.println(F("86 − Transition Ramp Up Short Smooth 1 – 0 to 100%"));
      return effect;
      break;

    case 87:
      Serial.println(F("87 − Transition Ramp Up Short Smooth 2 – 0 to 100%"));
      return effect;
      break;

    case 88:
      Serial.println(F("88 − Transition Ramp Up Long Sharp 1 – 0 to 100%"));
      return effect;
      break;

    case 89:
      Serial.println(F("89 − Transition Ramp Up Long Sharp 2 – 0 to 100%"));
      return effect;
      break;

    case 90:
      Serial.println(F("90 − Transition Ramp Up Medium Sharp 1 – 0 to 100%"));
      return effect;
      break;

    case 91:
      Serial.println(F("91 − Transition Ramp Up Medium Sharp 2 – 0 to 100%"));
      return effect;
      break;

    case 92:
      Serial.println(F("92 − Transition Ramp Up Short Sharp 1 – 0 to 100%"));
      return effect;
      break;

    case 93:
      Serial.println(F("93 − Transition Ramp Up Short Sharp 2 – 0 to 100%"));
      return effect;
      break;

    case 94:
      Serial.println(F("94 − Transition Ramp Down Long Smooth 1 – 50 to 0%"));
      return effect;
      break;

    case 95:
      Serial.println(F("95 − Transition Ramp Down Long Smooth 2 – 50 to 0%"));
      return effect;
      break;

    case 96:
      Serial.println(F("96 − Transition Ramp Down Medium Smooth 1 – 50 to 0%"));
      return effect;
      break;

    case 97:
      Serial.println(F("97 − Transition Ramp Down Medium Smooth 2 – 50 to 0%"));
      return effect;
      break;

    case 98:
      Serial.println(F("98 − Transition Ramp Down Short Smooth 1 – 50 to 0%"));
      return effect;
      break;

    case 99:
      Serial.println(F("99 − Transition Ramp Down Short Smooth 2 – 50 to 0%"));
      return effect;
      break;

    case 100:
      Serial.println(F("100 − Transition Ramp Down Long Sharp 1 – 50 to 0%"));
      return effect;
      break;

    case 101:
      Serial.println(F("101 − Transition Ramp Down Long Sharp 2 – 50 to 0%"));
      return effect;
      break;

    case 102:
      Serial.println(F("102 − Transition Ramp Down Medium Sharp 1 – 50 to 0%"));
      return effect;
      break;

    case 103:
      Serial.println(F("103 − Transition Ramp Down Medium Sharp 2 – 50 to 0%"));
      return effect;
      break;

    case 104:
      Serial.println(F("104 − Transition Ramp Down Short Sharp 1 – 50 to 0%"));
      return effect;
      break;

    case 105:
      Serial.println(F("105 − Transition Ramp Down Short Sharp 2 – 50 to 0%"));
      return effect;
      break;

    case 106:
      Serial.println(F("106 − Transition Ramp Up Long Smooth 1 – 0 to 50%"));
      return effect;
      break;

    case 107:
      Serial.println(F("107 − Transition Ramp Up Long Smooth 2 – 0 to 50%"));
      return effect;
      break;

    case 108:
      Serial.println(F("108 − Transition Ramp Up Medium Smooth 1 – 0 to 50%"));
      return effect;
      break;

    case 109:
      Serial.println(F("109 − Transition Ramp Up Medium Smooth 2 – 0 to 50%"));
      return effect;
      break;

    case 110:
      Serial.println(F("110 − Transition Ramp Up Short Smooth 1 – 0 to 50%"));
      return effect;
      break;


    case 111:
      Serial.println(F("111 − Transition Ramp Up Short Smooth 2 – 0 to 50%"));
      return effect;
      break;

    case 112:
      Serial.println(F("112 − Transition Ramp Up Long Sharp 1 – 0 to 50%"));
      return effect;
      break;

    case 113:
      Serial.println(F("113 − Transition Ramp Up Long Sharp 2 – 0 to 50%"));
      return effect;
      break;

    case 114:
      Serial.println(F("114 − Transition Ramp Up Medium Sharp 1 – 0 to 50%"));
      return effect;
      break;

    case 115:
      Serial.println(F("115 − Transition Ramp Up Medium Sharp 2 – 0 to 50%"));
      return effect;
      break;

    case 116:
      Serial.println(F("116 − Transition Ramp Up Short Sharp 1 – 0 to 50%"));
      return effect;
      break;

    case 117:
      Serial.println(F("117 − Transition Ramp Up Short Sharp 2 – 0 to 50%"));
      return effect;
      break;

    case 118:
      Serial.println(F("118 − Long buzz for programmatic stopping – 100%"));
      return effect;
      break;

    case 119:
      Serial.println(F("119 − Smooth Hum 1 (No kick or brake pulse) – 50%"));
      return effect;
      break;

    case 120:
      Serial.println(F("120 − Smooth Hum 2 (No kick or brake pulse) – 40%"));
      return effect;
      break;

    case 121:
      Serial.println(F("121 − Smooth Hum 3 (No kick or brake pulse) – 30%"));
      return effect;
      break;

    case 122:
      Serial.println(F("122 − Smooth Hum 4 (No kick or brake pulse) – 20%"));
      return effect;
      break;

    case 123:
      Serial.println(F("123 − Smooth Hum 5 (No kick or brake pulse) – 10%"));
      return effect;
      break;
  }
  return 0; 
}
