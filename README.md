# libopenstreamdeck

An open-source C++ 20 library to write plugin for the Stream Deck on Windows/Mac.

## Setup

As the library is still in an experimental state, it is not published to any Conan repository.
You need to build the library and it to your local Conan cache to use it in a project. 

### On your computer

1. Clone the repository
```
git clone https://github.com/openstreamdeck/libopenstreamdeck.git
```
2. Install Conan dependencies
```
conan install --build=missing .
```
3. Compile the library and add it to your Conan cache
```
conan create .
```

