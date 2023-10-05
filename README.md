# Send SMS Using Twilio SMS API

### Steps to RUN :

Replace <b>SID, AUTH_TOKEN, TWILIO_PHONE_NUMBER, and SMS_RECEPIENT_NUMBER</b>.

<b>SID</b> and <b>TWILIO_PHONE_NUMBER</b> -> You will get it from Twilio API.

<b>SMS_RECEPIENT_NUMBER</b> -> This is the number to which you want to send the message.

### Clone or Download the repository :

Go to the root directory.

### Create a Build Directory Generate CMakeFiles :
```
cmake -S . -B build
```
### Change directory

```
cd build
```

### Compile and Install the project
```
sudo make install
```
# Another Way to RUN

Copy the contents of "build.sh" file.

Save as build.sh.

### Make it executable
```
chmod +x build.sh
```
### RUN :
./build.sh
