DELIMITER //
CREATE PROCEDURE fetchName(IN accountsid int)
BEGIN
SELECT CONCAT(firstname," ",lastname) as wholeName
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

