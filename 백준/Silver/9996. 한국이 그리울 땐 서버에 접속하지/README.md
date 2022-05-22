# [Silver III] 한국이 그리울 땐 서버에 접속하지 - 9996 

[문제 링크](https://www.acmicpc.net/problem/9996) 

### 성능 요약

메모리: 2028 KB, 시간: 4 ms

### 분류

브루트포스 알고리즘(bruteforcing), 정규 표현식(regex), 문자열(string)

### 문제 설명

<p>In his spare time, Vjeko likes to browse through files in directories. Unfortunately, it seems to him that the console on his computer broke down and now it doesn't correctly print file names that match a certain pattern. </p>

<p>A pattern is string consisting of lowercase letters of the English alphabet and exactly one asterisk. </p>

<p>A file name matches a pattern if the pattern string can be made equal to the file name by replacing the asterisk with an arbitrary string of lowercase letters of the English alphabet (an empty string substitution is also possible). For example, strings “abcd”, “ad” and “anestonestod” all match the pattern “a*d” and the string “bcd” does not. </p>

<p>Write a programme that will, given a pattern and file names, output whether a file name matches the pattern or not. </p>

### 입력 

 <p>The first line of input contains the integer N (1 ≤ N ≤ 100), the number of files. </p>

<p>The second line of input contains a string of characters consisting of only lowercase letter of the English alphabet and exactly one asterisk (ASCII value 42). The length of the string will not exceed 100 and the asterisk will not be located at the beginning nor at the end of the string. </p>

<p>Each of the following N lines contains file names, each in its own line. The file names consist of only lowercase letters of the English alphabet and their length will not exceed 100. </p>

### 출력 

 <p>Output N lines. The i<sup>th</sup> line should be “DA” (Croatian for yes) if the i<sup>th</sup> file name matches the pattern or “NE” (Croatian for no) if the i<sup>th</sup> file name does not match the pattern. </p>

