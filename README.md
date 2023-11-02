# Forwarding Algorithm <img src="https://cdn.freebiesupply.com/logos/thumbs/2x/uncw-logo.png" width="300" height="300" align="right" >

## Overview

An assignment for CSC-344: Computer Networks that involved implementing an algorithm to determine what port to forward
an IPv4 to based on a routing table. The algorithm was implemented in C++ and the routing table is read from a CSV file.

## Dependencies

- C++ 23 (Tested with MSVC Version 19.37.32824)
- CMake (Minimum Version Required: 3.26)
- vcpkg

## Building

1. Clone the repository and extract it to a directory.
2. Open a terminal and navigate to the directory.
3. First, run the following
   command: `cmake -B Build/ -S . -DCMAKE_TOOLCHAIN_FILE="path to vcpkg/scripts/buildsystems/vcpkg.cmake"`
4. Then, run the following command: `cmake --build Build/ --config Config`, where Config is either Debug or Release.
5. The executable will be located within the Build/Console/Config/ directory, where Config is either Debug or Release.
6. Copy the files in the Console/Resources/ directory to the directory where the executable is located.
7. Run the executable.

## Running Tests

1. Clone the repository and extract it to a directory.
2. Open a terminal and navigate to the directory.
3. First, run the following
   command: `cmake -B Build/ -S . -DCMAKE_TOOLCHAIN_FILE="path to vcpkg/scripts/buildsystems/vcpkg.cmake"`
4. Then, run the following command: `cmake --build Build/ --config Config`, where Config is either Debug or Release.
5. The executable will be located within the Build/Tests/Config/ directory, where Config is either Debug or Release.
6. Run the executable using the terminal.

## Usage

### Commands:

- `help` - Displays a list of commands.
- `exit` - Exits the program and allows the user to optionally save the forwarding ports to a text file.
- `load` - Loads a routing table from a CSV file.
- `port` - Displays the port that a given IPv4 address will be forwarded to.
- `ports` - Displays the ports that each IPv4 address will be forwarded to in a collection loaded from a text file.

### Examples:

#### Loading a Routing Table

```
> load
Enter the path to the routing table: Resources/RoutingTable.csv
```

#### Displaying the Port for an IPv4 Address

```
> port
Enter the IPv4 address: 192.168.1.1
```

#### Displaying the Ports for a Collection of IPv4 Addresses

```
> ports
Enter the path to the collection: Resources/IPv4Addresses.txt
```