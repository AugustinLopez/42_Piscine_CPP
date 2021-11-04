printf "Test 1: Lorem Ipsum -> Ipsum Lorem\n"
./replace test.txt "Lorem Ipsum" "Ipsum Lorem"
diff test.txt test.txt.REPLACE
printf "\n\nTest 2: A -> E\n"
./replace test.txt "A" "E"
diff test.txt test.txt.REPLACE
printf "\n\nTest 3: AA -> EE\n"
./replace test.txt "AA" "EE"
diff test.txt test.txt.REPLACE
printf "\n\nTest 4: AA -> EE\n"
./replace test.txt "AAAA" "EEEE"
diff test.txt test.txt.REPLACE
printf "\n\nTest 5: BB -> B\n"
./replace test.txt "BB" "B"
diff test.txt test.txt.REPLACE
printf "\n\nTest 6: BBB -> B\n"
./replace test.txt "BBB" "B"
diff test.txt test.txt.REPLACE
printf "\n\nTest 7: \\n'"
./replace test.txt "
" "\n"
diff test.txt test.txt.REPLACE
printf "\n\nTest 8: whole file\n"
./replace test.txt "`cat test.txt`" "Hello"
diff test.txt test.txt.REPLACE