### gen.exe -f <filename> <#shop> <#banks> <#change offices> <#items> <#currencies> <#currency_goals> <#item_goals>

## easy

.\gen.exe -e -f pfile01.pddl 1 1 1 1 1 1 1
Start-Sleep -Milliseconds 6000
.\gen.exe -e -f pfile02.pddl 1 2 1 2 2 2 2
Start-Sleep -Milliseconds 6000
.\gen.exe -e -f pfile03.pddl 2 2 1 2 3 3 2
Start-Sleep -Milliseconds 6000
.\gen.exe -e -f pfile04.pddl 3 2 1 3 2 2 3
Start-Sleep -Milliseconds 6000
.\gen.exe -e -f pfile05.pddl 4 2 1 5 2 2 4
Start-Sleep -Milliseconds 6000

## some challenge

.\gen.exe -e -f pfile06.pddl 4 2 2 5 3 3 4
Start-Sleep -Milliseconds 6000
.\gen.exe -e -f pfile07.pddl 5 2 2 5 4 4 5
Start-Sleep -Milliseconds 6000
.\gen.exe -e -f pfile08.pddl 6 3 3 6 3 3 6
Start-Sleep -Milliseconds 6000
.\gen.exe -e -f pfile09.pddl 5 2 2 6 4 4 6
Start-Sleep -Milliseconds 6000
.\gen.exe -e -f pfile10.pddl 5 3 3 5 5 5 5
Start-Sleep -Milliseconds 6000

### hard

.\gen.exe -f pfile11.pddl 5 3 3 5 3 3 5
Start-Sleep -Milliseconds 6000
.\gen.exe -f pfile12.pddl 5 3 3 7 3 3 7
Start-Sleep -Milliseconds 6000

.\gen.exe -f pfile13.pddl 5 3 3 6 3 3 6
Start-Sleep -Milliseconds 6000
.\gen.exe -f pfile14.pddl 6 3 3 7 2 2 6
Start-Sleep -Milliseconds 6000
.\gen.exe -f pfile15.pddl 7 3 3 7 2 2 7
Start-Sleep -Milliseconds 6000
.\gen.exe -f pfile16.pddl 7 3 3 7 3 3 7  
Start-Sleep -Milliseconds 6000

## extremely hard

.\gen.exe -f pfile17.pddl 7 4 4 8 3 3 8  
Start-Sleep -Milliseconds 6000
.\gen.exe -f pfile18.pddl 8 3 3 8 4 4 8  
Start-Sleep -Milliseconds 6000
.\gen.exe -f pfile19.pddl 9 4 4 8 3 3 8 
Start-Sleep -Milliseconds 6000
.\gen.exe -f pfile20.pddl 9 3 3 9 5 5 9 