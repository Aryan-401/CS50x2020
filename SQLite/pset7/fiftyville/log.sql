-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT * FROM crime_scene_reports
WHERE month= 7 AND day = 28 AND street= "Chamberlin Street";  --Get the ID of the Crime.tables (theft took place at 10:15 AM)

SELECT * FROM interviews
WHERE month = 7 AND day = 28; -- Get Transscripts of Witnesses (10 min after theft, the theif drove off FROM the courthouse parking lot) (Theif was withdrawing money on Fifer Street) (Leaving Town on the 27th Of July. Other Guy Purchased Ticket)

SELECT name FROM people
JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.license_plate
WHERE day = 28 AND month = 7 AND hour = 10 AND minute >= 15 AND minute < 25 AND activity = "exit"; --Get people who left the courthouse 10 min after the time of theft

SELECT DISTINCT name
FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE day = 28 AND month = 7 AND year = 2020 AND transaction_type = "withdraw" AND atm_location = "Fifer Street" --Get People who withdrew money on Fifer Street

SELECT name
FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
WHERE flight_id = (SELECT id FROM flights WHERE day = 29 AND month = 7 ORDER BY hour, minute LIMIT 1); -- Get People who boarded the first flight on the 29th

SELECT name
FROM people
JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE day = 28 AND month = 7 AND year = 2020 AND duration < 60;  --Get all calls less than a minute

SELECT name FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
WHERE flight_id = (SELECT id FROM flights WHERE day = 29 AND month = 7 AND year = 2020 ORDER BY hour, minute LIMIT 1)
INTERSECT
SELECT DISTINCT name FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE day = 28 AND month = 7 AND year = 2020 AND transaction_type = "withdraw" AND atm_location = "Fifer Street"
INTERSECT
SELECT nameFROM people
JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE day = 28 AND month = 7 AND year = 2020 AND duration < 60
INTERSECT
SELECT name FROM people
JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.license_plate
WHERE day = 28 AND month = 7 AND year = 2020 AND hour = 10 AND minute >= 15 AND minute < 25 AND activity = "exit"; --Get intersection of all queries to find perp (Ernest)

SELECT city FROM airports
WHERE id = (SELECT destination_airport_id FROM flights WHERE day = 29 AND month = 7 AND year = 2020 ORDER BY hour,minute LIMIT 1);  --Get Destination Flight (London)

SELECT name
FROM people
JOIN phone_calls ON people.phone_number = phone_calls.receiver
WHERE day = 28 AND month = 7 AND year = 2020 AND duration < 60 AND caller = (SELECT phone_number FROM people WHERE name = "Ernest");