use Tests;
/*
CREATE TABLE Animals(AnimalID INT NOT NULL,CONSTRAINT PK_Animals PRIMARY KEY(AnimalID));

CREATE TABLE Keeper(KeeperID INT NOT NULL,CONSTRAINT PK_Keeper PRIMARY KEY(KeeperID),Anmimal_id INT REFERENCES Animals(AnimalID));

CREATE TABLE Enclosure(
	EAnimalID INT NOT NULL,
	EKeeperID INT NOT NULL,
	CONSTRAINT PK_Transactions PRIMARY KEY (EAnimalID, EKeeperID)
);*/

GO

create or alter view AnimalsView
AS 
	Select *
	From Animals
GO

CREATE OR ALTER VIEW KeeperView 
AS 
	SELECT Keeper.KeeperID
	FROM Keeper INNER JOIN Enclosure ON Keeper.KeeperID = Enclosure.EKeeperID
GO

/*
CREATE TABLE Aux(
	id INT NOT NULL, 
	CONSTRAINT PK_Aux PRIMARY KEY (id)
);

INSERT INTO Aux VALUES (1),(2),(3);
GO*/

CREATE OR ALTER VIEW EnclosureView
AS 
	SELECT Enclosure.EAnimalID
	FROM Enclosure INNER JOIN Aux ON Aux.id = Enclosure.EAnimalID
	GROUP BY EAnimalID
	
GO

DELETE FROM Tables
INSERT INTO Tables VALUES('Animals'),('Keeper'),('Enclosure')


DELETE FROM Views 
INSERT INTO Views VALUES ('AnimalsView'),('KeeperView'),('EnclosureView')

DELETE FROM Tests 
INSERT INTO Tests VALUES('selectView'),('insertAnimals'),('deleteAnimals'),('insertKeeper'),('deleteKeeper'),('insertEnclosure'),('deleteEnclosure') 

SELECT * FROM Tests
SELECT * FROM Tables 
SELECT * FROM Views

DELETE FROM TestViews
INSERT INTO TestViews VALUES (36,19)
INSERT INTO TestViews VALUES (36,20)
INSERT INTO TestViews VALUES (36,21)
SELECT * FROM TestViews


--(testId, tableId, NoOfRows, Position) 
-- position denotes the order in which they will be executed
--				no of rows= how many to be inserted

DELETE FROM TestTables 
INSERT INTO TestTables VALUES (36, 19, 100, 1)
INSERT INTO TestTables VALUES (39, 20, 100, 2)
INSERT INTO TestTables VALUES (40, 21, 100, 3)
SELECT * FROM TestTables



GO
CREATE OR ALTER PROC insertAnimals 
AS 
	DECLARE @crt INT = 1
	DECLARE @rows INT
	SELECT @rows = NoOfRows FROM TestTables WHERE TestId = 36
	--PRINT (@rows)
	WHILE @crt <= @rows 
	BEGIN 
		INSERT INTO Animals VALUES (@crt + 1)
		SET @crt = @crt + 1 
	END 

GO 

CREATE OR ALTER PROC deleteAnimals 
AS 
	DELETE FROM Animals WHERE AnimalID>1;

GO 



CREATE OR ALTER PROC insertKeeper
AS 
	DECLARE @crt INT = 1
	DECLARE @rows INT
	SELECT @rows = NoOfRows FROM TestTables WHERE TableID = 39
	WHILE @crt <= @rows 
	BEGIN 
		INSERT INTO Keeper VALUES (@crt,1)
		SET @crt = @crt + 1 
	END 

GO 

CREATE OR ALTER PROC deleteKeeper 
AS 
	DELETE FROM Keeper;

GO



CREATE OR ALTER PROC insertEnclosure
AS 
	DECLARE @crt INT = 1
	DECLARE @rows INT
	SELECT @rows = NoOfRows FROM TestTables WHERE TestId = 40
	WHILE @crt <= @rows 
	BEGIN 
		INSERT INTO Enclosure VALUES (@crt,@crt)
		SET @crt = @crt + 1 
	END 

GO 

CREATE OR ALTER PROC deleteEnclosure 
AS 
	DELETE FROM Enclosure;

SELECT * FROM Views

GO
CREATE OR ALTER PROC TestRunViewsProc
AS 
	DECLARE @start1 DATETIME;
	DECLARE @start2 DATETIME;
	DECLARE @start3 DATETIME;
	DECLARE @end1 DATETIME;
	DECLARE @end2 DATETIME;
	DECLARE @end3 DATETIME;
	
	SET @start1 = GETDATE();
	PRINT ('executing select * from Animals')
	EXEC ('SELECT * FROM AnimalsView');
	SET @end1 = GETDATE();
	INSERT INTO TestRuns VALUES ('test_view', @start1, @end1)
    INSERT INTO TestRunViews VALUES (@@IDENTITY, 19, @start1, @end1);

	SET @start2 = GETDATE();
	PRINT ('executing select * from Keeper')
	EXEC ('SELECT * FROM KeeperView');
	SET @end2 = GETDATE();
	INSERT INTO TestRuns VALUES ('test_view2', @start2, @end2)
    INSERT INTO TestRunViews VALUES (@@IDENTITY, 20, @start2, @end2);


	SET @start3 = GETDATE();
	PRINT ('executing select * from Enclosures')
	EXEC ('SELECT * FROM EnclosureView');
	SET @end3 = GETDATE();
	INSERT INTO TestRuns VALUES ('test_view3', @start3, @end3)
    INSERT INTO TestRunViews VALUES (@@IDENTITY, 21, @start3, @end3);

GO


CREATE OR ALTER PROC TestRunTablesProc
AS 
	DECLARE @start1 DATETIME;
	DECLARE @start2 DATETIME;
	DECLARE @start3 DATETIME;
	DECLARE @start4 DATETIME;
	DECLARE @start5 DATETIME;
	DECLARE @start6 DATETIME;
	DECLARE @end1 DATETIME;
	DECLARE @end2 DATETIME;
	DECLARE @end3 DATETIME;
	DECLARE @end4 DATETIME;
	DECLARE @end5 DATETIME;
	DECLARE @end6 DATETIME;


	SET @start2 = GETDATE();
	PRINT('deleting data from Animals')
	EXEC deleteAnimals;
	SET @end2 = GETDATE();
	INSERT INTO TestRuns VALUES ('test_delete_Animals',@start2, @end2);
	INSERT INTO TestRunTables VALUES (@@IDENTITY, 19, @start2, @end2);

	SET @start1 = GETDATE();
	PRINT('inserting data into Animals')
	EXEC insertAnimals;
	SET @end1 = GETDATE();
	INSERT INTO TestRuns VALUES ('test_insert_Animals',@start1, @end1);
	INSERT INTO TestRunTables VALUES (@@IDENTITY, 19, @start1, @end1);

	SET @start4 = GETDATE();
	PRINT('deleting data from Keeper')
	EXEC deleteKeeper;
	SET @end4 = GETDATE();
	INSERT INTO TestRuns VALUES ('test_delete_Keeper',@start4, @end4);
	INSERT INTO TestRunTables VALUES (@@IDENTITY, 20, @start4, @end4);

	SET @start3 = GETDATE();
	PRINT('inserting data into Keeper')
	EXEC insertKeeper;
	SET @end3 = GETDATE();
	INSERT INTO TestRuns VALUES ('test_insert_Keeper',@start3, @end3);
	INSERT INTO TestRunTables VALUES (@@IDENTITY, 20, @start3, @end3);

	SET @start6 = GETDATE();
	PRINT('deleting data from Enclosure')
	EXEC deleteEnclosure;
	SET @end6 = GETDATE();
	INSERT INTO TestRuns VALUES ('test_delete_Enclosure',@start6, @end6);
	INSERT INTO TestRunTables VALUES (@@IDENTITY, 21, @start6, @end6);

	SET @start5 = GETDATE();
	PRINT('inserting data into Enclosure')
	EXEC insertEnclosure;
	SET @end5 = GETDATE();
	INSERT INTO TestRuns VALUES ('test_insert_Enclosure',@start5, @end5);
	INSERT INTO TestRunTables VALUES (@@IDENTITY, 21, @start5, @end5);

GO 

select * from TestRuns;

EXEC TestRunTablesProc;
EXEC TestRunViewsProc;