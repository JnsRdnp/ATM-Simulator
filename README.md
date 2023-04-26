# group_15

![image](https://user-images.githubusercontent.com/78476744/233318810-29c73b87-1d22-4804-b861-3252c321e309.png)

Congrats, the program should now be able to work without much changes to the backend itself. You can add new cards by doing the same thing, but without the need of creating the whole system again. You can also add multiple accounts to one card if you so wish to.

#### 

## Usage
Usage of the Bank Simulator is simple. You can login into the bank simulator by giving it a card using RFID-reader and giving it's PIN. If the card is both credit and debit, it will ask the user to choose one of them. If the card has multiple accounts attatched to it, it will ask the user which it wants to use.

In the "main menu", the user can choose to see their balance (saldo), withdraw money (nosto), see history (tili) or sign out (kirjaudu ulos). The main menu also asks the user automatically after 20 seconds of not interfacing with the program, if they want to continue their session. This also automatically sign outs the user after 10 seconds of not choosing.

## Known Issues

* The addition of new info is unsafe and should be probably done via a different software made for it.
* The software's installation is cumbersome, would be helped by an installer for the QT fronted.


## License

## Acknowledgements

List any contributors or resources that you used in the development of your project, including any libraries or frameworks.


Working with MySQL database and creating procedures
- https://peatutor.com/databases/

Connecting QT to the backend
- https://peatutor.com/qt

API and JavaScript
- https://peatutor.com/express/

General QT problems
- https://forum.qt.io/
- https://doc.qt.io/
- https://www.qtcentre.org/


