void resetPumps(){
  if(rtc.daystamp>get_ts(23,59,0)){
    pumpReset=true;
  }
  if(rtc.daystamp<1000 && pumpReset==true){
    pumpReset=false;
    for( int i=0;i <= PUMPCOUNTS; i++){
        dosingState[i]=false;
//        dosing[i].status=false;
    }
  }
}
void setDosing(){
  resetPumps();;
    for( int i=0;i <= PUMPCOUNTS; i++){
      if(dosing[i].active!=0){
        if(rtc.daystamp>=dosing[i].time && digitalRead(dosing[i].pinAddr)==LOW && dosingState[i]==false){
          t.pulse(dosing[i].pinAddr,60000 * dosing[i].mldosing / dosing[i].mlperminute, LOW);
          dosingState[i]=true;
          writeLCD(i,dosing[i].mldosing);
        }
      }
    }
}

void writeLCD(int pos, int val){
          int EEPval;
          EEPROM_readAnything(100+(pos*2),EEPval);  
          EEPval=EEPval-val; 
          EEPROM_writeAnything(100+(pos*2), EEPval);
          lcd.setCursor(0+(pos*3),1); 
//      Serial.println(val);
          EEPval=EEPval*100/dose_val;
          lcd.print(EEPval);
          if(EEPval<100)lcd.print(F(" "));
  
}
