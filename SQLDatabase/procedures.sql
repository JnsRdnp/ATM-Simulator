DELIMITER //
CREATE PROCEDURE fetchName(IN accountsid int)
BEGIN
SELECT  CONCAT(firstname," ",lastname) into @wholeName
FROM user
WHERE iduser =
( SELECT user_iduser
  FROM cards
  WHERE idcard = (
	SELECT card_idcard
    FROM accounts
    WHERE idaccounts = accountsid
  ));
END //
DELIMITER ;


DELIMITER //
CREATE PROCEDURE debit_withdraw(IN accountID INT,IN amount float)
BEGIN
  DECLARE test1 INT DEFAULT 0;
  START TRANSACTION;
  call fetchName(accountID);
  UPDATE accounts SET balance=balance-amount WHERE idaccounts=accountID AND balance>=amount;
  SET test1=ROW_COUNT();
    IF (test1 > 0) THEN COMMIT;
	  INSERT INTO history(accounts_idaccounts,wholeName,withdrawal,date)
	  VALUES(accountID,@wholeName,amount,NOW());
    ELSE
      ROLLBACK;
  END IF;
END //
DELIMITER ;


DELIMITER //
CREATE PROCEDURE credit_withdraw(IN accountID INT,IN amount float)
BEGIN
  DECLARE test1 INT DEFAULT 0;
  START TRANSACTION;
  call fetchName(accountID);
  UPDATE accounts SET balance=balance-amount WHERE idaccounts=accountID AND(creditLimit*-1)<=(balance-amount) AND (balance+creditLimit)>=amount;
  SET test1=ROW_COUNT();
    IF (test1 > 0) THEN COMMIT;
	  INSERT INTO history(accounts_idaccounts,wholeName,withdrawal,date)
	  VALUES(accountID,@wholeName,amount,NOW());
    ELSE
      ROLLBACK;
  END IF;
END //
DELIMITER ;


DELIMITER //
CREATE PROCEDURE get_history(IN accountID INT, IN showNumber INT, IN pageNumber INT)
BEGIN
  DECLARE pageOffset INT;
  SET pageOffset = pageNumber * 5;
  SELECT * FROM history WHERE accounts_idaccounts = accountID
  LIMIT pageOffset, showNumber;
END //
DELIMITER ;