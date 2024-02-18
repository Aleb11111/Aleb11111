use zoo

--Insert for at least 4 tables

--Insert into Animals 
--Values(9,'tiger','Stripes',7,'female',3,'2021.07.02'),
--(10,'tiger','Raj',5,'male',3,'2022.04.10'),
--(11,'tiger','Luna',3,'female',3,'2022.12.20'),
--(12,'tiger','Kavi',9,'male',3,'2021.10.05');

--INSERT INTO Animals
--Values(13,'giraffe','Gideon',3,'male',4,'2023.01.05'),
--(14,'giraffe','Gerald',7,'male',4,'2022.08.15'),
--(15,'giraffe','Giselle',5,'female',4,'2022.10.20');

--INSERT INTO Animals
--Values(16,'flamingo','Flora',4,'female',6,'2022.12.10'),
--(17,'flamingo','Floyd',5,'male',6,'2022.11.28'),
--(18,'flamingo','Fleur',3,'female',6,'2023.01.20'),
--(27,'flamingo','Felix',2,'male',6,'2023.03.05'),
--(25,'flamingo','Fiona',6,'female',6,'2022.10.15'),
--(26,'flamingo','Franklin',4,'male',6,'2023.02.10');

--INSERT INTO Animals
--Values(28,'dolphin','Dolly',9,'female',7,'2021.06.25'),
--(29,'dolphin','Danny',7,'male',7,'2022.03.12'),
--(30,'dolphin','Daisy',5,'female',7,'2022.09.08');

--INSERT INTO FeedingSchedule
--VALUES(2,5,3,'10:30',5,'Daily'),(3,7,6,'12:00',6,'Daily'),
--(4,13,7,'14:00',9,'Daily'),(5,17,13,'07:00',2,'Weekly'),
--(6,29,2,'12:00',4,'Daily'),(7,25,5,'07:00',3,'Weekly');

--INSERT INTO Veterinarians
--Values(1,'Micheal','Davis','male',0758298375,'Exotic Animal Care'),
--(2,'Emily','Rodriguez','female',0798427364,'Zoo Medicine'),
--(3,'James','Smith','male',0793745964,'Avian medicine'),
--(4,'Sarah','Johnson','female',0751218375,'Wildlife Medicine'),
--(5,'Jennifer','Lee','female',0709708375,'Aquatic Animal Health'),
--(6,'Robert','Clark','male',0798090654,'Reptile and Amphibian Care');

--Insert INTO MedicalRecords
--Values(1,1,1,'Respiratory infection',' Antibiotics prescribed for 10 days','Yes','2022.06.15'),
--(2,17,3,'Broken wing','Splint applied, pain medication given','Yes','2023.01.05'),
--(3,5,2,' Digestive issues','Special diet recommended for a week','No','2022.08.20'),
--(4,14,4,' Fractured leg','Cast applied, restricted movement advised','Yes','2022.11.30');

--Insert Into MedicalRecords
--Values(5,28,5,'Skin rash',' Topical cream applied twice daily','Yes','2023.03.10');

-- 2 commands using ORDER BY

--selects the first name, last name and experience years of female veterinarians
-- orders the results by experience years in descending 

SELECT FirstName, LastName, ExperienceYears
FROM Veterinarians
WHERE Gender = 'Female'
ORDER BY ExperienceYears DESC;

--retrieves the animal ID, name, and age of animals from the Animals table where the age is greater than 5
--orders the results first by age in ascending order, and then by name in ascending order for animals with the same age

SELECT AnimalID, Name, Age
FROM Animals
WHERE Age > 5
ORDER BY Age ASC, Name ASC;

--2 queries with top

--retrieves the top 5 veterinarians with the highest experience years
--orders the results by experience years in descending order

SELECT TOP 5 FirstName, LastName, ExperienceYears
FROM Veterinarians
ORDER BY ExperienceYears DESC;

--retrieves the top 3 tigers with the highest age
--orders the results by age in descending order

SELECT TOP 3 AnimalID, Name, Age
FROM Animals
WHERE Species = 'Tiger'
ORDER BY Age DESC;


-- 2 queries using distinct
--retrieves all distinct species from the Animals table
SELECT DISTINCT Species
FROM Animals;

--all distinct combinations of first names and last names from the Keepers table
SELECT DISTINCT FirstName, LastName
FROM Keepers;

-- 3 queries that contain arithmetic expressions in the where clause
--include only the id of the animals that twice their age is greater than 10
SELECT AnimalID, Name, Age
FROM Animals
WHERE Age * 2 > 10;

--include only the id of the animals that half of their age is greater or equal to 3
SELECT AnimalID, Name, Age
FROM Animals
WHERE Age / 2 >= 3;

-- include only the veterinarians where subtracting 2 from their experience years results in at least 5 years of experience
SELECT VetID, FirstName, LastName, ExperienceYears
FROM Veterinarians
WHERE ExperienceYears - 2 >= 5;


-- Update for at least 3


--sets the feeding portion to 4 for all records where the frequency is 'Weekly' 
--				or the animal ID is in the range of 25 to 27.

UPDATE FeedingSchedule
SET FeedingPortion = 4
Where Frequency = 'Weekly' OR AnimalID Between 25 AND 27;



-- sets the age to 8 for animals whose name starts with 'Z', 
--							followed by any character, and ends with 'e'.

UPDATE Animals 
SET Age = 8 
WHERE Name Like 'Z_e';


-- sets the experience years to 10 for the veterinarian named Robert.

update Veterinarians
set ExperienceYears = 10
where FirstName = 'Robert'



--promotes keepers with the qualification level 'level 2' to 'level 3' 
--				if their first name is either Olivia, Ava, Samuel, or Lucas.

UPDATE Keepers
SET CalificationLevel = 'level 3'
Where CalificationLevel = 'level 2' and FirstName in ('Olivia','Ava','Samuel','Lucas');


--Delete for at least 2


-- removes records from the FeedingSchedule table 
--				where the feeding portion is less than or equal to 2.

DELETE FROM FeedingSchedule
where FeedingPortion <=2;


--remove records from the Animals table where the age is greater than 9.

Delete from Animals
Where Age >9;


--2 queries with the union operation; use UNION [ALL] and OR;


-- retrieves names of animals with their entity type labeled as 'Animal' 
--				for those with an AnimalID greater than 9. 
--	It then combines this with the first names of female keepers, labeled as 'Keeper'

Select Animals.Name as AnimalName, 'Animal' as EntityType
From Animals
Where Animals.AnimalID > 9
Union
Select Keepers.FirstName as KeeperName, 'Keeper' as EntityType
From Keepers
where Keepers.Gender = 'female';


-- retrieves the first names of keepers with their job title as 'Keeper' 
--						and qualification levels of either 'level 2' or 'level 3'. 
--	It then combines this with the first names of veterinarians, 
--				labeled as 'Vet', whose specialization involves caring.

Select Keepers.FirstName as Employee, 'Keeper' as Job
from Keepers
where Keepers.CalificationLevel IN ('level 2','level 3')
UNION
Select Veterinarians.FirstName as Employee, 'Vet' as Job
from Veterinarians
where Veterinarians.Specialization LIKE '%care';



-- retrieves the first names of male keepers and keepers whose feeding portion 
--			is greater than or equal to 5 and It labels them as 'Keeper'
--		then combines this with the first names of veterinarians with more than 
--			5 years of experience, labeled as 'Veterinarian'


SELECT Keepers.FirstName, 'Keeper' AS EntityType
FROM Keepers
WHERE gender = 'male'
OR KeeperID IN (SELECT KeeperID FROM FeedingSchedule WHERE FeedingPortion >= 5)
UNION ALL
SELECT Veterinarians.FirstName, 'Veterinarian' AS EntityType
FROM Veterinarians
WHERE ExperienceYears > 5;



--2 queries with the intersection operation; use INTERSECT and IN;


--finds the common first names between the keepers and veterinarians

Select Keepers.FirstName
From Keepers
Intersect
Select Veterinarians.FirstName
from Veterinarians;


--finds the common AnimalIDs for animals located in habitats with HabitatIDs 2, 4, or 5.

Select FeedingSchedule.AnimalID
From FeedingSchedule
Intersect
Select Animals.AnimalID
From Animals
Where Animals.HabitatID in (2,4,5);


--2 queries with the difference operation; use EXCEPT and NOT IN;


--retrieves the KeeperIDs from the Keepers table, excluding those 
--			Veterinarians whose experience years are less than or equal to 3

Select Keepers.KeeperID
From Keepers
Except
Select Veterinarians.VetID
From Veterinarians
where Veterinarians.ExperienceYears <=3;


--etrieves the AnimalIDs from the FeedingSchedule table, excluding those AnimalIDs 
--		whose corresponding HabitatIDs in the Animals table are not in the range of [1, 2]

Select FeedingSchedule.AnimalID
From FeedingSchedule
except
Select Animals.AnimalID
From Animals
where HabitatID not in (Select HabitatID from Animals where HabitatID not in(1,2))


--4 queries with INNER JOIN, LEFT JOIN, RIGHT JOIN, and FULL JOIN


-- includes the animal's name (AnimalName), diagnosis, and treatment 
--			from the MedicalRecords table. Additionally, it 
--		includes the first name of the veterinarian (VetName) 
--				associated with each medical record.

SELECT Animals.Name AS AnimalName, MedicalRecords.Diagnosis, MedicalRecords.Treatment, Veterinarians.FirstName AS VetName
FROM Animals
INNER JOIN MedicalRecords ON Animals.AnimalID = MedicalRecords.AnimalID
INNER JOIN Veterinarians ON MedicalRecords.VetID = Veterinarians.VetID;



-- includes the first names of keepers (KeeperName), the names of animals (AnimalName), 
--		feeding times (FeedingTime), the first names of veterinarians (VetName), 
--		and information related to medical records, such as diagnosis and treatment.

SELECT Keepers.FirstName AS KeeperName, Animals.Name AS AnimalName, FeedingSchedule.FeedingTime,
       Veterinarians.FirstName AS VetName, MedicalRecords.Diagnosis, MedicalRecords.Treatment
FROM Keepers
FULL JOIN FeedingSchedule ON Keepers.KeeperID = FeedingSchedule.KeeperID
FULL JOIN Animals ON FeedingSchedule.AnimalID = Animals.AnimalID
FULL JOIN MedicalRecords ON Animals.AnimalID = MedicalRecords.AnimalID
FULL JOIN Veterinarians ON MedicalRecords.VetID = Veterinarians.VetID;



--includes the animal's name (AnimalName), diagnosis, and treatment

SELECT Animals.Name AS AnimalName, MedicalRecords.Diagnosis, MedicalRecords.Treatment
FROM Animals
LEFT JOIN MedicalRecords ON Animals.AnimalID = MedicalRecords.AnimalID;


--includes the first names of keepers (KeeperName) and the feeding times (FeedingTime)

SELECT Keepers.FirstName AS KeeperName, FeedingSchedule.FeedingTime
FROM Keepers
RIGHT JOIN FeedingSchedule ON Keepers.KeeperID = FeedingSchedule.KeeperID;




--2 queries with the IN operator and a subquery in the WHERE clause; 
--		in at least one case, the subquery must include a subquery in its own WHERE clause;



--retrieves animals housed in enclosures with above-average capacities

SELECT *
FROM Animals
WHERE HabitatID IN (
    SELECT Enclosures.EnclosureID
    FROM Enclosures
    WHERE Enclosures.Capacity > (
        SELECT AVG(Enclosures.Capacity)
       FROM Enclosures
    )
);



--	retrieves animals housed in enclosures with a certain 
--		type that is classified as being in good condition

SELECT *
FROM Animals
WHERE HabitatID IN (
    SELECT DISTINCT Enclosures.EnclosureID
    FROM Enclosures
    WHERE Enclosures.EType IN (
        SELECT DISTINCT Enclosures.EType
        FROM Enclosures
        WHERE Enclosures.Condition = 'good')
);



-- 2 queries with the EXISTS operator and a subquery in the WHERE clause;


--retrieves all information about animals (Animals A) where there exists 
--			at least one medical record (MedicalRecords M) with a 
--				diagnosis of 'Skin rash' for the same animal

SELECT *
FROM Animals A
WHERE EXISTS (
    SELECT 1
    FROM MedicalRecords M
    WHERE M.AnimalID = A.AnimalID
      AND M.Diagnosis = 'Skin rash'
);


-- find keepers who are assigned to lions

SELECT FirstName, LastName
FROM Keepers K
WHERE EXISTS (
    SELECT 1
    FROM Animals A
    WHERE A.AnimalID = K.KeeperID
      AND A.Species = 'Lion'
);



--2 queries with a subquery in the FROM clause;


--first filters the veterinarians with more than 5 years of experience. 
--  Then, in the outer query, it selects the first name, last name, 
--		and experience years from the result of the subquery 
-- (aliased as V). This effectively provides a list of experienced veterinarians.

SELECT FirstName, LastName, ExperienceYears
FROM (
    SELECT FirstName, LastName, ExperienceYears
    FROM Veterinarians
    WHERE ExperienceYears > 5
) V;


--retrieves the first name (FirstName) and last name (LastName) of female veterinarians (V) 
--			along with the average experience years (AvgExperience).

SELECT V.FirstName, V.LastName, AVG(M.ExperienceYears) as AvgExperience
FROM Veterinarians V, (
    SELECT AVG(ExperienceYears) as ExperienceYears
    FROM Veterinarians
    WHERE Gender = 'Female'
) M
WHERE V.Gender = 'Female'
GROUP BY V.FirstName, V.LastName;



-- 4 queries with the GROUP BY clause, 3 of which also contain the HAVING clause


--			retrieves the species (Species) and 
--	the average age (AvgAge) of animals from the Animals table

SELECT Species, AVG(Age) AS AvgAge
FROM Animals
GROUP BY Species
HAVING AVG(Age) > 5;


--retrieves the enclosure IDs (EnclosureID) and the total count of animals (TotalAnimals) in each enclosure

SELECT E.EnclosureID, COUNT(A.AnimalID) AS TotalAnimals
FROM Enclosures E
JOIN Animals A ON E.EnclosureID = A.HabitatID
GROUP BY E.EnclosureID
HAVING COUNT(A.AnimalID) < (
    SELECT AVG(Capacity)
    FROM Enclosures
);


--retrieves the maximum experience years (MaxExperience) of female veterinarians

SELECT MAX(ExperienceYears) AS MaxExperience
FROM Veterinarians
WHERE Gender = 'Female'
GROUP BY Gender
HAVING MAX(ExperienceYears) > (
    SELECT AVG(ExperienceYears)
    FROM Veterinarians
    WHERE Gender = 'Female'
);


--retrieves the keeper IDs (KeeperID) along with the total sum of feeding portions 
--		(TotalPortions) assigned to each keeper from the FeedingSchedule 

SELECT F.KeeperID, SUM(F.FeedingPortion) AS TotalPortions
FROM FeedingSchedule F
GROUP BY F.KeeperID;




--4 queries using ANY and ALL


--retrieves all information about animals whose age is 
--			greater than at least one lion's age

SELECT *
FROM Animals
WHERE Age > ANY (
    SELECT Age
   FROM Animals
    WHERE Species = 'Lion'
);



--	retrieves all information about animals whose age is 
--	greater than the average age of at least one species

SELECT *
FROM Animals
WHERE Age > ANY (
    SELECT AVG(Age)
    FROM Animals
    GROUP BY Species
);

SELECT *
FROM Animals
WHERE Age IN (
    SELECT Age
    FROM Animals
    GROUP BY Age
    HAVING AVG(Age) >= (
        SELECT AVG(Age)
        FROM Animals
    )
);



--retrieves all information about animals whose age is less than the age of all giraffes

SELECT *
FROM Animals
WHERE Age < ALL (
    SELECT Age
    FROM Animals
    WHERE Species = 'giraffe'
);


--			retrieves all information about animals whose 
--	age is less than or equal to the highest average age across all species

SELECT *
FROM Animals
WHERE Age <= ALL (
    SELECT AVG(Age)
    FROM Animals
    GROUP BY Species
);

SELECT *
FROM Animals
WHERE Age IN (
    SELECT Age
    FROM Animals
    GROUP BY Age
    HAVING AVG(Age) < (
        SELECT AVG(Age)
        FROM Animals
    )
);



-- Select all from tables - used to see the data 
Select * from MedicalRecords;
Select * From Veterinarians;
Select * FROM Animals;
SELECT * FROM Enclosures;
SELECT * FROM Keepers;
SELECT * FROM FeedingSchedule;



