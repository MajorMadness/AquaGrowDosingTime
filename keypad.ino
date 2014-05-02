// Taking care of some special events.
void keypadEvent(KeypadEvent key){
  int chanel;
  boolean s_Light=false;
    switch (keypad.getState()){
    case PRESSED:
        if (key == '1') {
          if(digitalRead(relayPIN[0])==true){
            digitalWrite(relayPIN[0],false);
          }else{
            digitalWrite(relayPIN[0],true);
          }
          manualRelay=true;
        }else if (key == '2') {
          if(digitalRead(relayPIN[1])==true){
            digitalWrite(relayPIN[1],false);
          }else{
            digitalWrite(relayPIN[1],true);
          }
          manualRelay=true;
        }else if (key == '3') {
          if(digitalRead(relayPIN[2])==true){
            digitalWrite(relayPIN[2],false);
          }else{
            digitalWrite(relayPIN[2],true);
          }
          manualRelay=true;
        }else if (key == '4') {
          if(digitalRead(relayPIN[3])==true){
            digitalWrite(relayPIN[3],false);
          }else{
            digitalWrite(relayPIN[3],true);
          }
          manualRelay=true;
        }else if (key == '5') {
        }else if (key == '6') {
        }else if (key == '7') {
        }else if (key == '8') {
        }else if (key == '9') {
          manualRelay=false;
        }else if (key == 'A') {
          t.pulse(dosing[0].pinAddr,60000 / dosing[0].mlperminute, LOW);
          writeLCD(0,1);
        }else if (key == 'B') {
          t.pulse(dosing[1].pinAddr,60000 / dosing[1].mlperminute, LOW);
          writeLCD(1,1);
        }else if (key == 'C') {
          t.pulse(dosing[2].pinAddr,60000 / dosing[2].mlperminute, LOW);
          writeLCD(2,1);
        }else if (key == 'D') {
          t.pulse(dosing[3].pinAddr,60000 / dosing[3].mlperminute, LOW);
          writeLCD(3,1);
        }else if (key == '*') {
          t.pulse(dosing[4].pinAddr,60000 / dosing[3].mlperminute, LOW);
          writeLCD(4,1);
        }else if (key == '#') {
          t.pulse(dosing[5].pinAddr,60000 / dosing[3].mlperminute, LOW);
          writeLCD(5,1);
        } 
        break;
        
        
    case HOLD:
      if (key == 'A') {
          EEPROM_writeAnything(100, dose_val);
        }else if (key == 'B') {
          EEPROM_writeAnything(102, dose_val);
        }else if (key == 'C') {
          EEPROM_writeAnything(104, dose_val);
        }else if (key == 'D') {
          EEPROM_writeAnything(106, dose_val);
        }else if (key == '*') {
          EEPROM_writeAnything(108, dose_val);
        }else if (key == '#') {
          EEPROM_writeAnything(110, dose_val);
        }
        break;
    } 
}

void switch_holdKey(char* key){
  if(strcmp(key,"A")==0 || strcmp(key,"B")==0 || strcmp(key,"C")==0 || strcmp(key,"D")==0 || strcmp(key,"#")==0 || strcmp(key,"*")==0)return;
  
}
