## gen.exe -f <filename> <#workshop> <#supplier> <#customer> <#itemGoals> <goalDifficulty>
## -n to set initial stock levels to 0.
## if goalDifficulty = 1, then goal is <= 10
## if goalDifficulty = 2, then goal is <= 50

## initial stock = zero, goal <= 50:

.\gen.exe -n -f pfile01.pddl 3 3 3 1 1
Start-Sleep -Milliseconds 6000
.\gen.exe -n -f pfile02.pddl 4 4 4 1 1
Start-Sleep -Milliseconds 6000
.\gen.exe -n -f pfile03.pddl 5 5 5 1 1
Start-Sleep -Milliseconds 6000
.\gen.exe -n -f pfile04.pddl 5 6 6 2 1
Start-Sleep -Milliseconds 6000
.\gen.exe -n -f pfile05.pddl 5 7 7 2 1
Start-Sleep -Milliseconds 6000
.\gen.exe -n -f pfile06.pddl 6 8 8 2 1
Start-Sleep -Milliseconds 6000
.\gen.exe -n -f pfile07.pddl 6 9 9 3 1
Start-Sleep -Milliseconds 6000

## initial stock = zero, goal <= 50:

.\gen.exe -n -f pfile08.pddl 4 4 4 2 2
Start-Sleep -Milliseconds 6000
.\gen.exe -n -f pfile09.pddl 5 5 4 2 2
Start-Sleep -Milliseconds 6000
.\gen.exe -n -f pfile10.pddl 5 5 5 3 2
Start-Sleep -Milliseconds 6000
.\gen.exe -n -f pfile11.pddl 6 6 5 3 2
Start-Sleep -Milliseconds 6000
.\gen.exe -n -f pfile12.pddl 6 5 6 3 2
Start-Sleep -Milliseconds 6000

### initial stock levels are not zero, goal <= 50:

.\gen.exe -f pfile13.pddl 3 3 4 2 2
Start-Sleep -Milliseconds 6000
.\gen.exe -f pfile14.pddl 3 4 5 2 2
Start-Sleep -Milliseconds 6000
.\gen.exe -f pfile15.pddl 4 4 6 2 2
Start-Sleep -Milliseconds 6000
.\gen.exe -f pfile16.pddl 4 5 4 2 2  
Start-Sleep -Milliseconds 6000
.\gen.exe -f pfile17.pddl 5 5 7 3 2
Start-Sleep -Milliseconds 6000
.\gen.exe -f pfile18.pddl 5 5 5 3 2
Start-Sleep -Milliseconds 6000
.\gen.exe -f pfile19.pddl 6 7 5 4 2 
Start-Sleep -Milliseconds 6000
.\gen.exe -f pfile20.pddl 7 6 6 4 2