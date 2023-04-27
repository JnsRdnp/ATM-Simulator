Bank Simulator

A first-year project for Oulu University of Applied Sciences' ["Software Developement Application Project" -course](https://www.oamk.fi/opinto-opas/en/content-of-studies/curricula?koulutus=tvt2023k-ohj&lk=k2023&alasivu=opintojakso&kieli=en&oj=IN00CS90_en). By [Santtu Niskanen](https://github.com/santtuniskanen), [Saku Roininen](https://github.com/SakRoi), [Joonas Ridanpää](https://github.com/JnsRdnp), and [Lauri Tuovinen](https://github.com/LauriTuovinen).

## Description

Bank Simulator is software made to simulate a real-life bank ATM. This project includes a frontend written in C++ and QT, a backend written in JavaScript (using express framework), and a MySQL database. 
This project was built on the plan to make a fully working imitation, with the additional prerequisites being automated signing out and having the whole backend in the cloud.
Bank Simulator also has some basic security features such as JSON Web Token for authentication and encrypting cards' PINs, it is however not made nor safe for actual production.

## Getting Started

### Prerequisites

- [**QT**](https://www.qt.io/download-open-source)
    - QT Serial Port reader
    - QT network
    - QT Widgets
- [**Node.js**](https://nodejs.org/en)
- [**Express**](https://expressjs.com/)
- [**Certbot**](https://certbot.eff.org/)
- A JavaScript package manager of your choice. (We used [npm](https://www.npmjs.com/), but something like Yarn should also work)
- [MySQL server](https://dev.mysql.com/downloads/) (you can also use MySQL workbench for this if you so wish.)
- A way to make POST HTTP requests (such as [Postman](https://www.postman.com/))
- RFID reader which can communicate with your computer using a serial port.

### Installation

1. Git Clone the repo to your local machine.
2. Install Certbot on your local machine or server. This is to make the backend's HTTPS work.
3. Install other Prerequisites.
4. Using either the model file or the dump file, build up the database.
5. Create a new MySQL user:
    `USE database;`
    `CREATE USER 'username'@'host' identified with mysql_native_password by 'password';`
    `GRANT ALL on database.* to 'username'@'host';`
6. Run and save the procedures found in procedures.sql in the MySQL database
7. In /backend, use your package manager to install the dependencies for it.
    for example, if you use NPM, you would run `npm install` in bankSimul/backend
8. Comment out the line 30 in app.js. (We need to do this to add cards into the database with encrypted PINs)
9. create a .env file in /backend and include the following data
    * SQL_SERVER = 'mysql://username:password@host:3306/database'
    * port = the port you want the backend to listen to
    * MY_TOKEN = a base 64 random string
10. Save and then run app.js using node: `node app.js`
11. In CardReaderDLL, change the settings in the openSerialPort method to be the same as your RFID reader.
12. In Login, in environment.cpp, change the localhost to match your version.
13. Build all projects from the /frontend file using QT.
14. Run Login.
    if this causes problems, see https://github.com/banksimul-2023-22spo/group_15/tree/main/frontend for FAQ.
15. Read one of your RFID cards and save the ID somewhere
16. Insert into the MySQL database a new user
17. Using that RFID card's ID, make a POST request to https:/host:port/cards with the following info in its body:
    * id : RFID-card's ID
    * PINcode : 4 numbers
    * idUser : the primary key of the inserted user
    * credit : 1 if the card is supposed to be a credit card, 0 if it's not
    * debit : 1 if the card is supposed to be a debit card, 0 if it's not
18. Insert an account into the MySQL database with the card's id and owner.
19. Your card is now able to be used to login into the bank simulator. Uncomment the line 30 in app.js and restart the server.
Congrats, the program should now be able to work without many changes to the backend itself. You can add new cards by doing the same thing but without the need of creating the whole system again. You can also add multiple accounts to one card if you so wish to.

#### 

## Usage
Usage of the Bank Simulator is simple. You can log in into the bank simulator by giving it a card using an RFID reader and giving it's PIN. If the card is both credit and debit, it will ask the user to choose one of them. If the card has multiple accounts attached to it, it will ask the user which it wants to use.

In the "main menu", the user can choose to see their balance (saldo), withdraw money (nosto), see history (tili), or sign out (kirjaudu ulos). The main menu also asks the user automatically after 20 seconds of not interfacing with the program, if they want to continue their session. This also automatically sign outs the user after 10 seconds of not choosing.

## [A short video to show the usage.](https://youtu.be/piatJRwadu4)

## Known Issues

* The addition of new info is unsafe and should be probably done via a different software made for it.

* The software's installation is cumbersome and would be helped by an installer for the QT fronted.

## License


## Acknowledgements

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


