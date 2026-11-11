-- 1. تقرير الجريمة
SELECT description FROM crime_scene_reports WHERE year = 2025 AND month = 7 AND day = 28 AND street = 'Humphrey Street';

-- 2. أقوال الشهود
SELECT name, transcript FROM interviews WHERE year = 2025 AND month = 7 AND day = 28;

-- 3. المشتبه بهم (سحب + عربيات + مكالمات + طيران)
SELECT DISTINCT people.name FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE atm_transactions.year = 2025
AND atm_transactions.month = 7
AND atm_transactions.day = 28
AND atm_transactions.transaction_type = 'withdraw'
AND bakery_security_logs.year = 2025
AND bakery_security_logs.month = 7
AND bakery_security_logs.day = 28
AND bakery_security_logs.hour = 10
AND bakery_security_logs.minute >= 15
AND bakery_security_logs.minute <= 25
AND bakery_security_logs.activity = 'exit'
AND phone_calls.year = 2025
AND phone_calls.month = 7
AND phone_calls.day = 28
AND phone_calls.duration < 60;-- Keep a log of any SQL queries you execute as you solve the mystery.
