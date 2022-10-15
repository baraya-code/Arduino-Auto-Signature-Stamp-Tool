void readProximity() {
  readProxi = !digitalRead(proximity);
  Serial.println(readProxi);
}
