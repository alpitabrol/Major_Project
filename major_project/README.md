
# Things needed to be there before building the project:

1. Eclipse IDE should be there installed in the linux system.
2. Raspberry Pi should be connected to the machine, should be able to send files either through cross-tool chain or through FTP
3. Keypad matrix should be connected properly to the Raspberry Pi.
4. Nginx software should be properly installed and should be in the working condtion.
5. Both raspberry pi and system should be connected to the same network.


# Steps for running code in your machine

1. Clone the repository in your machine.
2. Open all three projects(server_conn, keypad_interface and page_one_html) above mentioned in eclipse.
3. Firstly build the keypad_interface project, and transfer the object file of the project to raspberry pi folder from where you want to      call the program for interfacing keypad.
4. Secondly, build the other two projects: server_conn and page_one_html one by one and transfer the object files for both of them to        nginx folder of your machine i.e.: /usr/lib/cgi-bin/
5. Open you browser and run the link: localhost/cgi-bin/page_one_html/ "NOTE: The file names for the object files made should be same as      it is there in the repsitory."
6. Click on start shopping after entering your name. Then it will wait for the response from the keypad.
7. For giving the input run the object file trasnfered to raspberry pi and start entering the PLU codes, once you are done with the          shopping 	list, the final page will be automatically displayed on your machine browser.

For Refrence: Use Derek Molloy Book Chapter 12:
https://raks.ee/books/pdf/exploringraspberrypi.pdf

