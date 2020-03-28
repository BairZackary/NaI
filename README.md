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

Version four was primarily for testing the triggers one by one.
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

Version five will focus on a better data saving algorithm. 
This new algorithm will focus on saving data from all events, not just the largest event.
The data saving is already a function so the modification to the data saving for events should not be to drastic.
Along with the new data saving, the time on the data should be changed.
Added a global variable called TRIGGER_WINDOW that is the timespan spent looking for vetos.
After all triggers have the data saving modified, there should be no use for channelOneMax and channelTwoMax.
The negative trigger does not get modified as it is made to save all data.
The veto trigger now goes through all points and looks for events.
These events are then saved.
There was an error if channel one was triggered at an index less than NUMBER_OF_POINTS_SAVED, the header of the data would be saved multiple times.
This error has been fixed.
The double veto trigger still has the error from version four.
The error appears to be caused not by an infinite while loop, but somewhere in the data saving.
When given a keyboard interupt the error points to the saveData function call.
The longer you let the program run without interupting it, the larger the data file becomes, many times larger than a successfull file.
The error appears to be in the while loop that contains the saveData method call, so it is infact caused by an infinite while loop.
If channel one is triggered again, then the window and the offset are not altered, meaning that the next execution of the loop would be the same as the previous, causing the never ending
Fixing this error will mean removing the else statement and moving what was inside of it to after the if statement.
These changes were made, and there is still an error except this time the keyboard interupt points to the if statement containing the saveData function call.
The error in the double veto trigger has now been fixed.
A similar fix will later be applied to the double coincidence trigger.
Aside from the difference in saving data, version five also changed the run time.
The magic number * 2 in the control loop was replaced with a minute modifier in the globals cell.
