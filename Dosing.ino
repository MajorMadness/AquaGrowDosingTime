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
          int val;
          EEPROM_readAnything(100+(i*2),val);  
          val=val-dosing[i].mldosing; 
          EEPROM_writeAnything(100+(i*2), val);
          lcd.setCursor(0+(i*3),1); 
//      Serial.println(val);
          val=val*100/dose_val;
          lcd.print(val);
          if(val<100)lcd.print(F(" "));
        }
      }
    }
}