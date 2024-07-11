# README

This project was created for a challenge in [Global Hack Week](https://ghw.mlh.io/challenges).

Given a list of Hackathons in CSV format (provided [here](https://hackp.ac/sort-a-list)), the program will allow the user to sort the list by any of its columns.

## Building

To build this project, you must have the following:
* cmake
* A compatible C/C++ compiler, e.g. [MSVC](https://visualstudio.microsoft.com/vs/features/cplusplus/) on Windows, or the GNU compiler toolchain on Linux.

After all prerequisites are installed, you should create a `build` subdirectory inside the repository, and then use `cmake` to build the project:
```
mkdir build
cd build
cmake ..
cmake --build . --target ghw-sorting-challenge
```

Then, simply run the executable created in the build directory. With MSVC, the executable will be located in `build/debug/ghw-sorting-challenge.exe`.

## Use
The application will initially try to load a csv file from `../hackathons.csv`. This should work if the binary is executed from the `build` subdirectory (e.g. `./debug/ghw-sorting-challenge.exe`), but if the csv cannot be loaded, the application will prompt the user to enter a file path.

After the file is loaded, the application will prompt the user to select one of the columns in the given csv. Then, the rows will be sorted alphanumerically by the selected column. Finally, the sorted rows will be displayed to the user.