
## <seed> <#rovers> <#waypoints> <#objectives> <#cameras> <#goals>
## roversgenerator_cp.exe -t -n -f file.pddl 1 4 2 1 2

## easy

.\roversgenerator_cp.exe -t -n -f pfile01.pddl 1 3 2 1 1
Start-Sleep -Milliseconds 6000
.\roversgenerator_cp.exe -t -n -f pfile02.pddl 1 3 2 2 1
Start-Sleep -Milliseconds 6000
.\roversgenerator_cp.exe -t -n -f pfile03.pddl 1 3 2 2 1
Start-Sleep -Milliseconds 6000
.\roversgenerator_cp.exe -t -n -f pfile04.pddl 1 3 2 2 2
Start-Sleep -Milliseconds 6000
.\roversgenerator_cp.exe -t -n -f pfile05.pddl 1 3 2 3 2
Start-Sleep -Milliseconds 6000
.\roversgenerator_cp.exe -t -n -f pfile06.pddl 1 4 2 3 2
Start-Sleep -Milliseconds 6000
.\roversgenerator_cp.exe -t -n -f pfile07.pddl 1 4 2 3 2
Start-Sleep -Milliseconds 6000

## some challenge

.\roversgenerator_cp.exe -t -n -f pfile08.pddl 2 4 2 3 2
Start-Sleep -Milliseconds 6000
.\roversgenerator_cp.exe -t -n -f pfile09.pddl 2 4 2 3 3
Start-Sleep -Milliseconds 6000
.\roversgenerator_cp.exe -t -n -f pfile10.pddl 2 4 3 4 3
Start-Sleep -Milliseconds 6000
.\roversgenerator_cp.exe -t -n -f pfile11.pddl 2 4 3 4 3
Start-Sleep -Milliseconds 6000
.\roversgenerator_cp.exe -t -n -f pfile12.pddl 2 5 4 4 3
Start-Sleep -Milliseconds 6000

### hard

.\roversgenerator_cp.exe -t -n -f pfile13.pddl 2 5 4 4 4
Start-Sleep -Milliseconds 6000
.\roversgenerator_cp.exe -t -n -f pfile14.pddl 2 5 4 5 4
Start-Sleep -Milliseconds 6000
.\roversgenerator_cp.exe -t -n -f pfile15.pddl 3 5 4 6 4
Start-Sleep -Milliseconds 6000
.\roversgenerator_cp.exe -t -n -f pfile16.pddl 3 4 5 6 4  
Start-Sleep -Milliseconds 6000

## extremely hard

.\roversgenerator_cp.exe -t -n -f pfile17.pddl 3 5 5 6 5
Start-Sleep -Milliseconds 6000
.\roversgenerator_cp.exe -t -n -f pfile18.pddl 3 5 6 6 5
Start-Sleep -Milliseconds 6000
.\roversgenerator_cp.exe -t -n -f pfile19.pddl 4 6 6 6 6  
Start-Sleep -Milliseconds 6000
.\roversgenerator_cp.exe -t -n -f pfile20.pddl 4 6 7 7 6