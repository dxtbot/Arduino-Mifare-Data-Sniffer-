# Arduino-Mifare-Data-Sniffer-
![rfid](https://user-images.githubusercontent.com/20719445/109416695-1d77bc00-79c0-11eb-8019-07a8cae3a3ba.jpg)
![arduino-nano-v30-ft232-met-usb-kabel](https://user-images.githubusercontent.com/20719445/109416696-1e105280-79c0-11eb-93aa-531989fefaed.jpg)
![61FlaWpfVYL _SL1001_](https://user-images.githubusercontent.com/20719445/109417047-32554f00-79c2-11eb-9650-8994df2bc01a.jpg)
You wil need a Arduino Oled 128x64 and the RC522 RFID module .

Arduino Rfid Data steeler .

![IMG20210228122845](https://user-images.githubusercontent.com/20719445/109416925-86abff00-79c1-11eb-990b-1c617c6f8c34.jpg)
![IMG20210110102324](https://user-images.githubusercontent.com/20719445/109416922-84e23b80-79c1-11eb-9c0f-70a7f1895a23.jpg)
![IMG20210228122825](https://user-images.githubusercontent.com/20719445/109416950-b22ee980-79c1-11eb-8f20-755c7b72fad4.jpg)

i used this to debug the Dutch Ov Chipcard .(transportation card ) .
or just to have fun !
it wil read and store UID and first 5 block's of a Mifare card .
it wil store it in the Arduino Eeprom mem ,
i use a second sketch to read out the Eeprom memory and wil give a serial print from the collected data .
you could use this as a example how to read out certain RFID cards and how to store some data to manipulate .


