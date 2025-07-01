-- Keep a log of any SQL queries you execute as you solve the mystery.

-- To check tables inside the database
.tables

-- Checking Schema of Crime Scene Report
.schema crime_scene_report

-- Checking for report where thief was last scene
SELECT * FROM crime_scene_reports
WHERE year = 2024
and month = 7
and day = 28
and street = 'Humphrey Street';
-- Findings
-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
-- Interviews were conducted today with three witnesses who were present at the time –
-- each of their interview transcripts mentions the bakery.


-- Checking Schema of intervies table
.schema interviews


-- Checking for interviews during day of the crime scene;
SELECT * FROM interviews
where year = 2024
and month = 7
and day = 28;
-- Findings
-- Ruth - Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away.
-- If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.

-- Eugene - I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery,
-- I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money

-- Raymond - As the thief was leaving the bakery, they called someone who talked to them for less than a minute.
-- In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
-- The thief then asked the person on the other end of the phone to purchase the flight ticket.

-- Checking Schema of bakery_security_logs table
.schema bakery_security_logs

-- Checking Bakery Security Logs for day the cs50 duck was stolen
SELECT * FROM bakery_security_logs
WHERE year = 2024
and month = 7
and day = 28
and hour = 10
and minute >= 15
and minute <=25
and activity = 'exit';
-- Findings two cars with licence plate of R3G7486 and 13FNH73 entered the bakery before 1015am on the day of the theft
-- R3G7486 at 10:08am and 13FNH73 at 10:14am

-- The following cars left the bakery within the 10 minute time frame after the theft took place based on enquiries from interviewing with Ruth
-- 5P2BI95,
-- 94KL13X,
-- 6P58WS2,
-- 4328GD8,
-- G412CB,
-- L93JTIZ,
-- 322W7JE,
-- 0NTHK55

-- Checking Schema of atm_transactions
.schema atm_transactions

-- Checking for atm transactions on Leggett Street during the day of the theft
SELECT * from atm_transactions
where year = 2024
and month = 7 and day = 28
and atm_location = 'Leggett Street'
and transaction_type = 'withdraw';
-- Account numbers who withdrew money during day of the crime scene
-- | id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
-- | 246 | 28500762       | 2024 | 7     | 28  | Leggett Street | withdraw         | 48     |
-- | 264 | 28296815       | 2024 | 7     | 28  | Leggett Street | withdraw         | 20     |
-- | 266 | 76054385       | 2024 | 7     | 28  | Leggett Street | withdraw         | 60     |
-- | 267 | 49610011       | 2024 | 7     | 28  | Leggett Street | withdraw         | 50     |
-- | 269 | 16153065       | 2024 | 7     | 28  | Leggett Street | withdraw         | 80     |
-- | 288 | 25506511       | 2024 | 7     | 28  | Leggett Street | withdraw         | 20     |
-- | 313 | 81061156       | 2024 | 7     | 28  | Leggett Street | withdraw         | 30     |
-- | 336 | 26013199       | 2024 | 7     | 28  | Leggett Street | withdraw         | 35     |


-- Checking Schema of phone_calls table
.schema phone_calls

-- Checking phone calls that lasted less than a minute during day of the crime
SELECT * FROM phone_calls where year = 2024 and month = 7 and day = 28 and duration <=60;
-- Findings - Phone calls made during day of crime and lasted less than a minute
-- | id  |     caller     |    receiver    | year | month | day | duration |
-- +-----+----------------+----------------+------+-------+-----+----------+
-- | 221 | (130) 555-0289 | (996) 555-8899 | 2024 | 7     | 28  | 51       |
-- | 224 | (499) 555-9472 | (892) 555-8872 | 2024 | 7     | 28  | 36       |
-- | 233 | (367) 555-5533 | (375) 555-8161 | 2024 | 7     | 28  | 45       |
-- | 234 | (609) 555-5876 | (389) 555-5198 | 2024 | 7     | 28  | 60       |
-- | 251 | (499) 555-9472 | (717) 555-1342 | 2024 | 7     | 28  | 50       |
-- | 254 | (286) 555-6063 | (676) 555-6554 | 2024 | 7     | 28  | 43       |
-- | 255 | (770) 555-1861 | (725) 555-3243 | 2024 | 7     | 28  | 49       |
-- | 261 | (031) 555-6622 | (910) 555-3251 | 2024 | 7     | 28  | 38       |
-- | 279 | (826) 555-1652 | (066) 555-9701 | 2024 | 7     | 28  | 55       |
-- | 281 | (338) 555-6650 | (704) 555-2131 | 2024 | 7     | 28  | 54       |




-- Checking Schema of Flights table
.schema flights

-- Checking Flights going out a day after the crime took place and finding the earliest flight leaving
SELECT * FROM flights where year = 2024 and month = 7 and day = 29 ORDER BY HOUR ASC LIMIT 1;
-- Findings Flights leaving day after the crime
-- +----+-------------------+------------------------+------+-------+-----+------+--------+
-- | id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
-- +----+-------------------+------------------------+------+-------+-----+------+--------+
-- | 36 | 8                 | 4                      | 2024 | 7     | 29  | 8    | 20     |
-- +----+-------------------+------------------------+------+-------+-----+------+--------+


-- Checking number of suspects who have matching phone_numbers, account number and licence plate:
SELECT * FROM people p join bank_accounts b on p.id = b.person_id
WHERE p.phone_number IN ('(130) 555-0289','(499) 555-9472', '(367) 555-5533', '(609) 555-5876', '(499) 555-9472', '(286) 555-6063', '(770) 555-1861', '(031) 555-6622', '(826) 555-1652', '(338) 555-6650')
AND p.license_plate IN ('5P2BI95','94KL13X','6P58WS2','4328GD8','G412CB','L93JTIZ','322W7JE','0NTHK55')
AND b.account_number IN('28500762','28296815','76054385','49610011','16153065','25506511','81061156', '26013199');
-- findings
-- Only Two Matches were found with the matching phone numbers, account number and lucence plates during day of the crime
-- |   id   | name  |  phone_number  | passport_number | license_plate | account_number | person_id | creation_year |
-- +--------+-------+----------------+-----------------+---------------+----------------+-----------+---------------+
-- | 686048 | Bruce | (367) 555-5533 | 5773159633      | 94KL13X       | 49610011       | 686048    | 2010          |
-- | 514354 | Diana | (770) 555-1861 | 3592750733      | 322W7JE       | 26013199       | 514354    | 2012          |
-- +--------+-------+----------------+-----------------+---------------+----------------+-----------+---------------+

-- Trying to identify accomplice based on suspect phone number
SELECT * FROM people WHERE phone_number IN ('(375) 555-8161', '(725) 555-3243')
-- Findings
-- +--------+--------+----------------+-----------------+---------------+
-- |   id   |  name  |  phone_number  | passport_number | license_plate |
-- +--------+--------+----------------+-----------------+---------------+
-- | 847116 | Philip | (725) 555-3243 | 3391710505      | GW362R6       |
-- | 864400 | Robin  | (375) 555-8161 | NULL            | 4V16VO0       |
-- +--------+--------+----------------+-----------------+---------------+


-- Checking airport and passengers table a day after crime took place and checking for passegers who boarded with the suspsected name and passport number and macthing flight id
SELECT * FROM passengers p JOIN flights f on p.flight_id = f.id
WHERE f.year = 2024 and f.month = 7 and f.day = 29 and p.passport_number IN ('5773159633','3592750733') and flight_id = 36;


-- Findings
-- +-----------+-----------------+------+----+-------------------+------------------------+------+-------+-----+------+--------+
-- | flight_id | passport_number | seat | id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
-- +-----------+-----------------+------+----+-------------------+------------------------+------+-------+-----+------+--------+
-- | 36        | 5773159633      | 4A   | 36 | 8                 | 4                      | 2024 | 7     | 29  | 8    | 20     |
-- +-----------+-----------------+------+----+-------------------+------------------------+------+-------+-----+------+--------+
-- From this we now know the thief was Bruce based on the passport number


-- Checking Schema of airports table
.schema airports

-- finding the city bruce escaped to
SELECT * FROM airports where id = 4;
-- +----+--------------+-----------------------------+---------------+
-- | id | abbreviation |          full_name          |     city      |
-- +----+--------------+-----------------------------+---------------+
-- | 4  | LGA          | LaGuardia Airport           | New York City |


-- Finding Receiver Phone Number Of Bruce during day of theft
SELECT * FROM phone_calls where year = 2024 and month = 7 and day = 28 and duration <=60 and caller = '(367) 555-5533';

-- Findings - Receiver Phone Number is '(375) 555-8161'

-- Finding who is receiver/accomplice of thief
SELECT * FROM people where phone_number = '(375) 555-8161';

-- Findings The accomplice is Robin
-- +--------+-------+----------------+-----------------+---------------+
-- |   id   | name  |  phone_number  | passport_number | license_plate |
-- +--------+-------+----------------+-----------------+---------------+
-- | 864400 | Robin | (375) 555-8161 | NULL            | 4V16VO0       |
-- +--------+-------+----------------+-----------------+---------------+





-- Compounded Findings:
-- Findings two cars with licence plate of R3G7486 and 13FNH73 entered the bakery before 1015am on the day of the theft
-- R3G7486 at 10:08am and 13FNH73 at 10:14am

-- The following cars left the bakery within the 10 minute time frame after the theft took place based on enquiries from interviewing with Ruth
-- 5P2BI95,
-- 94KL13X,
-- 6P58WS2,
-- 4328GD8,
-- G412CB,
-- L93JTIZ,
-- 322W7JE,
-- 0NTHK55

-- Account numbers who withdrew money during day of the crime scene
-- | id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
-- | 246 | 28500762       | 2024 | 7     | 28  | Leggett Street | withdraw         | 48     |
-- | 264 | 28296815       | 2024 | 7     | 28  | Leggett Street | withdraw         | 20     |
-- | 266 | 76054385       | 2024 | 7     | 28  | Leggett Street | withdraw         | 60     |
-- | 267 | 49610011       | 2024 | 7     | 28  | Leggett Street | withdraw         | 50     |
-- | 269 | 16153065       | 2024 | 7     | 28  | Leggett Street | withdraw         | 80     |
-- | 288 | 25506511       | 2024 | 7     | 28  | Leggett Street | withdraw         | 20     |
-- | 313 | 81061156       | 2024 | 7     | 28  | Leggett Street | withdraw         | 30     |
-- | 336 | 26013199       | 2024 | 7     | 28  | Leggett Street | withdraw         | 35     |


-- Findings - Phone calls made during day of crime and lasted less than a minute
-- | id  |     caller     |    receiver    | year | month | day | duration |
-- +-----+----------------+----------------+------+-------+-----+----------+
-- | 221 | (130) 555-0289 | (996) 555-8899 | 2024 | 7     | 28  | 51       |
-- | 224 | (499) 555-9472 | (892) 555-8872 | 2024 | 7     | 28  | 36       |
-- | 233 | (367) 555-5533 | (375) 555-8161 | 2024 | 7     | 28  | 45       |
-- | 234 | (609) 555-5876 | (389) 555-5198 | 2024 | 7     | 28  | 60       |
-- | 251 | (499) 555-9472 | (717) 555-1342 | 2024 | 7     | 28  | 50       |
-- | 254 | (286) 555-6063 | (676) 555-6554 | 2024 | 7     | 28  | 43       |
-- | 255 | (770) 555-1861 | (725) 555-3243 | 2024 | 7     | 28  | 49       |
-- | 261 | (031) 555-6622 | (910) 555-3251 | 2024 | 7     | 28  | 38       |
-- | 279 | (826) 555-1652 | (066) 555-9701 | 2024 | 7     | 28  | 55       |
-- | 281 | (338) 555-6650 | (704) 555-2131 | 2024 | 7     | 28  | 54       |

-- Findings Flights leaving day after the crime
-- | id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
-- +----+-------------------+------------------------+------+-------+-----+------+--------+
-- | 18 | 8                 | 6                      | 2024 | 7     | 29  | 16   | 0      |
-- | 23 | 8                 | 11                     | 2024 | 7     | 29  | 12   | 15     |
-- | 36 | 8                 | 4                      | 2024 | 7     | 29  | 8    | 20     |
-- | 43 | 8                 | 1                      | 2024 | 7     | 29  | 9    | 30     |
-- | 53 | 8                 | 9                      | 2024 | 7     | 29  | 15   | 20     |


-- findings
-- Only Two Matches were found with the matching phone numbers, account number and lucence plates during day of the crime
-- |   id   | name  |  phone_number  | passport_number | license_plate | account_number | person_id | creation_year |
-- +--------+-------+----------------+-----------------+---------------+----------------+-----------+---------------+
-- | 686048 | Bruce | (367) 555-5533 | 5773159633      | 94KL13X       | 49610011       | 686048    | 2010          |
-- | 514354 | Diana | (770) 555-1861 | 3592750733      | 322W7JE       | 26013199       | 514354    | 2012          |
-- +--------+-------+----------------+-----------------+---------------+----------------+-----------+---------------+

-- SUSPECTS LIST:
-- - BRUCE
-- - DIANA
