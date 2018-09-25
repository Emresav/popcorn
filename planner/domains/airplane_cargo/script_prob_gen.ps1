####  gen.exe -f <filename> <#tankers> <#planes> <#airports> <#refineries> <#cargo> <#cargo_goals>

## easy numeric goals

.\gen.exe -e -f pfile01.pddl 1 2 2 2 2 2
Start-Sleep -Milliseconds 6000
.\gen.exe -e -f pfile02.pddl 1 2 2 2 2 2 
Start-Sleep -Milliseconds 6000
.\gen.exe -e -f pfile03.pddl 1 2 3 2 3 3 
Start-Sleep -Milliseconds 6000
.\gen.exe -e -f pfile04.pddl 1 1 3 3 3 3
Start-Sleep -Milliseconds 6000
.\gen.exe -e -f pfile05.pddl 1 1 3 3 4 4
Start-Sleep -Milliseconds 6000
.\gen.exe -e -f pfile06.pddl 1 2 3 3 5 5 
Start-Sleep -Milliseconds 6000
.\gen.exe -e -f pfile07.pddl 1 2 3 3 6 6 
Start-Sleep -Milliseconds 6000
.\gen.exe -e -f pfile08.pddl 2 2 3 3 7 7
Start-Sleep -Milliseconds 6000

## hard numeric goals

.\gen.exe -f pfile09.pddl 2 2 4 4 4 4
Start-Sleep -Milliseconds 6000
.\gen.exe -f pfile10.pddl 2 2 4 5 4 4
Start-Sleep -Milliseconds 6000
.\gen.exe -f pfile11.pddl 2 2 4 5 5 5 
Start-Sleep -Milliseconds 6000
.\gen.exe -f pfile12.pddl 2 2 4 6 5 5
Start-Sleep -Milliseconds 6000
.\gen.exe -f pfile13.pddl 2 3 4 7 6 6 
Start-Sleep -Milliseconds 6000
.\gen.exe -f pfile14.pddl 3 2 4 7 6 6
Start-Sleep -Milliseconds 6000
.\gen.exe -f pfile15.pddl 3 2 5 7 7 7
Start-Sleep -Milliseconds 6000
.\gen.exe -f pfile16.pddl 3 2 5 8 7 7  
Start-Sleep -Milliseconds 6000
.\gen.exe -f pfile17.pddl 2 3 5 9 8 8
Start-Sleep -Milliseconds 6000
.\gen.exe -f pfile18.pddl 2 3 6 8 8 8
Start-Sleep -Milliseconds 6000
.\gen.exe -f pfile19.pddl 2 3 6 9 9 9
Start-Sleep -Milliseconds 6000
.\gen.exe -f pfile20.pddl 3 3 6 9 9 9