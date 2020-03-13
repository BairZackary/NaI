# NaI
Professor To's dark matter research sodium iodide project.


The hantek master api folder holds the needed files for the scope as well as the basic program that comes with the scope.
This folder does not need to be changed.

The hantek software folder holds the scope's driver.
This folder does not need ot be changed.

The other resources folder has a copy of the original software for the scope as well as some references I used for research on the project, and the original flowchart for the program.

The python files folder holds all of the important files for this project.  This folder contains:


The data folder which is where all collected data goes.  The naming scheme is year, month, date, time.  These files are csv files.

The figures folder holds the important saved figures generated from when the program runs.

The noteworthy data folder holds important data that was copied from the data folder.  It is meant to isolate important data files.

The previous students work folder contains files that were worked on previous to the fall 2019 semester.

The zackary bair radioactive tests folder contains the module that the scope uses as well as all of the files that the new program needs.


Versions for the software:

Vrsion one has a rough version of the negative, veto, and coincidence triggers.

Version two now has a dedicated cell for the global variables, the ones that are commonly chaanged.  In the final version, all changable variables will be here.  This version was the first one hooked up directly to the detectors and used to take experimental data.  The data was to test the functionality of the triggers.

Version three adds in a rough double veto and double coincidence triggers.  These triggers have not yet been testeed, and most likely will contain errors or bugs.

Version four will be primarily for testing the triggers one by one.  In this version the data saving will be altered to save specific events rather than just mass amounts of data surrounding an event.
