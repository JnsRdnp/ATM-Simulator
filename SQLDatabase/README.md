# Opening models and creating a database
&nbsp;
## Opening model
After downloading the .mwb file, open MySQL Workbench.
Navigate to `'File/Open Model'` or do `'Ctrl + O'`
In file explorer, select the correct file.
&nbsp;
## Synchronizing model
Create database 
``` mysql
CREATE DATABASE mydb;
USE mydb;
```
<ol>
    <li>After database creation, select the EER Diagram tab and navigate to `'Database/Synchronize Model'` or do 'Shift + Ctrl + Z'.</li>
    <li>Set the correct connection, which should be set by default.</li> 
    <li>Skip options for Synchronization Script.</li> 
    <li>Connect to database to fetch information and next select the correct Model Schema. It should be selected by default.</li>
<ol>
    
ALTERNATIVELY:
<img width="524" alt="image" src="https://user-images.githubusercontent.com/112471004/228183558-e5af2b47-4607-4867-8efb-359c39af66f3.png">

https://stackoverflow.com/questions/13693665/cannot-alter-schema-name-in-mysql-5-5-w-mysql-workbench
    
