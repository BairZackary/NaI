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

Version one has a rough version of the negative, veto, and coincidence triggers.

Version two now has a dedicated cell for the global variables, the ones that are commonly chaanged.  In the final version, all changable variables will be here.  This version was the first one hooked up directly to the detectors and used to take experimental data.  The data was to test the functionality of the triggers.

Version three adds in a rough double veto and double coincidence triggers.  These triggers have not yet been testeed, and most likely will contain errors or bugs.

Version four will be primarily for testing the triggers one by one.
The negative trigger saves all data taken if neither trigger was activated.
If a channel was triggered then no data is saved.
The veto trigger saves all data if channel one was triggered, but channel two was not triggered.  
If channel one was not triggered or if channel two was triggered, no data is saved.
The double veto trigger currently has an error that will enter into an infinite while loop. 
The error takes place it seems during the plotting.  It plots the first three subplots then does nothing else.
The coincidence trigger saves data if channel one was triggered, and then within the coincidence window, channel two was also triggered.
If channel one was not triggered or if channel two was not triggered within the window then no data will be saved.
The double coincidence trigger currently has an error that it will enter into an infinite while loop.
The error takes place it seems during the plotting.  It plots the first three subplots then does nothing else.
This error seems to be the same error that the double veto trigger has, suggesting it is caused by something in common between these two.
