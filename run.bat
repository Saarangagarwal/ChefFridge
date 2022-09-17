@ECHO OFF
ECHO running image detection
python createGroups.py
set GOOGLE_APPLICATION_CREDENTIALS = C:\Users\16478\Desktop\starterhacks\My First Project-b330c7d7e977.json
python getter.py
PAUSE 
