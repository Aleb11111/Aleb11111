use dbForA5;

CREATE TABLE Artists (
    artist_id INT PRIMARY KEY,
    artist_name VARCHAR(255) UNIQUE,
    age INT
);

CREATE TABLE Albums (
    album_id INT PRIMARY KEY,
    album_name VARCHAR(255),
    release_date DATE
);


CREATE TABLE Tracks (
    track_id INT PRIMARY KEY,
    track_name VARCHAR(255),
    artist_id INT FOREIGN KEY REFERENCES Artists(artist_id),
    album_id INT FOREIGN KEY REFERENCES Albums(album_id)
);

GO
CREATE OR ALTER PROCEDURE insertRandomArtists
    @rows INT
AS
BEGIN
    DECLARE @counter INT = 1

    WHILE @counter <= @rows
    BEGIN
        DECLARE @artist_name NVARCHAR(255) = 'Artist' + CAST(ABS(CHECKSUM(NEWID())) % 10000 AS NVARCHAR(10))
        
        -- Insert the random artist into the Artists table
        INSERT INTO Artists (artist_id, artist_name, age)
        VALUES (@counter, @artist_name, CAST(ROUND(RAND() * 40 + 20, 0) AS INT))  -- Assuming age is between 20 and 60

        SET @counter = @counter + 1
    END
END

exec insertRandomArtists 100000

DELETE FROM Artists
Select * From Artists
Select count(*) From Artists


GO
CREATE OR ALTER PROCEDURE insertRandomAlbums
    @rows INT
AS
BEGIN
    DECLARE @counter INT = 1

    WHILE @counter <= @rows
    BEGIN
        DECLARE @album_name NVARCHAR(255) = 'Album' + CAST(ABS(CHECKSUM(NEWID())) % 10000 AS NVARCHAR(10))
        DECLARE @release_date DATE = DATEADD(DAY, ROUND(RAND() * 365 * 10, 0), '2010-01-01')  -- Assuming albums from 2010 to 2020

        -- Insert the random album into the Albums table
        INSERT INTO Albums (album_id, album_name, release_date)
        VALUES (@counter, @album_name, @release_date)

        SET @counter = @counter + 1
    END
END

exec insertRandomAlbums 10000

Select * From Albums
Select count(*) From Albums

GO

CREATE OR ALTER PROCEDURE insertRandomTracks
    @rows INT
AS
BEGIN
    DECLARE @counter INT = 1

    WHILE @counter <= @rows
    BEGIN
        DECLARE @track_name NVARCHAR(255) = 'Track' + CAST(ABS(CHECKSUM(NEWID())) % 10000 AS NVARCHAR(10))
        DECLARE @artist_id INT = (ABS(CHECKSUM(NEWID())) % 10000) % 10000 + 1  -- Assuming 10,000 artists
        DECLARE @album_id INT = (ABS(CHECKSUM(NEWID())) % 10000) % 10000 + 1  -- Assuming 10,000 albums

        -- Insert the random track into the Tracks table
        INSERT INTO Tracks (track_id, track_name, artist_id, album_id)
        VALUES (@counter, @track_name, @artist_id, @album_id)

        SET @counter = @counter + 1
    END
END

exec insertRandomTracks 10000
Select * From Tracks
Select count(*) From Tracks

-- Clustered Index Scan
SELECT * FROM Artists;

-- Clustered Index Seek
SELECT * FROM Artists WHERE artist_id < 199;

-- Nonclustered Index Scan
SELECT artist_name FROM Artists;

-- Nonclustered Index Seek
SELECT artist_name FROM Artists WHERE artist_name = 'Artist343';

-- Key Lookup (RID Lookup or Bookmark Lookup)
SELECT artist_name,age FROM Artists WHERE artist_name = 'Artist3474';


--b. Write a query on table Tb with a WHERE clause of the form WHERE b2 = value and analyze its execution plan. 
--		Create a nonclustered index that can speed up the query. Examine the execution plan again.

SELECT *
FROM Albums
WHERE album_name = 'Album2373'

--
DROP INDEX INDEX_album_name ON Albums
CREATE NONCLUSTERED INDEX INDEX_album_name ON Albums(album_name);


-- Create a view that joins at least 2 tables. Check whether existing indexes are helpful; 
--		if not, reassess existing indexes / examine the cardinality of the tables.

GO
CREATE OR ALTER VIEW View1 AS
	SELECT A.artist_id, B.album_id, C.track_id
	FROM Tracks C
	INNER JOIN Artists A ON A.artist_id = C.artist_id
	INNER JOIN Albums B ON B.album_id = C.album_id
	WHERE B.album_id > 500 AND A.artist_id < 150

GO
SELECT *
FROM View1

DROP INDEX Artists_Age_index ON Artists
CREATE NONCLUSTERED INDEX Artists_Age_index ON Artists(age)

DROP INDEX Tracks_index ON Tracks
CREATE NONCLUSTERED INDEX Tracks_index ON Tracks(artist_id, album_id)