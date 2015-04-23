# hash-table

The premise of this project is to create a hash table of size 1000 to store integers, using linear probing as collision resolution with step size of 1.

The program takes a text file as an input. The text file will give instructions to the program, which will tell it what action to take next.

If the line begins with an 'i', it should insert that number into the hash table if it is not present and then output either "inserted" or "duplicate".

If the line beings with an 's', it should search the hash table for that number and then output either "present" or "absent".

Example:

file1.txt contains:

i 10

i 12

s 10

c 5

i 10

s 5

./fourth file1.txt

inserted

inserted

present

error

duplicate

absent
