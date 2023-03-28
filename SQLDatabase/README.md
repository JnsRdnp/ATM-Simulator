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
    <li>After database creation, navigate to `'Database/Synchronize Model'` or do `'Shift + Ctrl + Z'`.
    <li>Set the correct connection, which should be set by default. 
    <li>Skip options for Synchronization Script. 
    <li>Connect to database to fetch information and next select the correct Model Schema. It should be selected by default.
<ol>