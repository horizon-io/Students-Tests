# Students-Tests
A Test for Students

## Please solve the following questions in your language of choice (C++, JavaScript, VB,...etc).

## It's important to solve it in the best way possible, using the least steps and considering the readabilty.

Copy and Paste your answers in the form below:

https://drive.google.com/open?id=1_nuVHEh6wlQCGcwqHKuvG4077JGQAVkkCvOJSCYIqKM

Or Better use this playgroud (depends on your language): https://www.tutorialspoint.com/codingground.htm, and share the playground (Project > Share) and paste the links in the forms.

## P1\ Find the missing letter

Write a method that takes an array of consecutive (increasing) letters as input and that returns the missing letter in the array.

You will always get an valid array. And it will be always exactly one letter be missing.

The length of the array will always be at least 2.

The array will always contain letters in only one case.


Example:

> ['a','b','c','d','f'] -> 'e'

> ['O','Q','R','S'] -> 'P'

(Use the English alphabet with 26 letters!)


## P2\ Create a Binary -bits- calculator

You should get 2 strings input, contains binary numbers (base 2), you should find the sum of these 2 binary numbers in decimal (base 10).

You always get valid binary numbers.


You may consider that the user will input different number of bits.

You may consider using Power functions -in your language of choice.

Example:
> ("10", "10") -> 4

> ("101", "10") -> 7

> ("1000", "10") -> 10


## P3\ Find the Network and Broadcast addresses for a given IP Address

The input should be an IP address, with a CIDR or Subnet (your choice).

You will always get a valid Host and Subnet (or CIDR) addresses.

You may consider converting Strings to numbers.

you may consider using Bitwise operations (AND, OR, XOR, NOT).

You may consider defining your own types.

Example:

> (IP: 192.168.2.6, CIDR: 25) -> (Network: 192.168.2.0, Broadcast: 192.168.2.127)

> (IP: 192.168.2.6, Subnet: 255.255.255.128) -> (Network: 192.168.2.0, Broadcast: 192.168.2.127)

> (IP: 10.0.0.2, CIDR: 17) -> (Network: 192.168.2.0, Broadcast: 192.168.2.127)

> (IP: 10.0.0.2, Subnet: 255.255.128.0) -> (Network: 10.0.0.0, Broadcast: 10.0.127.255)
