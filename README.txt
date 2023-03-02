CIS 3210 Computer Networks A3
Olivia Biancucci
1136788

OVERVIEW:
This application runs a receiver and sender that can send and receive text messages from a
text file over an unconnected UDP. The sender will take in a text file and send the text
data to the receiver which will output the data.

INSTALLION/HOW TO USE:
After downloading the zip file "obiancucA3" right click on the file and extract
all contents. In your Linux terminal, navigate the working directory to the folder.
Type the command "make" to compile all of the code. Each program can be ran in two
separate terminals both in the folders' directory. The two programs that can be ran
simultaneously are:

1) ./sender will run the sender code, it arguments include the receivers IP address,
and a file name. This is in the format ./sender receiver-IP-address filename

2) ./receiver will run the receiver code. It does not take any arguments.

Both the sender and the receiver must be ran with the correct number of arguments
and in the correct format.

All the functionality works and can be demonstrated by running the above commands with
a text file. The receiver will continue to run until user terminated with "CTRL + C"