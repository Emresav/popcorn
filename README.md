# popcorn

POPCORN is a temporal-numeric planning software that I have developed during my PhD studies at King's College London under supervision of Prof Maria Fox and Prof Derek Long. POPCORN can reason about action-specific numeric parameters that can take their values from relatively large domains. The planner has a freedom of choosing their values during planning process. Practically speaking, this means that you can now model actions that can have multiple flexible numeric parameters, such as the withdrawal amount from the cashpoint (e.g. `10<= ?cash <= 100`), or the refuel amount, as in PDDL community these parameters can only be defined with fixed values. The language we use when developing our domains, the extended version of PDDL, is quite straightforward; so I highly recommend users to inspect them to decide whether this is something that you want in your planning scenarios. This work was published on ECAI 2016 under the title of [Planning Using Actions with Control Parameters](https://kclpure.kcl.ac.uk/portal/files/56331945/FAIA285_1185.pdf). 

Also note that this code base includes a MILP Compilation of optimal numeric planning problems with control parameters. I collaborated with *Chiara Piacentini* on this work. 

# Dependencies
POPCORN makes use of various other tools that are available online, these are:

For parsing the PDDL domain: Flex, Bison 
Optimisation tools: CLP, CoinUtils, CBC, CBLAS, CGL, CPLEX

```
apt-get update
apt-get -y install g++ make flex bison cmake doxygen coinor-clp coinor-libcbc-dev coinor-libclp-dev coinor-libcoinutils-dev coinor-libosi-dev coinor-libcgl-dev libbz2-dev libgsl-dev libz-dev
```
**NOTE**: You will need to install CPLEX from their website!

# Running POPCORN

1. Clone this repository to your local machine: 

```
https://github.com/Emresav/popcorn.git
```

2. Export the directories of CPLEX libraries:

```
export CPLEX="/my/location/to/libcplex.a"
export ILOCPLEX="/my/location/to/libilocplex.a"
export CONCERT="/my/location/to/libconcert.a"
export CPLEX_INCLUDES="/my/location/to/cplex/include"
export CONCERT_INCLUDES="/my/location/to/concert/include"
```

3. Compiling the source code:

```
cd /planner/planner
ls -la
cmake .
make clean
make popf3-clp
```

4. Features of POPCORN
In order to see the available features of POPCORN, simply run the executable: `/planner/planner/popf/popf3-clp`

5. Running POPCORN:
```
/planner/planner/popf/popf3-clp $DOMAINFILE $PROBLEMFILE > $PLANFILE
```

That's it! I have included various domains and problem instances that are used during my experiments. Almost all of them are new and quite rich in terms of temporal and numeric features. Have fun, and please do not hesitate to contact me if you have any issues during compiling and running the planner.  
