# Kinder_Bueno
To improve my network knowledge in C i decided to create my own server to use it on my future project.

The project using socket librabry in C.

You can see how to launch to server and then the client just bellow with terminal command.

## Server

  Build the server binary with :
  ``` make ```

  Get the ip to launch the client :
  ``` chmod +x ./script/getIP.sh && ./script/getIP.sh ```

  Move to the directory :
  ``` cd server/ ```

  Run the binary :
  ``` ./server ```

## Client

  Build the client binary with :
  ``` make ```
  
  Move to the directory :
  ```cd client/```

  Run the binary :
  ``` ./client {IP}```
  
  Then you get a confirmation message for the connexion.
  Now you can type : 
  - ```SIGN-IN``` to register to the server, then you enter Username and Password.
  - ```LOGIN``` to login into the server you to already hace create the account.
  - ```SEND``` to type a message to someone you have to type the username and then the message.
