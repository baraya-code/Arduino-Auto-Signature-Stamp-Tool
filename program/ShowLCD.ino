void ShowLCD() {
  lcd.setCursor(0, 0);
  lcd.print("Total Cap : ");
  lcd.setCursor(0, 1);
  lcd.print(ttd);
  lcd.setCursor(12, 1);
  lcd.print("Kali");
}
